#include<iostream>
#include<string>
using namespace std;

class Integer{
    private :
        int n;

    public : 
        Integer(string s){
            n = stoi(s);
        }
        Integer(int a){
            n = a;
        }

        int get(){
            return n;
        }

        void set(int a){
            n = a;
        }

        bool isEven(){
            if(n % 2 == 0) return true;
        }
};

int main() {
    Integer n(30);
    cout << n.get() << ' '; // 30 ��� 
    n.set(50);
    cout << n.get() << ' '; // 50 ��� 
    
    Integer m("300");
    cout << m.get() << ' '; // 300 ��� 
    cout << m.isEven(); // true(������ 1) ��� 
}