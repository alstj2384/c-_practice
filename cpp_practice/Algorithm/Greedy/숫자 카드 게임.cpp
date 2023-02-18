#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v;
    vector<int>::iterator it;

    int n,m;
    int a;
    cin >> n >> m;
    for(int i = 0 ; i < n*m; i++){
        cin >> a;
        v.push_back(a);
    }
    int tmp = 0;
    it = v.begin();
    for(int j = 0; j < n; j++){
        sort(it, it+m);
        if(tmp < *it) tmp = v[*it];
        it += m;
    }

    for(int elem: v){
        cout << elem ;
    }

    cout <<tmp << endl;
    return 0;


}//23분 걸림