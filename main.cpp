#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

enum class brand { Mercedes = 0, Nissan = 9, Mitsubishi = 16, Toyota = 27, BMW = 34 };

class Car {
public:
	Car(int model) { m_model = model; };//
	virtual void print() =0;
	virtual ~Car() {};
protected:
	int m_model;
};

class Mercedes_c : public Car {
public:
	Mercedes_c(int model):Car(model) {};
	virtual void print() {
		cout << "Mercedes " << m_model << endl;
	};
	virtual ~Mercedes_c() {
		cout << "Mercedes " << m_model << endl;
	};
};
class Nissan_c :public Car {
public:
	Nissan_c(int& model) :Car(model) {};
	virtual void print() {
		cout << "Nissan " << m_model << endl;
	};
	virtual ~Nissan_c() {
		cout << "Nissan " << m_model << endl;
	};
};
class Mitsubishi_c :public Car {
public:
	Mitsubishi_c(int& model) :Car(model) {};
	virtual void print() {
		cout << "Mitsubishi " << m_model << endl;
	};
	virtual ~Mitsubishi_c() {
		cout << "Mitsubishi " << m_model << endl;
	};
};
class Toyota_c :public Car {
public:
	Toyota_c(int& model) :Car(model) {};
	virtual void print() {
		cout << "Toyota " << m_model << endl;
	};
	virtual ~Toyota_c() {
		cout << "Toyota " << m_model << endl;
	};
};
class BMW_c :public Car {
public:
	BMW_c(int& model) :Car(model) {};
	virtual void print() {
		cout << "BMW " << m_model << endl;
	};
	virtual ~BMW_c() {
		cout << "BMW " << m_model << endl;
	};
};


int main()
{
	ifstream ifile;
	ifile.open("cars.txt");
	//cout << ifile.is_open();
	string brands = "Mercedes Nissan Mitsubishi Toyota BMW";
	vector<Car*> cars;
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
