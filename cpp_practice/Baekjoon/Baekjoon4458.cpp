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

//getline으로 받을 때 문제점, 이 전에 cin을 받았다면 ,\n(개행문자)가
// 입력버퍼에 남아있어서 getline 입력에 문제가 생길 수 있다.