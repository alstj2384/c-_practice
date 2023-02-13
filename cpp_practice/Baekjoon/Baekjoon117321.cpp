#include <iostream>

using namespace std;

int main(){

    string str;
    cin >> str;
    int i = 0;
    while(i <= str.length()){
        cout << str.substr(i, 10) << endl;
        i += 10;
    }
    return 0;
}