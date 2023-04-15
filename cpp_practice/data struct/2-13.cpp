#include <iostream>

using namespace std;

// 2-13 1부터 n까지 더하는 프로그램 작성

int rec(int n){
    if(n==1){
        return 1;
    }
    return n + rec(n-1);
}
int main(){

    int n;
    cin >> n;
    cout << rec(n) << '\n';

    return 0;
}