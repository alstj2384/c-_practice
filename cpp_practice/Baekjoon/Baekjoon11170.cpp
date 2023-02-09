#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int a;
    cin >> a; // ÃÑ ¹Ýº¹È½¼ö
    int count[a] = { 0, };


    for(int i = 0; i < a; i++){
        int x, y;
        cin >> x >> y;
            for(int z = x; z <= y; z++){
                string s = to_string(z);
                for(int j = 0; j < s.length(); j++){
                        if(s[j] == '0') count[i]++;
                }
            }
    }
    for(int i = 0; i < a; i++){
        cout << count[i] << endl;
    }
    return 0;
}