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
    Tower myTower; // 1 ????
    Tower seoulTower(100); // 100 ????
    cout << "????? " << myTower.getHeight() << "????" << endl;
    cout << "????? " << seoulTower.getHeight() << "????" << endl;

    return 0;
}