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


## Build Debug
To build for development, run command:
```
./build.sh develop
```


