#!/bin/bash

cd /project

cpp_v=("$(g++ --version)")
echo $cpp

mkdir -p build && cd build

cmake ..

make


echo The application is running, please hit http://localhost:8080/\<int\> in your web browser

echo \<int\> can be 0, 1, 2 or 3

./E_commerce 2> info.txt
