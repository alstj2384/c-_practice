#include <iostream>

using namespace std;
//�������� ���� �� ����, interface Ȱ�� �Ǵ� �θ� Ŭ�������� ���� ������ �Լ��� 
//����ϴ� ��
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