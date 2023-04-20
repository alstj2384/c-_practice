#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Container {
    private:
        string title; // 컨테이너 타이틀
        char *author; // 컨테이너 작성자 이름 (동적 할당)
        int size; // 컨테이너에 저장된 정수 배열 크기
        int *arr; // 정수를 저장하는 배열 (동적 할당)
    public:
        void display();
        Container(string title, char *author, 
        int size, int *arr);
        ~Container();
        void replace_subtitle(string from, string to);
        void replace_first_last();
};

Container::Container(string title, char *author, 
        int size, int *arr){

        cout << "Container 생성자 호출" << endl;
        this->size = size;
        this->title = title;

        this->author = new char[strlen(author+1)];
        strcpy(this->author, author);

        this->arr = new int[size];
        for(int i = 0; i < size; i++){
            this->arr[i] = arr[i];
        }

        this->display();
}

void Container::display(){  
    cout << "title:" << title << "," << endl;
    cout << "author:" << author << ", size:" << size << "\n";
    cout << "arr[] = " ;

    for(int i = 0; i < size; i++){
        cout << " " << arr[i];
    }
    cout << endl;
    cout << endl;
}

Container::~Container(){
    cout << "Container 소멸자 호출" << endl;
    display();
    delete [] arr;
    delete [] author;
}
// 여기에 Container 클래스 멤버 함수들을 구현할 것

void Container::replace_subtitle(string from, string to){
    
    while(title.find(from) != -1)
    title.replace(title.find(from), from.length(), to); // 별! 외워두기
    display();
}

void Container::replace_first_last(){
    int fidx = title.find(' ');
    string a = title.substr(0, fidx);

    int ridx = title.rfind(' ');
    string b = title.substr(ridx+1, title.length());

    if(fidx == -1) {
        display();
        return;
    };
    title.replace(0, title.length()-(title.length()-fidx), b);
    title.replace(ridx, title.length()-(title.length()-ridx), a);
    display();
}
int main() {
 string title("First");
 char author[] = "Chosun Universty";
 int arr[5] = { 1, 2, 3, 4, 5 };
 Container c(title, author, 5, arr);
 
 cout << "제목에서 \"title\" 단어를 \"name\" 단어로 모두 바꿉니다." << endl;
 c.replace_subtitle("title", "name");
 cout << "제목의 첫 단어와 마지막 단어의 위치를 바꿉니다." << endl;
 c.replace_first_last();
}