#include <iostream>

using namespace std;

class Queue{
    private : 
        int head;
        int tale;
        int arr[10000];
    
    public :
        void init(){
            head = 0;
            tale = 0;
        }
        void push(int X){
            arr[tale++] = X;
        }
        int pop(){
            if(empty()) return -1;
            return arr[head++];
        }
        int size(){
            return tale-head;
        }
        bool empty(){
            if(size()==0) return true;
            return false;
        }
        int front(){
            if(empty()){
                return -1;
            }
            return arr[head];
        }
        int back(){
            if(empty()){
                return -1;
            }
            return arr[tale-1];
        }
};

int main(){
 ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b;
    cin >> a;
    Queue q;
    string str;
    q.init();
    for(;a--;){
        cin >> str;
        if(str == "push"){
            cin >> b;
            q.push(b);
        }
        else if(str == "front"){
            cout << q.front() << '\n';
        }
        else if(str == "back"){
            cout << q.back() << '\n';
        }
        else if(str == "empty"){
            cout << q.empty() << '\n';
        }
        else if(str == "pop"){
            cout << q.pop() << '\n';
        }
        else if(str == "size"){
            cout << q.size() << '\n';
        }

    }
    return 0;
}