#include <iostream>

using namespace std;

class queue{
    int arr[10000];
    int head;
    int rear;

    public :

        void init(){
            head = 0;
            rear = 0;
        }
        void push(int X){
            arr[rear++] = X;
            cout << arr[rear-1] << endl;
        };
        void pop(){
            if(empty()) cout << -1 << endl;
            cout << arr[head++] << endl;
        };
        void size(){
            cout << rear-head << endl;
        };
        bool empty(){
            if(rear == head) return true;
            return false;
        };
        void front(){
            cout << arr[head] << endl;
        };
        void back(){
            if(empty()) cout << -1 << endl;
            cout << arr[rear] << endl;
        };
};

int main(){
    int a,b ;

    cin >> a ;
    string str;
    queue q;
    for(int i = 0; i < a; i++){
        cin >> str;
        if(str == "push"){
            cin >> b;
            q.push(b);
        }
        else if(str == "front"){
            q.front();
        }
        else if(str == "back"){
            q.back();
        }
        else if(str == "size"){
            q.size();
        }
        else if(str == "empty"){
            cout << q.empty() << endl;
        }
        else if(str == "pop"){
            q.pop();
        }
    }
    return 0;
}