#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v;
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i ++){
        v.push_back(str[i]-'0');
    }


    sort(v.rbegin(), v.rend());
    
    for(int elem : v){
        cout << elem;
        
    }

    return 0;
}//15분, 