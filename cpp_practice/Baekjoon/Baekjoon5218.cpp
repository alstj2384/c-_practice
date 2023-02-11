#include <iostream>

using namespace std;


int main(){
    string str, str2;
    int n = 0;
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> str >> str2;
        cout << "Distances: " ;
            for(int k = 0; k < str.length(); k++){
                int x = str[k]; int y = str2[k];
                if(x > y) cout << (y+26)-x << " ";
                else if(y >= x) cout << y-x << " ";
            }cout << endl;
    }
    return 0;
}