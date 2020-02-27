/*
 * \file Matrix.hpp
 * \brief Matrix implementation for library
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

/*
 * Class to represent Matrix implementation
 */
template <typename T>
class Matrix {
private:

    std::vector<T> v;
    unsigned int r;
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

    Matrix(unsigned int, unsigned int, T* = 0, unsigned int = 0);

    Matrix(unsigned int, unsigned int, const std::vector<T>&);

    virtual ~Matrix() {
        clear();
    }

    Matrix& operator=(const Matrix&);
    std::vector<T> operator[](unsigned int) const;
    Matrix operator*(const Matrix&);

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
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& original) {
    clear();

    if (original.m > 0 && original.n > 0) {
        r = original.r;
        c = original.c;

        unsigned int matSize = r * c;

        for (unsigned int i = 0; i < matSize && i < original.size(); i++) {
            v.push_back(original.v[i]);
        }
    }
}


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

                    for (unsigned int k = 1; k < c; k++){
                        currVal += v[i * c + k] * mat2.v[k * mat2.c + j];
                    }

                    product.push_back(currVal);
                }
            }
    }
}


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


#endif // MATRIX_HPP