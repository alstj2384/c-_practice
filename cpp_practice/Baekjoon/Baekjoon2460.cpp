#include <iostream>

using namespace std;

void getIn(int a, int *sum){ // ž�� �ο� ��, ���� �ִ� �ο� ��
    *sum += a;
}

void getOut(int a, int *sum){ // ž�� �ο� ��, ���� �ִ� �ο� ��
    *sum -= a;
}



int main(){

    int a;
    int b;
    int sum=0;
    int tmp = 0;
    int result;

    for(int i = 0; i < 10; i ++){
        cin >> a;
        cin >> b;
        getOut(a, &sum);
        getIn(b, &sum);

        result = (tmp > sum ? tmp : sum);
        if(tmp < sum) tmp = sum; 

    }

    cout << result << endl;

    return 0;
}