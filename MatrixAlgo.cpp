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

    std::cout << a.size() << std::endl;
}
