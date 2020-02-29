#include "MatrixAlgoConfig.h"
#include <iostream>

#include "Matrix.hpp"

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

int main(int argc, char* argv[]) {

    int  am[2][3] = {
            {1,2,3},
            {4,5,6},
    };
    int  bm[3][2] = {
            {1,2},
            {3,4},
            {5,6}
    };

    Matrix<int> a(ARRAY_SIZE(am), ARRAY_SIZE(am[0]), am[0], ARRAY_SIZE(am)*ARRAY_SIZE(am[0]));
    Matrix<int> b(ARRAY_SIZE(bm), ARRAY_SIZE(bm[0]), bm[0], ARRAY_SIZE(bm)*ARRAY_SIZE(bm[0]));
    Matrix<int> c;
    Matrix<int> d;

    std::cout << a.size() << std::endl;



    try {
        c = a * b;

        for (unsigned int i = 0; i < c.rowNum(); i++) {
            for (unsigned int j = 0; j < c.colNum(); j++) {
                std::cout <<  c[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    } catch (MatrixError& e) {
        std::cerr << e.getErrorMessage() << std::endl;

        return e.getErrorCode();
    }

    try {
        d = c.transpose();

        for (unsigned int i = 0; i < d.rowNum(); i++) {
            for (unsigned int j = 0; j < d.colNum(); j++) {
                std::cout << d[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } catch (MatrixError& e) {
        std::cerr << e.getErrorMessage() << std::endl;

        return e.getErrorCode();
    }
}
