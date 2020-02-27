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