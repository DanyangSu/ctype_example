g++ -c -fPIC fib.cpp -o _fib.o
g++ -shared -Wl,-soname,_fib.so -o _fib.so _fib.o

