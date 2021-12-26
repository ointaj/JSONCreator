
#!/bin/bash

# rm -rf ./out/build/

BOLD=`tput bold`

if [[ ${1} == "-r" ]];
then
    rm -rf ./out/
fi

cmake -S . -B ./out/build/
CMAKE=$?

if [[ ${CMAKE} != 0 ]];
then
    echo "${BOLD} ERROR:  cmake"
    exit 1
fi

make -C ./out/build/
MAKE=$?

if [[ ${MAKE} != 0 ]];
then 
    echo "${BOLD} ERROR:  make"
    exit 2
fi

mv ./out/build/JSONCreator ./out/

echo "${BOLD}SUCCESS"