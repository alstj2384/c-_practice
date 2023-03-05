#include <iostream>
#include <stack>


using namespace std;

int main(){
    stack<int> s;
    int a,b, sum = 0;
    cin >>a;
    for(;a--;){
        cin >> b;
        if(b!=0)s.push(b);
        else s.pop();
    }

    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum << endl;
    return 0;
}