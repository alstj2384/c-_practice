#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct alp{
    char a;
    int x;

    
};

bool compare(const alp& a1, const alp& a2){
    return a1.x > a2.x;
}

int main(){
    
    alp Alp[26];

    for(int i = 0; i < 26; i++){
        Alp[i].x = 0;
    }

    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            Alp[str[i]-'A'].a = str[i];
            Alp[str[i]-'A'].x++;
        }
        else{
            char a = toupper(str[i]);
            Alp[toupper(str[i])-'A'].a = toupper(str[i]);
            Alp[toupper(str[i])-'A'].x++;
        }
    }

    sort(Alp, Alp+26, compare);

    if(Alp[0].x == Alp[1].x){
        cout << "?"<<endl;
    }
    else{
        cout << Alp[0].a << endl;
    }
    return 0;
}

// 대문자에서 toupper해도 대문자그대로임

//40분? 이건 ㅗㄴ션에 올려야겠다 ㅅㅂ
