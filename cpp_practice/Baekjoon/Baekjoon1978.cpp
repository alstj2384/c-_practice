#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, cnt;
    cin >> a;
    int sum = 0;
    for(int i = 0 ; i < a; i++){
        cin >> b;
        cnt = 0;
        if(b == 1 ) continue;
        if(b % 2 != 0 || b == 3 || b == 5 || b || 7) cnt++;
        if (b % 5 != 0 || b == 5 || b == 2 || b == 3 || b == 7) cnt++;
        if (b % 7 != 0 || b == 7 || b == 2 || b == 3 || b == 5) cnt++;
        if (b % 3 != 0 || b == 3 || b == 2 || b == 5 || b == 7) cnt++;

        if(cnt == 4) sum++;
    }

    cout << sum << endl;
    return 0;
}