#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v;
    int sum = 0;
    int flag = false;
    int a;
    for (int i = 0; i < 9; i++){
        cin >> a;
        v.push_back(a);
        sum += v[i];
    }

    for(int i = 0; i < 8;i++){
        for(int j = i+1; j < 9; j++){
            if(*(v.begin()+i) + *(v.begin()+j) == sum-100){
                v.erase(v.begin()+i);
                v.erase(v.begin()+(j-1));
                flag = true;
                break;
            }
        }if(flag == true) break;
    }

    // 답이 맞는 경우 for문을 탈출을 염두에 두지 않았었음
    // 추가로 2중 또는 3중 for문의 탈출 방식으로 flag방식을 알아냄.

    sort(v.begin(), v.end());

    for(int elem : v){
        cout << elem << endl;
    }
    return 0;
}

// 40 -> 11 (29min)