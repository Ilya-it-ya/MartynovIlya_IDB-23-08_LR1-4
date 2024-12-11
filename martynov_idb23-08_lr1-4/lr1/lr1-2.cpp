
#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;
int n;
class book {
public:
	string a, b, c;
	book(string a, string b, string c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	book() {}
};
void switchh(book* arr, int option) {
	switch (option)
	{
	case(1):
		for (int i = 0; i < n; i++) {
			if (arr[i].c == "художественная литература") {
				cout << "автор " << i + 1 << " книги: " << arr[i].a << ", её название: " << arr[i].b << ", её жанр: " << arr[i].c << endl;
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i].c == "техническая литература") {
				cout << "автор " << i + 1 << " книги: " << arr[i].a << ", её название: " << arr[i].b << ", её жанр: " << arr[i].c << endl;
			}
		}
		break;
	case(2):
		for (int i = 0; i < n; i++) {
			if (arr[i].c == "техническая литература") {
				cout << "автор " << i + 1 << " книги: " << arr[i].a << ", её название: " << arr[i].b << ", её жанр: " << arr[i].c << endl;
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i].c == "художественная литература") {
				cout << "автор " << i + 1 << " книги: " << arr[i].a << ", её название: " << arr[i].b << ", её жанр: " << arr[i].c << endl;
			}
		}
		break;
	}
}
void iff(book* arr, int option) {
	if (option == 1) {
		for (int i = 0; i < n; i++) {
			if (arr[i].c == "художественная литература") {
				cout << "автор " << i + 1 << " книги: " << arr[i].a << ", её название: " << arr[i].b << ", её жанр: " << arr[i].c << endl;
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i].c == "техническая литература") {
				cout << "автор " << i + 1 << " книги: " << arr[i].a << ", её название: " << arr[i].b << ", её жанр: " << arr[i].c << endl;
			}
		}
	}
	if (option == 2)
	{
		for (int i = 0; i < n; i++) {
			if (arr[i].c == "техническая литература") {
				cout << "автор " << i + 1 << " книги: " << arr[i].a << ", её название: " << arr[i].b << ", её жанр: " << arr[i].c << endl;
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i].c == "художественная литература") {
				cout << "автор " << i + 1 << " книги: " << arr[i].a << ", её название: " << arr[i].b << ", её жанр: " << arr[i].c << endl;
			}
		}
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "введите количество книг" << endl;
	cin >> n;
	book* library = new book[n];
	for (int i = 0; i < n; i++) {
		string a, b, c;
		cout << "введите автора " << i + 1 << " книги" << endl;
		cin.get();
		getline(cin, a);
		cout << "введите название " << i + 1 << " книги" << endl;
		getline(cin, b);
		cout << "введите жанр " << i + 1 << " книги" << endl;
		string c_demo;
		cin >> c_demo;
		if ((c_demo.find("Художественный") != string::npos) or (c_demo.find("художественный") != string::npos)) {
			c = "художественная литература";
		}
		if ((c_demo == "Технический") or (c_demo == "технический")) {
			c = "техническая литература";
		}
		if ((a != "") and (b != "") and ((c == "техническая литература") or (c == "художественная литература"))) {
			library[i] = book(a, b, c);
		}
		else
		{
			cout << "вы ввели что-то не то" << endl;
			i--;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "автор " << i + 1 << " книги: " << library[i].a << ", её название: " << library[i].b << ", её жанр: " << library[i].c << endl;
	}
	cout << endl << "хотите вывести сначала художественные книги, а затем технические, или наоборот?" << endl << "1) выведи сначала художественные, потом технические (введите 1 если этот вариант)" << endl << "2) выведи сначала технические, затем художественные (введите 2 если этот вариант)" << endl;
	short option;
	cin >> option;
	if (option == 1) {
		switchh(library, option);
	}
	if (option == 2) {
		iff(library, option);
	}
}
