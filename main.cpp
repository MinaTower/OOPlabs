#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

enum brand { Mercedes = 0, Nissan = 9, Mitsubishi = 16, Toyota = 27, BMW = 34 };

class car {
protected:
	int model;
public:
	car(){ model = 0; };
	virtual ~car() {};
};

class Mercedes_c:public car {
public:
	Mercedes_c(int a) { model = a; };
	virtual ~Mercedes_c() {
		cout << "Mercedes " << model << endl;
	};
};
class Nissan_c :public car {
public:
	Nissan_c(int a){ model = a; };
	virtual ~Nissan_c() {
		cout << "Nissan " << model << endl;
	};
};
class Mitsubishi_c :public car {
public:
	Mitsubishi_c(int a) { model = a; };
	virtual ~Mitsubishi_c() {
		cout << "Mitsubishi " << model << endl;
	};
};
class Toyota_c :public car {
public:
	Toyota_c(int a) { model = a; };
	virtual ~Toyota_c() {
		cout << "Toyota " << model << endl;
	};
};
class BMW_c :public car {
public:
	BMW_c(int a) { model = a; };
	virtual ~BMW_c() {
		cout << "BMW " << model << endl;
	};
};


int main()
{
	ifstream ifile;
	ifile.open("cars.txt");
	//cout << ifile.is_open();
	string brands = "Mercedes Nissan Mitsubishi Toyota BMW";
	vector<car*> cars;
	string my_brand;
	int my_model;
	for (int i = 0; i < 10; i++) {
		ifile >> my_brand >> my_model;
		switch (int(brands.find(my_brand))) {
		case 0:
			cars.push_back(new Mercedes_c(my_model));
			continue;
		case 9:
			cars.push_back(new Nissan_c(my_model));
			continue;
		case 16:
			cars.push_back(new Mitsubishi_c(my_model));
			continue;
		case 27:
			cars.push_back(new Toyota_c(my_model));
			continue;
		case 34:
			cars.push_back(new BMW_c(my_model));
			continue;
		}
	};
	for (int i = 0; i < cars.size(); i++) {
		delete cars[i];
	};
	
	ifile.close();
	return 0;
}
