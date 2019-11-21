nodemon --watch './src/*.*' --ext 'c' --exec './compile.sh' -- './src/xsendkey.c'


nodemon --watch './src/*.*' --ext 'c' --exec './scripts/compile.sh' -- './src/x-sender/src/example.cpp' './bin/example'

clang -Werror --include-directory "./lib/cxxopts/include" --include-directory "/usr/include/c++/9.2.0/experimental" -o "./bin/example" "./src/x-sender/test/t1.cpp"

clang -Werror --include-directory "./lib/cxxopts/include" --include-directory "/usr/include/c++/9.2.0" -o "./bin/example" "./src/x-sender/test/t1.cpp"

clang -Werror --include-directory "./lib/cxxopts/include"  -o "./bin/example" "./src/x-sender/test/t1.cpp"


-Werror
clang -v -Wall --include-directory ./lib/cxxopts/include -o './bin/example' ./src/x-sender/src/example.cpp

clang -Werror --include-directory "./lib/cxxopts/include" --include-directory "/usr/include/c++/9.2.0/experimental" -o "./bin/example" "./src/x-sender/test/t1.cpp"


clang -v --include-directory="./lib/argparse" -Wall -o "./bin/example" "./src/x-sender/test/t1.cpp"

/usr/include/c++/9.2.0/experimental/

clang -Werror -o "./bin/example" "./src/x-sender/test/t1.cpp"


clang --include-directory="./lib/argparse" -Werror -o "./bin/example" "./src/x-sender/test/t1.cpp"

gcc -Werror --include-directory ./lib/cxxopts/include -o './bin/example' ./src/x-sender/src/example.cpp

clang -Werror --include-directory="./lib/cxxopts/include" -o './bin/example' ./src/x-sender/src/example.cpp
 \
"a" "bb" "ccc"


clang -v -Wall -I ./lib/cxxopts/include -o './bin/example' ./src/x-sender/src/example.cpp