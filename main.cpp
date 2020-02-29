/**
 * Main Entrance of script used to show multiplication and transposition of Matrix
 * Implementation
 */

#include "MatrixAlgoConfig.h"
#include <iostream>

#include "Matrix.hpp"


int main(int argc, char* argv[]) {

    int  aData[2][6] = {
            {1, 2, 3, 4, 5, 6},
            {7, 8, 9, 10, 11, 12},
    };
    int  bData[6][2] = {
            {1, 2},
            {3, 4},
            {5, 6},
            {4, 9},
            {2, 1},
            {6, 9}
    };

    int aRow = sizeof aData / sizeof(aData[0]);
    int aCol = sizeof aData[0] / sizeof(int);
    int bRow = sizeof bData / sizeof(bData[0]);
    int bCol = sizeof bData[0] / sizeof(int);

    Matrix<int> a(aRow, aCol, aData[0], aRow * aCol);
    Matrix<int> b(bRow, bCol, bData[0], bRow * bCol);
    Matrix<int> c;
    Matrix<int> d;


    try {
        std::cout << "Matrix A contents" << std::endl;

        for (unsigned int i = 0; i < a.rowNum(); i++) {
            for (unsigned int j = 0; j < a.colNum(); j++) {
                std::cout <<  a[i][j] << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    } catch (MatrixError& e) {
       std::cerr << e.getErrorMessage() << std::endl;

       return e.getErrorCode();
    }


    try {
        std::cout << "Matrix B contents" << std::endl;

        for (unsigned int i = 0; i < b.rowNum(); i++) {
            for (unsigned int j = 0; j < b.colNum(); j++) {
                std::cout <<  b[i][j] << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    } catch (MatrixError& e) {
       std::cerr << e.getErrorMessage() << std::endl;

       return e.getErrorCode();
    }


    try {
        std::cout << "Matrix C = A * B" << std::endl;
        c = a * b;

        for (unsigned int i = 0; i < c.rowNum(); i++) {
            for (unsigned int j = 0; j < c.colNum(); j++) {
                std::cout <<  c[i][j] << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    } catch (MatrixError& e) {
        std::cerr << e.getErrorMessage() << std::endl;

        return e.getErrorCode();
    }

    try {
        std::cout << "Matrix D = C transposed" << std::endl;
        d = c.transpose();

        for (unsigned int i = 0; i < d.rowNum(); i++) {
            for (unsigned int j = 0; j < d.colNum(); j++) {
                std::cout << d[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    } catch (MatrixError& e) {
        std::cerr << e.getErrorMessage() << std::endl;

        return e.getErrorCode();
    }
}
