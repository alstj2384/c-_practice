#include <iostream>
#include <vector>

using namespace std;


int classify(int &r_iter, int &cnt, int &k){
    while(k-r_iter>=0){
        if(k - r_iter < 0){
            return 0;
        }else if(k - r_iter >= 0){
            cnt++;
            k= k-r_iter;
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int a;
    int cnt = 0;
    int *b = &cnt;
    int *c = &k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    vector<int>::reverse_iterator r_iter = v.rbegin();
    for(; r_iter != v.rend(); r_iter++){
        classify(*r_iter, *b, *c);
    }
    cout << cnt << endl;

   
    return 0;
}

//���͸� Ȱ���Կ� �־ ��ȯ������ iterator �ñ����� ������ 35�к��� 5������ ã�ƺ�
//���Ϳ� ������� for���� ���ؼ�

//25�� ����/ �����Ϳ� ���ؼ� �ñ�����

 //���� ��� for��
    // for(int elem : v){
    //     cout << "���� : "<< elem << endl;
    // }