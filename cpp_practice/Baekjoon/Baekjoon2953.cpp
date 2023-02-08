#include <iostream>

using namespace std;

int main(){

    int high = 0;
    int list[4];
    int idx;
    for(int i = 0; i < 5; i ++){
        int tmp = 0;
        for(int j = 0; j < 4; j++){
            cin >> list[j];
            tmp += list[j];
        }
        if(high < tmp) { high = tmp; idx = i+1;}
    }
    
    cout << idx <<" "<< high << endl;
    return 0;
}