#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Container {
    private:
        string title; // �����̳� Ÿ��Ʋ
        char *author; // �����̳� �ۼ��� �̸� (���� �Ҵ�)
        int size; // �����̳ʿ� ����� ���� �迭 ũ��
        int *arr; // ������ �����ϴ� �迭 (���� �Ҵ�)
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

        cout << "Container ������ ȣ��" << endl;
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
    cout << "Container �Ҹ��� ȣ��" << endl;
    display();
    delete [] arr;
    delete [] author;
}
// ���⿡ Container Ŭ���� ��� �Լ����� ������ ��

void Container::replace_subtitle(string from, string to){
    
    while(title.find(from) != -1)
    title.replace(title.find(from), from.length(), to); // ��! �ܿ��α�
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
 
 cout << "���񿡼� \"title\" �ܾ \"name\" �ܾ�� ��� �ٲߴϴ�." << endl;
 c.replace_subtitle("title", "name");
 cout << "������ ù �ܾ�� ������ �ܾ��� ��ġ�� �ٲߴϴ�." << endl;
 c.replace_first_last();
}