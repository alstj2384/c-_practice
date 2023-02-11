#include <iostream>

using namespace std;
//떠오르는 생각 두 가지, interface 활용 또는 부모 클래스에서 공통 변수와 함수를 
//상속하는 것
class Math{

    public :
        void setValue(int x, int y);
        int calculate();
        int a, b;
};

class Add : public Math{};
class Sub : public Math{};
class Mul : public Math{};
class DIv : public Math{};