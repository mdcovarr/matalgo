/*
 * \file Matrix.hpp
 * \brief Matrix implementation for library
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP
/*
 * Class to represent Matrix implementation
 */
template <class T>
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

    Matrix(unsigned int,, unsigned int, T* = 0, unsigned int = 0);

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

#endif // MATRIX_HPP