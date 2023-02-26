#include <iostream>
#include <queue>


using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    queue<int> q;
    int arr[1000] = {0,};
    int n, k;
    cin >> n >> k;

    for(int i = 1 ; i < n+1; i++){
        q.push(i);
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 1; j < k; j++){
            q.push(q.front());
            q.pop();
        }
        arr[i]= q.front();
        q.pop();
    }

    cout << "<" << arr[0];
    int i = 1;
    while(true){
        cout << ", ";
        cout << arr[i++];
        if(i == n) break;
    }
    cout << ">";
    return 0;
}