#include <iostream>
#include <vector>
#include <algorithm>   
using namespace std;

int main(){

    int N, M, K, a; //M�� ���ϱ�., K�� �ݺ�����
    cin >> N >> M >> K;
    vector<int> v;
    for(int i = 0; i < N; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.rbegin(), v.rend());
    //���ĵ� ����� 1,2���� ���� ������ �׳� �ݺ�
    //�ƴ϶�� 0��1�� �ݺ�

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
}//22�� �ɸ�(���� �б� ���ۺ���)