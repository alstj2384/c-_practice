#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;
//20분하고 25분추가 + 5분 + 10분
//1시간 ㅅㅂ

int main(){
    int a ,b ;

    cin >> a >> b ;
    string str;
    str = to_string(a);
    reverse(str.begin(), str.end());
    stringstream stream(str);
    stream >>  a;
    
    string str2;
    str2 = to_string(b);
    reverse(str2.begin(), str2.end());
    stringstream stream2(str2);
    stream2 >>  b;

    int c = a + b;

    string str3;
    str3 = to_string(c);
    reverse(str3.begin(), str3.end());
    stringstream stream3(str3);
    stream3 >>  c;

    cout << c << endl;

    
    return 0;
}
// reverse함수
//벡터를 인자로 넘길 때 주의점 이거 링크달아놓기