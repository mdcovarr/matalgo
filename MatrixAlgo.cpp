#include "MatrixAlgoConfig.h"
#include <iostream>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << MatrixAlgo_VERSION_MAJOR << "."
                  << MatrixAlgo_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    const double inputValue = std::stod(argv[1]);
}
