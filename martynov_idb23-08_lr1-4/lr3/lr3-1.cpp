#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

class Detail {
protected:
	Detail() { cout << "деталь создана\n"; }
public:
	virtual ~Detail() { cout << "деталь удалена\n"; }
	virtual void show() const = 0;

	template <typename R, typename... Args>
	shared_ptr<R> create(Args&&... args);
};

class Assembly : public Detail {
private:
	Assembly() { cout << "сборка создана\n"; }
public:
	~Assembly() override { cout << "сборка удалена\n"; }
	void show() const override { cout << "это сборка.\n"; }
	template <typename R, typename... Args>
	friend shared_ptr<R> create(Args&&... args);
};

template <typename X, typename... Args>
shared_ptr<X> create(Args&&... args) {
	return shared_ptr<X>(new X(forward<Args>(args)...));
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<shared_ptr<Detail>> details;
	details.push_back(create<Assembly>());
	for (const auto& detail : details) {
		detail->show();
	}
	return 0;
}
