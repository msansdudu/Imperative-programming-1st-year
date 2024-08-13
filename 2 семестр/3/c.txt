gcc level1.c -c -Wall
gcc level2.c -c -Wall
gcc level3.c -c -Wall
ar rcs myblas.a level1.o level2.o level3.o