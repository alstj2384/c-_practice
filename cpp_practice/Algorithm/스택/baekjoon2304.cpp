#include <iostream>
#include <algorithm>
#include <stack>

typedef struct{
    int location;
    int height;
} spa;

bool compare(spa a, spa b){
    return (a.height < b.height);
}

using namespace std;

int main(){

    stack<spa> stack;

    int a,b,c;
    cin >> a;
    spa s[a];

    for(int i = 0; i < a; i++){
        cin >> b >> c;
        s[i].location = b;
        s[i].height = c;
    }

    sort(s,s+a,compare);
    int i = 0;
    for(spa elem : s){
        stack.push(elem);
    }

    while(!stack.empty()){
        cout << stack.top().location;
        stack.pop();
    }
    spa pivot, rpivot, lpivot;
    pivot.height = stack.top().height;
    pivot.location = stack.top().location;

    stack.pop();

    if(pivot.height <= stack.top().height && pivot.location > stack.top().location){
        rpivot.height = stack.top().height;
        rpivot.location = stack.top().location;
    };
    return 0;
}