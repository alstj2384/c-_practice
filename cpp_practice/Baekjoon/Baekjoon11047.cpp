#include <iostream>
#include <vector>

using namespace std;


int classify(int &r_iter, int &cnt, int &k){
    while(k-r_iter>=0){
        if(k - r_iter < 0){
            return 0;
        }else if(k - r_iter >= 0){
            cnt++;
            k= k-r_iter;
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int a;
    int cnt = 0;
    int *b = &cnt;
    int *c = &k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    vector<int>::reverse_iterator r_iter = v.rbegin();
    for(; r_iter != v.rend(); r_iter++){
        classify(*r_iter, *b, *c);
    }
    cout << cnt << endl;

   
    return 0;
}

//벡터를 활용함에 있어서 순환참조와 iterator 궁금증을 가지고 35분부터 5분정도 찾아봄
//벡터와 범위기반 for문에 대해서

//25분 남음/ 포인터에 대해서 궁금해짐

 //범위 기반 for문
    // for(int elem : v){
    //     cout << "원소 : "<< elem << endl;
    // }