#!/usr/bin/env bash

handle_help() {
    echo -e "Usage: build.sh [TYPE]\n"
    echo -e "build.sh - Build Matrix Multiplication &  Transposition Library\n"
    echo -e "Positional Arguments:"
    echo -e "[TYPE] {deploy, develop}\t\t sets the mode of build type\n"
    echo -e "Optional Arguments:"
    echo -e "-h, --help\t\t\t Displays this help menu"
    echo -e "-v, --version\t\t\tDisplays the version"

    return $1
}

rm -rf build
mkdir build
cd build
cmake ../
