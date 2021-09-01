#!/usr/bin/env bash
echo "start"

rm -rf build/
echo "创建编译目录：build"
mkdir build
echo "in编译目录：build"
cd build/
echo "do:cmake"
cmake ../
echo "do:make"
make
echo "do:make install"
make install

echo "End"
