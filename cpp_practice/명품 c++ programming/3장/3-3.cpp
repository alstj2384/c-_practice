#include <iostream>
using namespace std;
 
class Account{
    private:
        string Name;
        int Id;
        int Money;

    public :
        Account(string name, int id, int money){
            Name = name;
            Id = id;
            Money = money;
        }
        int deposit(int money){
            Money += money;
        }
        int withdraw(int money){
            Money -= money;
        }
        string getOwner(){
            return Name;
        }
        int inquiry(){
            return Money;
        }
};
int main() {
    Account a("Kitae", 1, 5000); // id 1��, �ܾ� 5000��, �̸��� Kitae�� ���� ��
    a.deposit(50000); // 50000�� ����
    cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
    int money = a.withdraw(20000); // 20000�� ���. withdraw()�� ����� ���� �ݾ� ����
    cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
}