#!/bin/bash

if [[ ${1} == "" ]];
then
    echo "PARAMETER MISSING"
    echo "Write ./run.sh --help"
    exit 1
fi

if [[ ${1} == "--help" ]];
then
    echo "To run program write ./run.sh -test.txt !"
    exit 2
fi

./out/JSONCreator "${1:1}"
