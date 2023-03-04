#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<char> s;

    int a;
    bool flag = true;
    string str;
    cin >> a;
    for(;a--;){
        cin >> str;
        for(int i = 0; i < str.length(); i++){
            if(str[i]=='('){
                s.push('(');
            }
            else if(str[i]==')'){
                if(s.empty()) {
                    flag = false;
                    break;
                }
                else s.pop();
            }
        }
        if(s.empty() && flag) cout << "YES" << '\n';
        else if(!flag || !s.empty()) cout << "NO" << '\n';

        while(!s.empty()) s.pop();
        flag = true;
    }


    return 0;
}