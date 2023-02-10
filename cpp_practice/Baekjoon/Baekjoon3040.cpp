#include <iostream>
#include <vector>

using namespace std;

int main(){

    // 모든 합을 구하고 답은 어차피 하나이므로 모든 합 - 100 을 한 값이
    // 두 요소의 합중 하나임.
    vector<int> v;
    int sum = 0;
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
            }
        }
    }

    for(int elem : v){
        cout << elem << endl;
    }
    return 0;
}