gcc -c -fPIC echo.c
gcc -shared -o core.so echo.o
