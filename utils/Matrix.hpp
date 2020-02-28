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

        Matrix(unsigned int row, unsigned int col, T* data, unsigned int dataLength) {
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

        Matrix(unsigned int row, unsigned int col, const std::vector<T>& data) {
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

#endif // MATRIX_HPP
