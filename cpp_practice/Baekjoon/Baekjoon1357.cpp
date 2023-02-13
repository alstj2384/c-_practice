#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;
//20���ϰ� 25�few��߰� + 5�� + 10��
//1�ð� ����

int main(){
    int a ,b ;

    cin >> a >> b ;
    string str;
    str = to_string(a);
    reverse(str.begin(), str.end());
    stringstream stream(str);
    stream >>  a;
    
    string str2;
    str2 = to_string(b);
    reverse(str2.begin(), str2.end());
    stringstream stream2(str2);
    stream2 >>  b;

    int c = a + b;

    string str3;
    str3 = to_string(c);
    reverse(str3.begin(), str3.end());
    stringstream stream3(str3);
    stream3 >>  c;

    cout << c << endl;

    
    return 0;
}
// reverse�Լ�
//���͸� ���ڷ� �ѱ� �� ������ �̰� ��ũ�޾Ƴ���