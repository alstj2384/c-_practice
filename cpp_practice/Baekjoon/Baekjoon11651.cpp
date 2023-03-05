#include <iostream>
#include <algorithm>
#include <vector>

struct coor{
    int x;
    int y;
};


bool compare(const coor& a1, const coor& a2){
    if(a1.y == a2.y){
        return a1.x < a2.x;
    }
    else {
        return a1.y < a2.y;
    }
}


using namespace std;

int main(){

    vector<coor> v;
    int a, b, c;
    cin >> a;
    coor coo;
    for(;a--;){
        cin >> b >> c;
        coo.x = b;
        coo.y = c;
        v.push_back(coo);
    }

    sort(v.begin(), v.end(), compare);
    for(coor elem : v){
        cout << elem.x << elem.y << endl;
    }

    return 0;
}