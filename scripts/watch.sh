#!/bin/bash

nodemon --watch './src/*.*' --ext 'c' --exec './compile.sh' -- './src/xsendkey.c' './bin/'


