#include<iostream>

using namespace std;


class Oval{
    private :
        int width, height;

    public :
        Oval(); // 너비와 높이를 1로 초기화하는 매개 변수 없는 생성자
        Oval(int a, int b); // 너비와 높이 값을 매개 변수로 받는 생성자
        int getWidth();
        int getHeight();
        void set(int w, int h);
        void show();

        ~Oval();
};

    Oval::Oval(){
        width = 1;
        height = 1;
    }

    Oval::Oval(int a, int b){
        width = a;
        height = b;
    }

    int Oval::getWidth(){
        return width;
    }

    int Oval::getHeight(){
        return height;
    }

    void Oval::set(int w, int h){
        width = w;
        height = h;
    }

    void Oval::show(){
        cout << "width = " << width << ", height = " << height << endl;
    }
    Oval::~Oval(){
        cout << "Oval 소멸 : width = " << width << ", height = " << height << endl;
    }



int main() {
    Oval a, b(3,4);
    a.set(10, 20);
    a.show();
    cout << b.getWidth() << "," << b.getHeight() << endl;
}
