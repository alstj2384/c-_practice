#include <iostream>

using namespace std;

int reverseNum(int a){
    int r = 0;
    while (a) {
        r = (r * 10) + (a % 10);
        a = a / 10;
    }

    return r;
}

int main(){

    int a, b;
    cin >> a;
    cin >> b;

    int result = (reverseNum(a) > reverseNum(b)) ? reverseNum(a) :  reverseNum(b);

    
    cout << result << endl;
    return 0;
}