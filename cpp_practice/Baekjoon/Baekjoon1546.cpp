#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int b;
    int tmp = 0;
    vector<double> v;
    double sum = 0;

    int a;
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> b;
        if(tmp < b) tmp = b;
        v.push_back(b);
    }


    for(double elem : v){
        if(elem <= tmp){
            sum += elem/tmp*100;
        }
        else if(elem == tmp){
            sum += elem;
        }
    }
    sum = sum/a;
    cout.precision(15);
    cout << fixed;

    cout << sum << endl;
    return 0;
}//20분 걸렸고, precision()함수 기억해놓기