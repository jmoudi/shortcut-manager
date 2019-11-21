#!/bin/bash

echo "Reloading at $(date +"%H:%M:%S-%N")";

gcc -Wall "$1" -lX11 -o 'run' && ./run;