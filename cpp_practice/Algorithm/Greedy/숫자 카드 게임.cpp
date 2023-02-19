#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v;
    vector<int>::iterator it;

    int n,m, a;
    int tmp = 0;

    cin >> n >> m;

    for(int i = 0 ; i < n*m; i++){
        cin >> a;
        v.push_back(a);
    }

    it = v.begin();
    
    for(int j = 0; j < n; j++){
        sort(it, it+m);
        if(tmp < *it) tmp = v[*it];
        it += m;
    }

    // for(int elem: v){
    //     cout << elem ;
    // }

    cout <<tmp << endl;
    return 0;


}//23분 걸림

//반복자 iterator을 사용할 떄, 
// it = v.begin()으로 반복자 위치 초기화,
// it += m으로 반복자 위치 조정 가능
// *it 역참조 기호를 사용해 값에 접근 가능을 알 수 있었다.