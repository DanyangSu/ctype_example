#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

class Libmath
{
    public:
        Libmath(int);
        double cfib();
    private:
        int val;
        double cfib_(int);

};

Libmath::Libmath(int n)
{
    val = n;
}

double Libmath::cfib_(int n) 
{
    int i;
    double a=0, b=1, tmp;
    for (i=0; i<n; i++) {
        tmp = a; a = a + b; b = tmp;
    }
    return a;
}

double Libmath::cfib()
{
    double a;
    a = cfib_(val);
    return a;
}


extern "C"
{    
    Libmath* Libmath_new(int n) {return new Libmath(n);}
    double Libmath_cfib(Libmath* libmath) {return libmath->cfib();}
}
