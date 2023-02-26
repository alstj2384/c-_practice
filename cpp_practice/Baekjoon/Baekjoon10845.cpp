#include <iostream>

using namespace std;

struct Queue{
    int head;
    int rear;
    int arr[10000];

    public :
        void init(){
            head = 0;
            rear = -1;
        }
        int push(int X){
            if(empty()){
                return -1;
            }
            arr[++rear] = X;
        };

        int pop(){
            return arr[head++];
        };

        int size(){
            return rear-head+1;
        };

        bool empty(){
            return (rear-head == -1);
        };

        int front(){
            return arr[head];
        }

        int back(){
            return arr[rear];
        }

};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, a;
    cin >> n;
    Queue q;
    string str;
    q.init();
    for(;n--;){
        cin >> str;
        if(str == "push"){
            cin >> a;
            q.push(a);
        }
        if(str == "pop"){
            cout << q.pop() << '\n';
        }
        if(str == "size"){
            cout << q.size() << '\n';
        }
        if(str == "empty"){
            cout << q.empty() << '\n';
        }
        if(str == "front"){
            cout << q.front() << '\n';
        }
        if(str == "back"){
            cout << q.back() << '\n';
        }
    }
    return 0;
}