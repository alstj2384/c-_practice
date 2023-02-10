#include <iostream>

using namespace std;

//23분 걸림

int main(){
    int a, m, count = 0;
    cin >> a >> m;
    string str;
    str = to_string(a);
    int i =0;
    int k = str.length();
    if(k*a > m){
        while(count < m){
            cout << str[i];
            i = (i+1)%k;//k는 자리수
            count++;
        }
    }
    else{
        for(int j = 0; j < a ; j++){
            cout<<str;
        }
    }
    return 0;
}


// 숫자를 문자열로 바꿔서 while문을 통해 문자열 인덱스 한 칸 씩 처리
// 한 번 반복에 cnt 1씩 증가, 
// idx값은 끝 처리에서 idx/2 or 3 (자리수에 따라 달라짐)을 해주면서 
// 문자열이 순서대로 돌도록 해주면 될듯.