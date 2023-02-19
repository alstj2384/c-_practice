#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){

    stack<int> s;
    vector<int> v;
    int n, a;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> a;
        v.push_back(a);
    }// 벡터의 인덱스 순서는 pop되어야 하는 순서

    int low_idx = 0;
    // for(int i = 0 ; i < v.size()-1; i++){
    //     if(v[i+1] == v[i]-1 || v[i] < v[i+1]){
    //         continue;
    //     }
    //     else{
    //         cout << "No" << endl;
    //     }
    // }

    cout << v.size()<<endl;
    return 0;
} //30분시작 + 30분시작


// low index 보다 커도 상관 없지만 작은 게 오면 안 된다
// low index다음 값이 low index-1 초과는 안 된다

//i 다음 값이 더 커도 되고, 1만큼 작아도 됨 최대값을 만나면 그 뒤는 내림차순이어야함
