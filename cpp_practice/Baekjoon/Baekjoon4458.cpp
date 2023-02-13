#include <iostream>

using namespace std;

int main(){

    int a;

    cin >> a;
    cin.ignore();
    for (int i = 0; i < a; i++){
        string str;

        getline(cin, str);

        for(int j = 0; j < str.length(); j++){
            if(j==0){
                str[j]=toupper(str[j]);
                cout << str[j];
                continue;
            }
            cout << str[j];
        }cout << endl;
    }

    return 0;
}