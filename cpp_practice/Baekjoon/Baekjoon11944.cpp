#include <iostream>

using namespace std;

//23�� �ɸ�

int main(){
    int a, m, count = 0;
    cin >> a >> m;
    string str;
    str = to_string(a);
    int i =0;
    int k = str.length();
    if(k*a > m){
        while(count < m){
            cout << str[i];
            i = (i+1)%k;//k�� �ڸ���
            count++;
        }
    }
    else{
        for(int j = 0; j < a ; j++){
            cout<<str;
        }
    }
    return 0;
}


// ���ڸ� ���ڿ��� �ٲ㼭 while���� ���� ���ڿ� �ε��� �� ĭ �� ó��
// �� �� �ݺ��� cnt 1�� ����, 
// idx���� �� ó������ idx/2 or 3 (�ڸ����� ���� �޶���)�� ���ָ鼭 
// ���ڿ��� ������� ������ ���ָ� �ɵ�.