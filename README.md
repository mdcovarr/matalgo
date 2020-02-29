# matalgo
A Matrix Multiplication Library

## Clone Repository
You can clone the source code for the Matrix Library Implementation:
```
git clone https://github.com/mdcovarr/matalgo.git
```

## Software Requirements
In order to build the project you need the following requirements:
```
cmake3 >= 3.10
```

# Implementation
For the project I implemented a class Matrix that is capable of creating a
object to represent/hold matrix data. I utilized Templates in C++ in order to be able
to create Matrix object of integers, doubles, floats, etc.

### Overloaded Operators
Overloaded some operators to be capable of multiplying matrices, assign matrices and access
the data in the matrices
```
operator *      // Overloaded to multiply matrices e.g. A * B
operator []     // Overloaded to access row and col of vector data matrix e.g. A[2][3]
operator =      // Overloaded to assign a matrix to another e.g. A = B
```


### Functions
Added functions to get information of matrix and to get tranposed representation of matrix.
```
rowNum()        // Getter which returns the number of rows in a matrix
colNum()        // Getter which returns the number of columns in a matrix
size()          // Getter which returns the full dimension size of the matrix
add()           // Function to add data to the matrix
transpose()     // Function which returns the transposition of a matrix
```


# Build

### Build Help
I created a helper script **build.sh** to help build the project using CMake.
The script is capable of building for Development or Deploy. In order to get help
of the command line parameters that you can pass to the script, run command:
```
./build.sh --help
```

Output of command should have show position and optional arguments like such.
```
Usage: build.sh [TYPE]

build.sh - Build Matrix Multiplication &  Transposition Library

Positional Arguments:
[TYPE] {deploy, develop}                 sets the mode of build type

Optional Arguments:
-h, --help                       Displays this help menu
-v, --version                   Displays the version
```

## Build Release
To build for deploy/release run command:
```
./build.sh deploy
```
This creates executable **MatrixAlgo** in folder
```
./Release
./Release/MatrixAlgo
```


## Build Debug
To build for development, run command:
```
./build.sh develop
```
This creates executable **MatixAlgo** in folder
```
./Debug
./Debug/MatrixAlgo
```

## Run Executable
You can run the **MatrixAlgo** executable to show you an example of the ability to
multiply matrices and to generate the transposition of a matrix.
```
./MatrixAlgo
```


# Matrix Class
The implementation of the Matrix Library capable of doing Matrix Multiplication
and Transposition is located at
```
utils/Matrix.hpp
```

### Matrix Exception Message Helper Class
If there are issues with attemptin to utilize the Matrix library, like multiplying
two matrices with incompatable parameters, we need to notify the user of the function.
For this we have the helper **MatrixError** class
```
utils/MatrixError.hpp
```

### main.cpp
The **main.cpp** file is a script that includes the **Matrix.hpp** implementation and displays
some examples of matrix contents, matrix multiplication and transposition.
```
./main.cpp
```

### Config
The **config** directory contains the configuration file that CMake utilizes to add version number to the project
```
config/MatrixAlgoConfig.h.in
```
