#include <iostream>

using namespace std;

class MyCar {
    private:
        //��� ����
        int fuel = 0;
        bool power = false;

    public:
        //������
        MyCar(){
            this->fuel = 100;
            this->power = true;
        }
        //������ ���� ����
        MyCar(int n){
            this->fuel = n;
            this->power = true;
        }

        //�Ҹ���(���� ���� �Ұ���)
        ~MyCar(){
            cout << "�Ҹ�Ǿ����ϴ�." << endl;
        }
        //�޼ҵ�
        void go(){
            this -> fuel--;
        }

        void oiling(int n){
            this->fuel += n;
        }

        void fuel_check(){
            cout << "���� : " << fuel << endl;
        }
};

int main()
{
   
    //�޼��� ȣ��
    // MyCar car = MyCar();

    // car.oiling(100);
    // car.fuel_check();

    // for(int i =0 ; i<10; i++) car.go();

    // car.fuel_check();
    // car.oiling(100);

    // for(int i=0;i<10;i++) car.go();
    // car.fuel_check();


    //Ŭ���� �迭 ���
    MyCar car[3]; //����

    for (int i = 0; i < 3; i++)car[i] = MyCar();
    /*Ŭ���� �迭�� ����� ���� ���� ��� �ʱ�ȭ�� ���� �����Ƿ�
     * ���� �� ���� for���� ������ �ʱ�ȭ �����־�� ��
     * �⺻ �����ڰ� Ŭ���� ���ο� ������ ��� ��� ����
    */

    //�޼��� ȣ��
    car[0].oiling(100);
    car[0].fuel_check();
    for(int i = 0; i < 10; i++) car[0].go();
    car[0].fuel_check();

    return 0;
}