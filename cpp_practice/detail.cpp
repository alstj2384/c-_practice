#include <iostream>
#include <string.h>
#include "name.h"


using namespace std;


    Account::Account(string n, int i , int m){
        name = n;
        id = i;
        money = m;
    }

    int Account::inquiry(){
        return money;
    }
    string Account::getOwner(){
        return name;
    }
    int Account::deposit(int m){
        return money += m;
    }

    int Account::withdraw(int m){
        return money -= m;
    }

    void Account::status(){
        cout << getOwner() << "���� ���� �ܰ� :" << inquiry()<< "��"<<endl;
    }

    Account::~Account(){
        cout<<name<<"���� ���°� ���� �Ǿ����ϴ�"<<endl;
    }