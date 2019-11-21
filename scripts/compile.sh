#!/bin/bash

echo "Reloading project at: $(date +"%H:%M:%S-%N")";

function compile(){
    echo "Compiling with Args: $1 ...$2";
    #gcc -Wall "$1" -lX11 -o 'run' && ./run;
    clang -v -Wall -o "$2" "$1"
}
compile

