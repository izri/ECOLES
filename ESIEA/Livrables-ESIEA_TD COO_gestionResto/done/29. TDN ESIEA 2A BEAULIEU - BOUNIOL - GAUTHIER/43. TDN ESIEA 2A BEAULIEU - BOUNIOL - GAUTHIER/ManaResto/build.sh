#!/bin/bash

OS=$(uname -s)
CURRENTPATH=$(pwd)
BUILDFOLDER="build"
ABSOLUTEFOLDER="$CURRENTPATH/$BUILDFOLDER"

checkbuildfolder() {
	echo "PWD : $CURRENTPATH"
	if [ ! -d "$BUILDFOLDER" ]; then
		mkdir "$ABSOLUTEFOLDER"
	else
		echo "The build folder already exists !"
	fi
}

build() {
	cd "$ABSOLUTEFOLDER"
	qmake ../
	make -j "$(($1 + 1))"
	mv ../build ../../build
}

error() {
    echo "Make sure that qmake, make, g++ and qt5-default are installed."
    echo "For Ubuntu 14.04 users, to install all requirements do :"
    echo "sudo apt-get update && sudo apt-get install qt5-qmake make g++ qt5-default -y"
}

if [ ! "$(command -v qmake)" > /dev/null ]; then
	error
	exit 1
fi

if [ ! "$(command -v make)" > /dev/null ]; then
	error
	exit 1
fi

if [ ! "$(command -v g++)" > /dev/null ]; then
	error
	exit 1
fi

checkbuildfolder

if [ "$OS" == "Darwin" ]; then
	echo "OS : Mac OS X"
	CORES=$(sysctl -a | grep machdep.cpu.core_count: | awk '{print $2}')
	echo "Cores : $CORES"
	build $CORES
elif [ "$OS" == "Linux" ]; then
	echo "OS : GNU/Linux"
	CORES=$(cat /proc/cpuinfo | grep proc | wc -l | awk '{print $0+1}')
	echo "Cores : $CORES"
	build $CORES
else
	echo "Unknown OS"
fi
