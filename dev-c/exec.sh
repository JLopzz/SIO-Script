gcc prod1.c -o productor1
gcc prod2.c -o productor2
gcc prod3.c -o productor3
gcc prod4.c -o productor4
gcc cons.c -o consumidor
clear
./productor1
./productor2
./productor3
./productor4
./consumidor
rm productor1 productor2 productor3 productor4 consumidor