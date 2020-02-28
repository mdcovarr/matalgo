/*
 *  \file Matrix.cpp
 *  \brief File used to implement functionality for the Matrix class.
 */

#include "Matrix.hpp"

/*
 *  Template class function/operators implementation
 */


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
    Matrix<T> product(r, mat2.c);

    if (c != mat2.r) {
        // TODO: need to throw an exception
    } else if (r < 1 || c < 1 || mat2.c) {
        // TODO: need to throw an exception
    } else if ((r * c > size()) || (mat2.r * mat2.c > mat2.size())) {
        // TODO: need to throw an exception
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

                product.push_back(currVal);
            }
        }
    }
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
        // TODO: need to throw an exception
    } else if ((rowIndex + 1) * c) {
        // TODO: need to also throw an exception
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
