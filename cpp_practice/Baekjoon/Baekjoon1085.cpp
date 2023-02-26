#include <iostream>

using namespace std;

int compare(int x, int w){
    if(w-x < x) return w-x;
    return x;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int result;
    result = (compare(x,w) < compare(y,h)) ? compare(x,w) : compare(y,h);
    cout << result << endl;

    return 0;
}