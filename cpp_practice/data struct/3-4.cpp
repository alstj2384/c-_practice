#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int two[10];
    for(int i = 0; i < 10; i++) two[i] = pow(2,i);
    for(int i = 0; i < 10; i++) cout << two[i] << " " << '\n';
    return 0;
}