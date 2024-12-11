#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Publication {
protected:
	string namebook;
	float pricebook;
};

class sales {
public:
	float arr[3] = { 10, 11, 12 };
};

class book :Publication, sales {
	int numpages;
public:

	void getdata() {
		cout << "введите название книги" << endl;
		cin >> namebook;
		cout << "введите количество страниц" << endl;
		cin >> this->numpages;

	}
	void putdata() {
		cout << "название книги: " << namebook << endl;
		cout << "продажи книг за последние три месяца: " << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;
		cout << "количество страниц в книге " << namebook << " - " << numpages << endl;
	}
};

class type :Publication, sales {
	float recordtime;
public:
	void getdata() {
		cout << "введите название книги" << endl;
		cin >> namebook;
		cout << "введите длину записи в минутах" << endl;
		cin >> this->recordtime;
	}
	void putdata() {
		cout << "название книги: " << namebook << endl;
		cout << "продажи книг за последние три месяца: " << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;
		cout << "длительность записи книги " << namebook << " - " << recordtime << " минут" << endl;
	}
};

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	book dostoevsky;
	type typedostoevsky;
	dostoevsky.getdata();
	dostoevsky.putdata();
	typedostoevsky.getdata();
	typedostoevsky.putdata();
}