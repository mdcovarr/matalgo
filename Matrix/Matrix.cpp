/*
 *  \file Matrix.cpp
 *  \brief File used to implement functionality for the Matrix class.
 */

#include "Matrix.hpp"

/*
 *  Template class function/operators implementation
 */


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
