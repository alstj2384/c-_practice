#include <iostream>

using namespace std;

// 2-14 1부터 1/n까지 더하는 프로그램 작성

float rec(float n){
    if(n==1){
        return 1;
    }
    return 1/n + rec(n-1);
}
int main(){

    float n;
    cin >> n;
    cout << rec(n) << '\n';

    return 0;
}