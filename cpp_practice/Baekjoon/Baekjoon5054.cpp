#include <iostream>

using namespace std;

int main(){

    int t, a, n;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        int small = 99;
        int big = 0;
        for(int j = 0 ; j < n; j++){
            cin >> a;
            if(big < a) big = a;
            if(small > a) { small = a;

        }
        cout << (big-small)*2 << endl;
    }

    return 0;
}
}