#include <iostream>

using namespace std;
//10분 + 30분// 총 소요 22분
class knight{
    int x;
    int y;

    public :
        knight(int X, int Y){
            x = X;
            y = Y;
        }

        bool check(int X, int Y){
            if(X < 1 || X > 8) return false;
            if(Y < 1 || Y > 8) return false;
        }

        int move(){
            //(-1, 2) (1,2) (-2, 1) (-2, -1) (2, 1) (2, -1) (-1, -2) (1, -2)
            int cnt = 0;

            if(check(x-1, y+2) != false) cnt ++;
            if(check(x+1, y+2) != false) cnt ++;
            if(check(x-2, y+1) != false) cnt ++;
            if(check(x-2, y-1) != false) cnt ++;
            if(check(x+2, y+1) != false) cnt ++;
            if(check(x+2, y-1) != false) cnt ++;
            if(check(x-1, y-2) != false) cnt ++;
            if(check(x+1, y-2) != false) cnt ++;

            return cnt;
        }

};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    knight k(1,1);
    
    cout << k.move() << endl;

    return 0;
}