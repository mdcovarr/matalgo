#!/usr/bin/env bash

handle_error() {
    echo -e "Error: Unhandled argument received, exiting..."
}

handle_version() {
    echo -e "version 1.0"
}

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

handle_deploy() {
    rm -rf Release
    mkdir Release
    pushd Release

    cmake3 ../ -DCMAKE_BUILD_TYPE=Release ..
    make -j$(nproc)

    popd
}

handle_develop() {
    rm -rf Debug
    mkdir Debug
    pushd Debug

    cmake3 ../ -DCMAKE_BUILD_TYPE=Debug ..
    make -j$(nproc)

    popd
}

for elem in "$@"
do
    if [ "$elem" = "--help" -o "$elem" = "-h" ]
    then
        handle_help 0
        exit 0
    fi;

    if [ "$elem" = "--version" -o "$elem" = "-v" ]
    then
        handle_version
        exit 0
    fi;

    if [ "$elem" = "deploy" ]
    then
        handle_deploy
        exit $?
    fi;

    if [ "$elem" = "develop" ]
    then
        handle_develop
        exit $?
    fi;

    handle_error
    exit 1
done

rm -rf build
mkdir build
cd build
cmake ../
