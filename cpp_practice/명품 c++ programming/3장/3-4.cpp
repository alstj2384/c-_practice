#include <iostream>

using namespace std;

class CoffeeMachine{
    private :
        int Coffee;
        int Water;
        int Sugar;

    public : 

        CoffeeMachine(int a, int b, int c){
            Coffee = a;
            Water = b;
            Sugar = c;
        }

        void drinkEspresso(){
            Coffee = Coffee-1;
            Water = Water -1;
        }
        void drinkAmericano(){
            Coffee = Coffee-1;
            Water = Water -2;
        }
        void drinkSugarCoffee(){
            Coffee = Coffee-1;
            Water = Water -2;
            Sugar = Sugar -1;
        }
        void show(){
            cout << "Ŀ�� �ӽ� ����, Ŀ��:" << Coffee << "��:" << Water << "    ����:" << Sugar <<endl;
        }
        void fill(){
            Coffee = 10;
            Water = 10;
            Sugar = 10;
        }
};

int main() {
    CoffeeMachine java(5, 10, 3); // Ŀ�Ƿ�:5, ����:10, ����:6 ���� �ʱ�ȭ
    java.drinkEspresso(); // Ŀ�� 1, �� 1 �Һ�
    java.show(); // ���� Ŀ�� �ӽ��� ���� ���
    java.drinkAmericano(); // Ŀ�� 1, �� 2 �Һ�
    java.show(); // ���� Ŀ�� �ӽ��� ���� ���
    java.drinkSugarCoffee(); // Ŀ�� 1, �� 2, ���� 1 �Һ�
    java.show(); // ���� Ŀ�� �ӽ��� ���� ���
    java.fill(); // Ŀ�� 10, �� 10, ���� 10 ���� ä���
    java.show(); // ���� Ŀ�� �ӽ��� ���� ���


    return 0;
}