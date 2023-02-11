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
    Account a("Kitae", 1, 5000); // id 1번, 잔액 5000원, 이름이 Kitae인 계좌 성
    a.deposit(50000); // 50000원 저금
    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
    int money = a.withdraw(20000); // 20000원 출금. withdraw()는 출금한 실제 금액 리턴
    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}