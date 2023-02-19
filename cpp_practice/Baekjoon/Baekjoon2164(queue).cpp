#include <iostream>
#include <deque>

using namespace std;

int main(){
    
    deque<int> dq;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }

    while(dq.size()!=1){
        dq.pop_front();
        dq.push_back(dq[0]);
        dq.pop_front();
    }
    for(int elem : dq){
        cout << elem << endl;
    }
    return 0;
}//10분. 아무래도 벡터와 활용이 비슷해서 쉽게한듯.