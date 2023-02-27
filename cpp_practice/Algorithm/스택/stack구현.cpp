#include <iostream>
#define MAX 100000

using namespace std;

class Stack{
    private:
        char arr[MAX];
        int top;

    public :
        void init(){
            top = -1;
        }

        void pop(){
            if(is_empty()){
                cout << "스택이 비었습니다" << endl;
            }
            top--;
        };
        void push(char c){
            if(is_full()){
                cout << "스택이 꽉 찼습니다" << endl;
            }
            arr[++top] = c;
        };
        bool is_full(){
            if(top == MAX-1) return true;
            return false;
        };
        bool is_empty(){
            if(top == -1) return true;
            return false;
        };

        char peek(){
            return arr[top];
        };

};
int main(){

    Stack s;
    s.init();

    int a;
    cin >> a;
    string str;
    int cnt = 0;

    for(int i = 0; i < a; i++){
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            if(str[j]=='A' && s.peek() != 'A'){
                s.push('A');
            }
            else if(str[j]=='A' && s.peek() == 'A'){
                s.pop();
            }
            else if(str[j]=='B' && s.peek() !='B'){
                s.push('B');
            }
            else if(str[j]=='B' && s.peek() == 'B'){
                s.pop();
            }
        }if(s.is_empty()) cnt++;
        
        while(!s.is_empty()){
            s.pop();
        }
    }

    cout << cnt << endl;
    return 0;
}