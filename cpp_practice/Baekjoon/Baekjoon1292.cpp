#include <iostream>

using namespace std;

int easyNum(int a){
    int cnt = 0;
    int i= 1;
    int sum=0;
    while(1){
        for(int j = 0; j < i; j++){
            cnt++;
            if(cnt > a) break;
            sum += i;
        }
        if(cnt > a) break; 
        i++;
    }
    return sum;
}

int main(){
    int a, b;
    cin >> a>>b;
    a=a-1;
    cout << abs(easyNum(b)-easyNum(a)) << endl;

    return 0;
}//1 22 333 4444 55555

