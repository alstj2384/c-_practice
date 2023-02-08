#include <iostream>

using namespace std;


int main(){
    int a;
    int list[10][2] = {0 ,};
    int tmp = 0;
    for(int i = 0; i < 10; i++){
        cin >> a;
        for(int j = 0; j < 10; j++){
            if(list[j][0] == a) {
                list[j][1]++; 
                break;
            }
            else if(list[j][0] == 0){
                list[j][0] = a;
                list[j][1]++;
                break;
            }
        }
    }
    for(int i = 0; i< 10; i++){
        tmp = tmp + list[i][0] * list[i][1];
    }
        cout << tmp/10 << endl;
    


    for(int i = 0; i < 10 ; i++){
        for(int j =0; j < 9; j++){
            if(list[j][1] < list[j+1][1]){
                tmp = list[j+1][1];
                list[j+1][1] = list[j][1];
                list[j][1] = tmp;

                tmp = list[j+1][0];
                list[j+1][0] = list[j][0];
                list[j][0] = tmp;
                if(list[j+1][1]==0) break;
            }
        }
    }

    cout << list[0][0]<<endl; 

    return 0;
}