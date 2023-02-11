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
            cout << "커피 머신 상태, 커피:" << Coffee << "물:" << Water << "    설탕:" << Sugar <<endl;
        }
        void fill(){
            Coffee = 10;
            Water = 10;
            Sugar = 10;
        }
};

int main() {
    CoffeeMachine java(5, 10, 3); // 커피량:5, 물량:10, 설탕:6 으로 초기화
    java.drinkEspresso(); // 커피 1, 물 1 소비
    java.show(); // 현재 커피 머신의 상태 출력
    java.drinkAmericano(); // 커피 1, 물 2 소비
    java.show(); // 현재 커피 머신의 상태 출력
    java.drinkSugarCoffee(); // 커피 1, 물 2, 설탕 1 소비
    java.show(); // 현재 커피 머신의 상태 출력
    java.fill(); // 커피 10, 물 10, 설탕 10 으로 채우기
    java.show(); // 현재 커피 머신의 상태 출력


    return 0;
}