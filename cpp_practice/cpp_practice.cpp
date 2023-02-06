#include <iostream>

using namespace std;

class MyCar {
    private:
        //멤버 변수
        int fuel = 0;
        bool power = false;

    public:
        //생성자
        MyCar(){
            this->fuel = 100;
            this->power = true;
        }
        //생성자 다중 정의
        MyCar(int n){
            this->fuel = n;
            this->power = true;
        }

        //소멸자(다중 정의 불가능)
        ~MyCar(){
            cout << "소멸되었습니다." << endl;
        }
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
   
    //메서드 호출
    // MyCar car = MyCar();

    // car.oiling(100);
    // car.fuel_check();

    // for(int i =0 ; i<10; i++) car.go();

    // car.fuel_check();
    // car.oiling(100);

    // for(int i=0;i<10;i++) car.go();
    // car.fuel_check();


    //클래스 배열 사용
    MyCar car[3]; //생성

    for (int i = 0; i < 3; i++)car[i] = MyCar();
    /*클래스 배열을 사용할 때는 생성 즉시 초기화가 되지 않으므로
     * 생성 후 따로 for문을 돌려서 초기화 시켜주어야 함
     * 기본 생성자가 클래스 내부에 존재할 경우 사용 가능
    */

    //메서드 호출
    car[0].oiling(100);
    car[0].fuel_check();
    for(int i = 0; i < 10; i++) car[0].go();
    car[0].fuel_check();

    return 0;
}