#include <iostream>
using namespace std;

class Date{
    private :
        int year;
        int month;
        int day;

    public :
        Date(int a, int b, int c){
            year = a;
            month = b;
            day = c;
        }
        Date(string str){
            year = stoi(str.substr(0,4));
            month = stoi(str.substr(5,1));
            day = stoi(str.substr(7,2));
        }

        int getYear() {
            return year;
        }
        int getMonth(){ 
            return month;
        }
        int getDay() {
            return day;
        }

        void show(){
            cout << year << "년" << month << "월" << day << "일\n";
        }
};

int main() {
    Date birth(2014, 3, 20);
    Date independenceDay("1945/8/15");
    independenceDay.show();
    cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}

/*알게된 점
같은 클래스라고 해서 생성자의 자료형이 굳이 같을 필요는 없다.
다른 자료형을 받아서 변환해주면 그만인 일
*/