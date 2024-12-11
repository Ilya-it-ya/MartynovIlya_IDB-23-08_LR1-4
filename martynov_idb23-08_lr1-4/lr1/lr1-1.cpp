#include <iostream>
#include <random>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	random_device ggg;
	mt19937 generator(ggg());
	uniform_int_distribution<>distribution(-32768, 32767);
	short arr[10];
	cout << "содержимое массива:  ";
	for (int x = 0; x < 10; x++) {
		arr[x] = distribution(generator); //генерируем рандомные числа
		cout << arr[x] << " ";
	}
	cout << endl << "адресс начала массива:  " << &arr[0] << endl << "адресс второго эллемента массива:  " << &arr[1];
}
