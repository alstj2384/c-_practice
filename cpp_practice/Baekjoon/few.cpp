#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b,m;
    cin >> n;
    vector<int> v,k;

    for(int i = 0; i < n; i++){
        cin >>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> b;
        k.push_back(b);

        cout << binary_search(v.begin(), v.end(), b) << '\n';
    }

    return 0;
}//ios_base::sync_with_stdio(0); cin.tie(0);