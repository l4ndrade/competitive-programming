#!/bin/bash
clear
g++ -std=c++17 -O2 -Wall $2 $1/$1.cpp
for file in $1/in*
do
    echo $file
    ./a.out <$file
    echo "-----------------------"
    echo
done