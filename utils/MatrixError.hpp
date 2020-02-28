/*
 * \file MatrixError.hpp
 * \brief Matrix Error message implementation for library
 */

#ifndef MATRIX_ERROR_HPP
#define MATRIX_ERROR_HPP

#include <sstream>
#include <string>

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
