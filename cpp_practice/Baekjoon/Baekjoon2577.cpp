#include <iostream>

using namespace std;


int main(){

    int a, b, c;
    cin >> a >> b >> c;
    int list[10] = {0, };

    int big = a*b*c;

    while(big){
        
        list[big%10]++;
        big /= 10;
    }

    for(int i =0; i<10; i++) cout << list[i] << endl;
    return 0;
}