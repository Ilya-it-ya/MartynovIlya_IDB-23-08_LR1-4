#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    Person(string name, int age) : name(name), age(age) {}
    virtual void printInfo() {
        cout << "Name: " << name << ", Age: " << age;
    }
};

class Preschooler : public Person {
public:
    Preschooler(string name, int age) : Person(name, age) {}
    void printInfo() override {
        cout << "Preschooler: ";
        Person::printInfo();
        cout << endl;
    }
};

class Schoolchild : public Person {
public:
    int grade;
    Schoolchild(string name, int age, int grade) : Person(name, age), grade(grade) {}
    void printInfo() override {
        cout << "Schoolchild: ";
        Person::printInfo();
        cout << ", Grade: " << grade << endl;
    }
};

class Student : public Person {
public:
    string university;
    Student(string name, int age, string university) : Person(name, age), university(university) {}
    void printInfo() override {
        cout << "Student: ";
        Person::printInfo();
        cout << ", University: " << university << endl;
    }
};

class WorkingPerson : public Person {
public:
    string profession;
    WorkingPerson(string name, int age, string profession) : Person(name, age), profession(profession) {}
    void printInfo() override {
        cout << "Working Person: ";
        Person::printInfo();
        cout << ", Profession: " << profession << endl;
    }
};

template <typename T>
class PointerArray {
private:
    vector<T*> array; 
public:
    void add(T* object) { array.push_back(object); } 
    T* operator[](int index) { return array[index]; } 
    int size() { return array.size(); } 
};

int main() {
    PointerArray<Person> people;
    people.add(new Preschooler("Peter", 5));
    people.add(new Schoolchild("Vasya", 10, 5));
    people.add(new Student("Masha", 19, "MSU"));
    people.add(new WorkingPerson("Kolya", 30, "Programmer"));

    PointerArray<int> numbers;
    numbers.add(new int(10));
    numbers.add(new int(20));
    cout << *numbers[0] << endl;
    cout << *numbers[1] << endl;

    try {
        for (size_t i = 0; i < 3; ++i) {
            people[i]->printInfo();
        }
    }
    catch (const out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << endl;
    }

    for (size_t i = 0; i < people.size(); ++i) {
        delete people[i];
    }
    for (size_t i = 0; i < numbers.size(); ++i) {
        delete numbers[i];
    }

    return 0;
}


