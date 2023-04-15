#include <iostream>
#include "3-10.h"
using namespace std;

void Math::setValue(int x, int y){
    a = x;
    b = y;
}

int Add::calculate(){
    return a + b;
}
class Add : public Math{};
class Sub : public Math{};
class Mul : public Math{};
class DIv : public Math{};


