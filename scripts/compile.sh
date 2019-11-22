#!/bin/bash

echo "Reloading project at: $(date +"%H:%M:%S-%N")";

function compile(){
    echo "Compiling with Args: ${1} ...${2}";
    gcc -v -Wall -lX11 -o "$2" "$1" #gcc -v -Wall -lX11 -o "$2"; "$1"
    #clang -v -Wall -lX11 -o "$2" "$1"
}
compile "$@"


