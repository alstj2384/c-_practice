#include <iostream>

using namespace std;


int main(){

    
    int a;
    cin >> a;
    int cnt = 0;
    for(int i = 0 ; i < a; i++){
        bool Exist[26] = { 0, };
        string str;
        cin >> str;
        for(int j = 0 ; j < str.length(); j++){
            if(Exist[str[j]-'a'] == false){
                Exist[str[j]-'a'] = true;
            }
            else if(Exist[str[j]-'a'] == true && str[j] != str[j-1]){
                cnt++;
                break;
            }
        }
    }

    cout << a-cnt << endl;

    return 0;
}