#include <iostream>

using namespace std;
//30 23분 (7분)
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b;
    int cnt = 0;
    cin >> a >> b;

    while(a != 1){
        if(a%b==0) {
            a/=b;
            cnt++;
        }
        else {
            a= a-1;
            cnt++;
        }

    }

    cout << cnt << endl;
    return 0;
}