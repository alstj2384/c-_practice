#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;
    int a;
    vector<int> v;
    for(int i = 0; i < N; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    for(int elem : v){
        cout << elem << endl;
    }
    return 0;
}