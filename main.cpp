#include <iostream>
#include<vector>
#include<typeinfo>

using namespace std;


int get_random_int() {
    static int seed = 0;
    seed++;
    return seed;
};

class Class1 {
public:
    Class1() { inf1 = get_random_int(); };
    Class1(int copyed_int) {inf1 = copyed_int; };

    virtual ~Class1() {};
    virtual Class1* my_copy() {
        return new Class1(inf1);
    };
private:
    int inf1;
};
class Class2: public Class1 {
public:
    Class2() { inf2 = get_random_int(); };
    Class2(int copyed_int) { inf2 = copyed_int; };
    virtual ~Class2() {};
    virtual Class1* my_copy() {
        return new Class2(inf2);
    };
private:
    int inf2;
};

int main()
{
    Class1* a1 = new Class1();
    Class1* a2 = new Class2();
    Class1* a3 = new Class1();

    vector<Class1*> db1;
    db1.push_back(a1->my_copy());
    db1.push_back(a2->my_copy());
    db1.push_back(a3->my_copy());

    for (int i = 0; i < db1.size(); i++) { cout << typeid(*(db1[i])).name() << endl; };

    delete a1;
    delete a2;
    delete a3;
    for (int i = 0; i < db1.size(); i++) { delete db1[i]; };
    db1.clear();

    return 0;
};
