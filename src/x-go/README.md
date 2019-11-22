go build -a

gcc -Wall ./xsendkey.c

gcc -Wall -I /usr/include/X11 ./xsendkey.c