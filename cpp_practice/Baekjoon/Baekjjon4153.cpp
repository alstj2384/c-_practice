#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, c;
    while(true){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0){
            break;
        }
        if(pow(a,2)+pow(b,2)==pow(c,2)){
            cout << "right" << endl;
        }
        else if(pow(b,2)+pow(c,2)==pow(a,2))
            cout << "right" << endl;
        else if(pow(a,2)+pow(c,2)==pow(b,2))
            cout << "right" << endl;
        else cout << "wrong" << endl;
        
    }


    return 0;
}