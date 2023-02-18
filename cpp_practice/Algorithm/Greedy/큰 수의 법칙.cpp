#include <iostream>
#include <vector>
#include <algorithm>   
using namespace std;

int main(){

    int N, M, K, a; //M번 더하기., K번 반복가능
    cin >> N >> M >> K;
    vector<int> v;
    for(int i = 0; i < N; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.rbegin(), v.rend());
    //정렬된 요소의 1,2번쨰 값이 같으면 그냥 반복
    //아니라면 0번1번 반복

    int sum = 0;
    bool flag = false;
    
    for(int i = 0; i < M;){
        if(v[0] == v[1]){
            sum += v[0];
            i++;
        }
        else if(v[0] > v[1]){
            if(flag == false){
                for(int j = 0 ; j < K; j++){
                    sum += v[0];
                    i++;
                }flag = true;
            }
            else if(flag == true){
                    sum += v[1];
                    i++;
                    flag = false;
            }
        }
    }

    cout << sum << endl;


    return 0;
}//22분 걸림(문제 읽기 시작부터)