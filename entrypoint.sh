#!/bin/bash

cd /project

cpp_v=("$(g++ --version)")
echo $cpp

mkdir -p build && cd build

cmake ..

make

./E_commerce
# Compile the Java PAC demo project
# mvn clean install

# Run the Java PAC demo project
# mvn spring-boot:run