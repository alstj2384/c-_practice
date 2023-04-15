#include <iostream>

using namespace std;


struct person{
    string name;
    int age;
    float salary;

};
int main(){

    person p;

    p.name = "¼Û¹Î¼­";
    p.age = 23;
    p.salary = 700000;

    cout << p.name << '\n' << p.age << '\n' << p.salary << '\n'<< endl;
    return 0;
}