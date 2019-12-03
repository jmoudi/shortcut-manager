#!/bin/bash

#!/bin/bash

echo "Reloading project at: $(date +"%H:%M:%S-%N")";

function watch(){
    local srcFile=$1;
    local outputFile=$2;
    echo "Compiling with Args: $*";
    if [[ ~ "srcFile"]]
    #gcc -v -Wall -lX11 -o "$2" "$1" #gcc -v -Wall -lX11 -o "$2"; "$1"
    #clang -v -Wall -lX11 -o "$2" "$1"
}
watch "$@"




