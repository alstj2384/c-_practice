#include <bits/stdc++.h>

using namespace std;

int main(){
    char a[100];
    char b = '.';
    stack<int> s1; // ()
    stack<int> s2; // []
    while(true){
        cin.getline(a ,100 ,'.');
        bool flag1 = true,flag2 = true;
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
        for(int i = 0; i < sizeof(a); i++){
            if(a[i] == '(') s1.push(1);
            else if(a[i] == ')'){
                if(s1.empty() || !s2.empty()) {
                    cout << "no" << endl;
                    flag1 = false;
                    break;
                }
                else s1.pop();
            }
            if(a[i] == '[') s2.push(1);
            else if(a[i] == ']'){
                if(s2.empty() || !s1.empty()) {
                    cout << "no" << endl;
                    flag2 = false;
                    break;
                }
                else s2.pop();
            }
        }
        if(flag1 && flag2) cout << "yes" << endl;
        if(a[0] == b) return 0;
    }
    return 0;
}