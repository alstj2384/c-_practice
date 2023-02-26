#include <iostream>

using namespace std;

int Fib(int k, int n){
    k--;
    if(k !=0){
        for(int i = 1; i < n+1 ;i++){
            Fib(k,n);
        }
    }
    if(k == 0){
        return n;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);


    return 0;
}