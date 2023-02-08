#include <iostream>
#include <string.h>

using namespace std;


int main(){
    int a;
    cin >> a;
    string print[a];

   for(int i = 0; i< a; i++){
        int j;


        
        string str;

        cin >> j >> str;
        str.erase(j-1,1);
        print[i] = str;
   }

    for(int i = 0 ; i < a; i++){
        cout << print[i] << endl;
    }
    return 0;
}