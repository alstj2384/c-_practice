#include <iostream>
#include <string.h>
#include "detail.cpp"


int main(){
    Account a("¹ÎÀç", 1, 5000);
    Account b("ÅÂ¹Î", 2, 10000);
    a.deposit(50000);
    a.status();
    int money = a.withdraw(20000);
    a.status();

    
    b.deposit(50000);
    b.status();
    money = b.withdraw(280000);
    b.status();

    cout << a.inquiry() - b.inquiry() << endl;
    cout << a.inquiry() - b.inquiry() << endl;

	return 0;  

}