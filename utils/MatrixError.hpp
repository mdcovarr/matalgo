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
static const std::string ERROR_4 = "Not enough data in Matrix object";
static const int NUMBER_OF_ERRORS = 4;

/**
 * Matrix Exception Handling Helper class.
 */
class MatrixError {
    private:
        std::string message;
        int errorCode;

    public:

        /**
         * Constructing Matrix Error object
         * @param code - integer value of error code occuring
         * @param errorMessage - error message string
         */
        MatrixError(int code, std::string errorMessage) {
            // currently only have 4 different error codes
            std::stringstream ss(errorMessage);

            if (code < 1 || code > NUMBER_OF_ERRORS) {
                errorCode = -1;
                message = "This is an unknown exception message";
            } else {
                errorCode = code;
                message = errorMessage;
            }
        }


        /**
         * Function used to get error message when throwing exception
         * @return message - string representation of error
         */
        inline std::string getErrorMessage() {
            return message;
        }

        /**
         * Function used to get error code when throwing exception
         * @return errorCode - errorCode integer of error that occurred
         */
        inline int getErrorCode() {
            return errorCode;
        }

};

#endif // MATRIX_ERROR_HPP
