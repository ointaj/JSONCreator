
#!/bin/bash

rm -rf ./out/build/

if [[ ${1} == "-r" ]];
then
    rm -rf ./out/
    exit 1
fi

cmake -S . -B ./out/build/
CMAKE=$?

if [[ ${CMAKE} != 0 ]];
then
    echo "ERROR:  cmake"
    exit 2
fi

make -C ./out/build/
MAKE=$?

if [[ ${MAKE} != 0 ]];
then 
    echo "$ERROR:  make"
    exit 3
fi

mv ./out/build/JSONCreator ./out/

echo "SUCCESS"