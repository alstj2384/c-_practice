#include <iostream>

using namespace std;


class Book {
    string *pTitle; // 제목
    int *pPrice;    // 가격
    int *pPages;    // 페이지수

    static int totalBooks;
    static int currentBooks;

public:
    // 생성자는 오직 하나만 작성하라. (복사생성자는 예외)
    // 필요한 경우 출력결과를 참조하여 매개변수를 적절히 수정하라.
    Book(string title, int price, int pages);
    Book(const Book& b);
    ~Book();
    Book& show();
    Book& set(const string& title);
    static void printBookCount();
};

int Book::totalBooks = 0;
int Book::currentBooks = 0;
/******************************************************************************
 * class Book implementation
 ******************************************************************************/

// 복사생성자를 제외한 다른 생성자는 작성하지 마라.
Book::Book(string title = "no_title", int price = 0, int pages = 1) {
    pTitle = new string(title);
    pPrice = new int(price);
    pPages = new int(pages);
    totalBooks++;
    currentBooks++;
}

// 괄호를 넣으면 할당과 동시에 괄호 내용 초기화

Book::Book(const Book& b){
    pTitle = new string(*b.pTitle);
    pPrice = new int(*b.pPrice);
    pPages = new int(*b.pPages);

    cout << "Book(const Book& b): ";
    show();
    totalBooks++;
    currentBooks++;
}

Book::~Book(){
    currentBooks--;
}
Book& Book::show() {
    cout << "title: " << *pTitle << ", price: " << *pPrice << ", pages: " << *pPages << endl;
    return *this;
}

Book& Book::set(const string& title) {
    *pTitle = title;
    *pPrice += 100;
    *pPages += 1;
    return *this;
}

void Book::printBookCount(){
    cout << "totalBooks: "<< totalBooks << ", currentBooks: " << currentBooks<<endl;
    cout << "--------------------------" << endl;
}

/******************************************************************************
 * Global functions
 ******************************************************************************/
void defParam() {
    Book no_title;
    Book a("A");
    Book b("B", 10000);
    Book c("C++ Programming", 30000, 696);
    no_title.show();
    a.show();
    b.show();
    c.show();
}

void copyConst() {
    Book a("A");
    a.show();
    Book b = a;
    b.set("B").show();
    a.show();
}

void staticMembers() {
    Book::printBookCount();
    Book *books = new Book[10];
    Book::printBookCount();

    delete[] books;
    Book::printBookCount();

    books = new Book[5];
    Book::printBookCount();

    delete[] books;
    Book::printBookCount();
}

/******************************************************************************
 * main function
 ******************************************************************************/

string menuStr =
"*************** Main Menu ****************\n"
"* 0.Exit 1.defParam 2.copyConst 3.static *\n"
"******************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: defParam();      break;
        case 2: copyConst();     break;
        case 3: staticMembers(); break;
        }
    }
    cout << "Good bye!!" << endl;
}