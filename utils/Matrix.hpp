/*
 * \file Matrix.hpp
 * \brief Matrix implementation for library
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "MatrixError.hpp"
#include <vector>

/*
 * Matrix class Header File
 */
template <typename T>
class Matrix {
    private:

        // representation of 2D matrix
        std::vector<T> v;
        // number of rows
        unsigned int r;
        // number of columns
        unsigned int c;

    protected:

        virtual void clear() {
            v.clear();
            r = 0;
            c = 0;
        }

    public:

        Matrix() {
            clear();
        }

        Matrix(unsigned int row, unsigned int col, T* data = 0, unsigned int dataLength = 0);
        Matrix(unsigned int row, unsigned int col, const std::vector<T>& data);

        virtual ~Matrix() {
            clear();
        }

        // Operators
        Matrix& operator=(const Matrix&);
        std::vector<T> operator[](unsigned int) const;
        Matrix operator*(const Matrix&);

        Matrix transpose();

        // Inline function to save time
        inline unsigned int rowNum() const {
            return r;
        }

        inline unsigned int colNum() const {
            return c;
        }

        inline unsigned int size() const {
            return v.size();
        }

        inline void add(const T& t) {
            v.push_back(t);
        }
};

template <typename T>
Matrix<T>::Matrix(unsigned int row, unsigned int col, T* data, unsigned int dataLength) {
    clear();

    if (row > 0 && col > 0) {
        r = row;
        c = col;
        unsigned int matSize = r * c;

        if (dataLength && data) {
            for (unsigned int i = 0; i < dataLength && i < matSize; i++) {
                v.push_back(data[i]);
            }
        }
    }
}

template <typename T>
Matrix<T>::Matrix(unsigned int row, unsigned int col, const std::vector<T>& data) {
    clear();

    if (row > 0 && col > 0) {
        r = row;
        c = col;

        unsigned int matSize = row * col;

        if (data.size() > 0) {
            for (unsigned int i = 0; i < matSize && i < data.size(); i++) {
                v.push_back(data[i]);
            }
        }
    }
}


/**
 * Overload of equals (=) operator to work with Matrix object. Used to assign
 * value of a matrix object to another.
 * @tparam T template type e.g., int, float, double
 * @param original - Matrix object we are copying
 * @return return object
 */
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& original) {
    clear();

    if (original.r > 0 && original.c > 0) {
        r = original.r;
        c = original.c;

        unsigned int matSize = r * c;

        for (unsigned int i = 0; i < matSize && i < original.size(); i++) {
            v.push_back(original.v[i]);
        }
    }

    return *this;
}


/**
 * Overload of multiplication (*) operator to work with Matrix object, Used to
 * multiply two Matrix objects
 * @tparam T template type e.g, int, float, double
 * @param mat2 - Second Matrix object in the multiplication
 * @return new Matrix<T> object representing the product of two Matrix objects
 */
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& mat2) {
    Matrix product(r, mat2.c);

    if (c != mat2.r) {
        // Need to throw an exception for index out of range
        throw MatrixError(1, ERROR_1);
    } else if (r < 1 || c < 1 || mat2.c < 1) {
        // Need to throw an exception for an invalid dimension of the Matrix object
        throw MatrixError(3, ERROR_3);
    } else if ((r * c > size()) || (mat2.r * mat2.c > mat2.size())) {
        // Need to throw an exception for an invalid amount of data
        throw MatrixError(4, ERROR_4);
    } else {
        // need to multiply elements and place in new Matrix
        for (unsigned int i = 0; i < r; i++) {
            for (unsigned int j = 0; j < mat2.c; j++) {
                // TODO: need to get product of row and col multiplication
                T currVal = v[i * c] * mat2.v[j];

                // Need to iterate through the correct location due to
                // single vector implementation
                for (unsigned int k = 1; k < c; k++){
                    currVal += v[i * c + k] * mat2.v[k * mat2.c + j];
                }

                product.v.push_back(currVal);
            }
        }
    }
    return product;
}


/**
 * Overload of vector access [] operator to work with Matrix object
 * @tparam T template type
 * @param rowIndex row index we are accessing in the matrix
 * @return the row contents at a given index of the 2D matrix
 */
template <typename T>
std::vector<T> Matrix<T>::operator[](unsigned int rowIndex) const {
    std::vector<T> output;

    if (rowIndex >= r) {
        // Need to throw an exception for index out of range
        throw MatrixError(1, ERROR_1);
    } else if ((rowIndex + 1) * c > size()) {
        // Need to throw an exception for index out of range
        throw MatrixError(4, ERROR_4);
    } else {
        unsigned int start = rowIndex * c;
        unsigned int end = start + c;

        for (unsigned int i = start; i < end; i++) {
            output.push_back(v[i]);
        }

        return output;
    }
}

/**
 * Add function to return the transposition of the Matrix
 * @tparam T template type
 * @return transposed - A Matrix object that is the transposed representation of the caller object.
 */
template <typename T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> transposed(c, r);

    if (r > 0 && c > 0) {

        unsigned int matSize = r * c;

        for (unsigned int i = 0; i < c; i++) {
            for (unsigned int j = 0; j < r; j++) {
                transposed.push_back(v[ j * c + i]);
            }
        }

        return transposed;
    }
}


#endif // MATRIX_HPP
