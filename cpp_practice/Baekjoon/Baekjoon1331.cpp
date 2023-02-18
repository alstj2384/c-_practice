#include <iostream>
#include <cstring>


using namespace std;
//1시 44분시작
//2시 20분까지 해보다가 막힘
int main(){

    string strArr[36] = {""};

    int idx;
    string str;
    
    for(int j = 0 ; j < 36; j++){
        cin >> str;
        strArr[j] = str;
        for(int i = 1 ; i < j; i++){
            if(strArr[i].compare(str) == 0){//strcmp는 참일경우 0을 반환
                cout << "Invalid" << endl;
            }
        }
    }
    cout << "Valid" << endl;
    return 0;
}

//(strArr[i].compare(str) !! idea 1;

//string 을 비어있는 문자열로 만들겠답시고 0을 넣었는데, 빈 칸 초기화는 ""으로 해야함













