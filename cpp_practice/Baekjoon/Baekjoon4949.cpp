#include <iostream>
#include <stack>


using namespace std;

//55 txx
int main(){
    stack<char> s;
    string ss;
    
    while(true){
        getline(cin, ss, '.');
        if(ss == "\0") break; 
        cin.ignore();

        for(char dldm: ss){
            if(s.empty() && dldm == ')') {
                s.push('d');
                break;
            }
            if(s.empty() && dldm == ']'){
                s.push('d');
                break;
            }
            if(dldm == '(' || dldm == '[')
                s.push(dldm);
            else if(dldm == ')' ){
                if(s.top() == '(') s.pop();
                else s.push(dldm);
            }
            else if(dldm == ']'){
                if(s.top() == '[') s.pop();
                else s.push(dldm);
            }
        }
        if(s.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
        while(!s.empty()) s.pop();
    }

    return 0;
}