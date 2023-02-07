#include <iostream>
#include <string.h>

using namespace std;

class Account {
    string name;
    int id;
    int money;

public :
        Account(string n, int i , int m);
        int inquiry();
        string getOwner();
        int deposit(int m);
        int withdraw(int m);
        void status();
        ~Account();
};