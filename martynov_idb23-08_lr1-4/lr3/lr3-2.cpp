#include <iostream>
#include <vector>
#include <random>

class Base {
public:
    virtual ~Base() { std::cout << "Base destroyed\n"; }
    virtual void behavior() const { std::cout << "Base behavior\n"; }
};

class Derived : public Base {
public:
    ~Derived() override { std::cout << "Derived destroyed\n"; }
    void behavior() const override { std::cout << "Derived behavior\n"; }
};

void add(std::vector<std::shared_ptr<Base>>& storage, const std::shared_ptr<Base>& obj) {
    storage.push_back(obj);
}

int main() {
    std::vector<std::shared_ptr<Base>> objects;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < 10; ++i) {
        if (dis(gen) % 2 == 0) {
            add(objects, std::make_shared<Base>());
        }
        else {
            add(objects, std::make_shared<Derived>());
        }
    }

    for (const auto& obj : objects) {
        obj->behavior();
    }

    return 0;
}
