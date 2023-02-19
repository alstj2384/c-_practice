#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> v;
    stack<int> s;

    v.push_back(1);
    v.push_back(2);

    s.push(1);
    s.push(2);

    if(v == s){}
    return 0;
}// 벡터에 담긴 정보와 스택에 담긴 정보가 완전히 같을 때 부등호를 사용가능한지