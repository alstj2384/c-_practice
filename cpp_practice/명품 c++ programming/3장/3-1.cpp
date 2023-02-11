#include <iostream>
using namespace std;
 
class Tower{
    private :
        int height;

    public :
        int getHeight(){
            return this->height;
        }
        Tower(){
        height = 1;
        }
        Tower(int a){
            height = a;
        }
};


int main() {
    Tower myTower; // 1 미터
    Tower seoulTower(100); // 100 미터
    cout << "높이는 " << myTower.getHeight() << "미터" << endl;
    cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;

    return 0;
}