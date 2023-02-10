#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> w;
    vector<int> k;
    int a;
    
    for(int i = 0; i < 10; i++){
        cin >> a;
        w.push_back(a);
    }
    for(int i = 0; i < 10; i++){
        cin >> a;
        k.push_back(a);
    }

    sort(w.rbegin(), w.rend());
    sort(k.rbegin(), k.rend());

    cout << w[0] + w[1] + w[2] << " " << k[0] + k[1] + k[2] << endl;
    return 0;
}

//7Ка