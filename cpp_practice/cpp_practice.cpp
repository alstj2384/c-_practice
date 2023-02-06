#include <iostream>

using namespace std;

class MyCar {
    private:
        //멤버 변수
        int fuel = 0;
        bool power = false;

    public:
        //메소드
        void go(){
            this -> fuel--;
        }

        void oiling(int n){
            this->fuel += n;
        }

        void fuel_check(){
            cout << "연료 : " << fuel << endl;
        }
};

int main()
{
    MyCar car = MyCar();

    //메서드 호출
    car.oiling(100);
    car.fuel_check();
    
    for(int i =0 ; i<10; i++) car.go();

    car.fuel_check();
    car.oiling(100);

    for(int i=0;i<10;i++) car.go();
    car.fuel_check();

    return 0;
}