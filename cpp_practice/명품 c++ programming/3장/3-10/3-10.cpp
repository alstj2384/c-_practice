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

//부모클래스에서 자식클래스로 상속하고 선언하려고 하니 상속받을 수 없다고 나옴.에서 끝남
//정리는 나중에 하는 거로
