#include <iostream>

using namespace std;

typedef struct _complex{
    float real;
    float imaginary;
} complex;

complex complex_add(complex a, complex b);

int main(){

    complex c1;
    complex c2;
    
    c1.real = 1.2; c1.imaginary = 2.4;
    c2.real = 1.1; c2.imaginary = 2.2;

    complex result = complex_add(c1, c2);

    cout << result.real << " " << result.imaginary<< endl;
    return 0;
}


complex complex_add(complex a, complex b){
    complex add;

    add.real = a.real + b.real;
    add.imaginary = a.imaginary + b.imaginary;

    return add;
}