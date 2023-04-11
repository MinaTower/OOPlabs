#define _CRTDBG_MAP_ALLOC
#include<crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;
using namespace std;

enum book_type_interpretator { technical = 1, fiction};//

class book {
private:
    const string m_author;//const
    const string m_title;
    book_type_interpretator m_book_type;//private
public:
    book(const string& author, const string& title, book_type_interpretator book_type) :
        m_author(author), m_title(title), m_book_type(book_type)
    {
        //if ((author == string(" ")) || (title == string(" ")) || (book_type == 3)); {
        //    cout << "incorrect input. Check the information <author, title, type<technical/fiction>>: ";
        //}//iskluch?
    };//проверка знач типа

    book_type_interpretator get_type() const { return m_book_type; };
};

void type_statistic_with_switch(const vector<book>& lib) {
    int t_col = 0;
    int h_col = 0;
    for (int i = 0; i < lib.size(); i++){
        switch (lib[i].get_type())
        {
        case 1:
            t_col += 1;
            continue;
        case 2:
            h_col += 1;
            continue;
        };
    };
    cout << "There are " << t_col << " technical books and " << h_col << " fiction books finded by type_statistic_with_switch function" << endl;
};
void type_statistic_with_if(const vector<book>& lib) {
    int t_col = 0;
    int h_col = 0;
    for (int i = 0; i < lib.size(); i++) {
        if (lib[i].get_type() == 1) { t_col += 1; }
        else { h_col += 1; };
    };
    cout << "There are " << t_col << " technical books and " << h_col <<" fiction books finded by type_statistic_with_if function" << endl;
};

int main()
{
    vector<book> library;
    book b1("Tолстой", "Война и мир", fiction);
    book b2("Достоевский", "Преступление и наказание", fiction);//  fiction
    book b3("Роулинг", "Гарри Поттер", fiction);
    book b4("Рузанова", "Расчёт электрических нагрузок", technical);
    book b5("Tолстой", "Война и мир", fiction);
    book b6("Савин", "Электротехника", technical);
    book b7("Щерба", "Часодеи", fiction);
    book b8("Галичский", "Учебник языка Эсперанто", technical);
    book b9("Боуэн", "Уличный кот по имени Боб", fiction);
    book b10("Хиз", "Создано чтобы прилипать", fiction);
    library.push_back(b1);
    library.push_back(b2);
    library.push_back(b3);
    library.push_back(b4);
    library.push_back(b5);
    library.push_back(b6);
    library.push_back(b7);
    library.push_back(b8);
    library.push_back(b9);
    library.push_back(b10);
    type_statistic_with_switch(library);
    type_statistic_with_if(library);
    
    return 0;
};
