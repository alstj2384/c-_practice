#include <iostream>
#include <string>

using namespace std;


int main(){

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string str;
        cin >> str;
        string str2 = str.substr(0,1);
        string str3 = str.substr(2,1);
        int a = (str2[0]-'0') + (str3[0]-'0');
        cout << a << endl;
    }
    return 0;
}