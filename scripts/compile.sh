#!/bin/bash

echo "Reloading project at: $(date +"%H:%M:%S-%N")";

function compile(){
    #gcc -Wall "$1" -lX11 -o 'run' && ./run;
    clang -v -Wall -I "$1" -o "$2"
}
