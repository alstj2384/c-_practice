#include <iostream>

using namespace std;
//10시 24분시작
//11:49분 다풀음... 
//1시간 25분걸림..

class Array{
    private:
        int R;
        int L;
        int cnt;
        int X;
    
    public :

        Array(int l, int r, int x){
            L = l;
            R = r;
            cnt = 1;
            X = x;
        }

        void change(){
            if(R > L){
                while(R > 1){
                    R--;
                    L++;
                    cnt++;
                    if(cnt >= X) break;
                }
                if(R==1 && cnt != X){
                    L++;
                    cnt++;
                }
            }
            else if(L > R){
                while(L > 1){
                    L--;
                    R++;
                    cnt++;
                    if(cnt >= X) break;
                }
                if(L==1 && cnt != X){
                    R++;
                    cnt++;
                }
            }
            else if(R == 1 && L == 1){
                R++;
                cnt++;

            }
        }

        int ViewCnt(){
            return cnt;
        }
        void ViewRL(){
            cout<< L << "/" << R << endl;
        }
};
int main(){

    int x;
    cin >> x;
    Array array(1,1,x);

    while(array.ViewCnt() < x){
        array.change();
    }

    array.ViewRL();

    return 0;
}
