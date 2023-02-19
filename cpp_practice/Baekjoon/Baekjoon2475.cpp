#include <iostream>

using namespace std;


int main(){

    //문자열 처음이나 끝이 ' '이면 컨티뉴
    string str;
    getline(cin, str);
    int cnt =0;
    for(int i= 0; i < str.length(); i++){
        if(i == 0 && str[i] == ' ') continue;
        else if(i == str.length()-1 && str[i]==' ')continue;
        if(str[i]==' ') {
            cnt++;
            cout << "빈칸발견" << endl;
        }
    }if(str.length()==3) cnt++;
    cout << cnt << endl;

    return 0;
}