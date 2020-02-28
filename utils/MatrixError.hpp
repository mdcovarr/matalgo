/*
 * \file MatrixError.hpp
 * \brief Matrix Error message implementation for library
 */

#ifndef MATRIX_ERROR_HPP
#define MATRIX_ERROR_HPP

#include <sstream>
#include <string>

static const std::string ERROR_1 = "Index out of range";
static const std::string ERROR_2 = "Incompatible Matrix Dimensions";
static const std::string ERROR_3 = "Invalid dimension for Matrix object";

class MatrixError {
    private:
        std::string message;
        int errorCode;

    public:

        MatrixError(int code, std::string errorMessage) {
            // need to get error code
            errorCode = code;
            std::stringstream ss(errorMessage);

            if (errorCode < 1) {
                errorCode = -1;
            }

            if (errorCode < 1) {
                message = "This is an unknown exception message";
            } else {
                message = errorMessage;
            }
        }


        inline std::string getErrorMessage() {
            return message;
        }

        inline int getErrorCode() {
            return errorCode;
        }

};

#endif // MATRIX_ERROR_HPP
