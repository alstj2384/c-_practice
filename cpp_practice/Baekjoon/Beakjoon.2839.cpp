#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;
    int cnt = 0;
    while(true){
        if(N % 5 == 0) {
            cnt += N/5;
            N = 0;
        }
        else if (N % 3 == 0){
            cnt += N/3;
            N = 0;
        }
        if(N - 5 >= 0) {
            cnt++;
            N -= 5;
        }
        else if(N - 3 >= 0) {
            cnt++;
            N -= 3;
        }
        else if(N == 0) {
            cout << cnt << endl;
            break;
        }
        else {
            cout << -1 << endl;
            break;
        }
    }

    return 0;
}