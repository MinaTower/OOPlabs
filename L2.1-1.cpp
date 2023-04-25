#define _CRTDBG_MAP_ALLOC
#include<crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;
using namespace std;

enum book_type_interpretator { technical = 1, fiction };

class Book {
public:
    Book(const string& author, const string& title, book_type_interpretator book_type) :
        m_author(author), m_title(title), m_book_type(book_type)
    {
    };
    ~Book() {};
    book_type_interpretator get_type() const { return m_book_type; };
private:
    const string m_author;//const
    const string m_title;
    book_type_interpretator m_book_type;//private
};

class Library {
public:
    void add_book(const string& author, const string& title, book_type_interpretator book_type) {
        if (author.empty() || title.empty()) {
        string n_author, n_title, n_type;
            cout << "Wrong values. Input the information again <author, title, type<technical/fiction>>: ";
            cin >> n_author >> n_title >> n_type;
            cout << endl;
            book_type_interpretator n_b_type;
            if (n_type == "fiction") { n_b_type = fiction; }
            else { n_b_type = technical; };
            library_collection.push_back(Book(n_author, n_title, n_b_type));
        }
        else { library_collection.push_back(Book(author, title, book_type)); };

    };
    void type_statistic_with_switch() {
        int t_col = 0;
        int h_col = 0;

        for (const Book& book : library_collection)
        {
            switch (book.get_type())
            {
            case 1:
                t_col += 1;
                continue;
            case 2:
                h_col += 1;
                continue;
            };
        }
        cout << "There are " << t_col << " technical books and " << h_col << " fiction books finded by type_statistic_with_switch function" << endl;
    };
    void type_statistic_with_if() {
        int t_col = 0;
        int h_col = 0;
        for (const Book& book:library_collection) {
            if (book.get_type() == 1) { t_col += 1; }
            else { h_col += 1; };
        };
        cout << "There are " << t_col << " technical books and " << h_col << " fiction books finded by type_statistic_with_if function" << endl;
    };
private:
    vector<Book> library_collection;
};

int main()
{
    Library Central;

    Central.add_book("Tолстой", "Война и мир", fiction);
    Central.add_book("Достоевский", "Преступление и наказание", fiction);
    Central.add_book("Роулинг", "Гарри Поттер", fiction);
    Central.add_book("Рузанова", "Расчёт электрических нагрузок", technical);
    Central.add_book("Tолстой", "Война и мир", fiction);
    Central.add_book("Савин", "Электротехника", technical);
    Central.add_book("Щерба", "Часодеи", fiction);
    Central.add_book("Галичский", "Учебник языка Эсперанто", technical);
    Central.add_book("Боуэн", "Уличный кот по имени Боб", fiction);
    Central.add_book("Хиз", "Создано чтобы прилипать", fiction);
    Central.add_book("","",fiction);
    Central.type_statistic_with_switch();
    Central.type_statistic_with_if();

    return 0;
};
