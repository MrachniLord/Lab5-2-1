#include <string>
#include <iostream>
#include <vector>
#include <list>

class A {
public:
    std::string s;
    A() {
        std::cout << "Default constructor class А" << std::endl;
    }

    A(const char* a) {
        s = a;
        std::cout << "User constructor class A" << std::endl;
        std::cout << s << std::endl;
    }

    virtual ~A() {
        std::cout << "Destuctor classа A" << std::endl;
        std::cout << typeid(*this).name() << std::endl;
    }
};

class B : public A {
public:
    B() {
        std::cout << "Constructor  class B" << std::endl;
    }

    B(const char* a) : A(a) {
        std::cout << "User constructor class B" << std::endl;
        std::cout << a << std::endl;
    }

    ~B() {
        std::cout << "Destuctor class B" << std::endl;
        std::cout << typeid(*this).name() << std::endl;
    }
};

void del(std::vector<A*>& v) {
    for (int i = 0; i < v.size(); i++) {
        delete v[i];
    }

}

int main() {
    std::list<A*> l;
    l.push_back(new A("First"));
    l.push_back(new B("Second"));

    // копирование из списка в вектор
    std::vector<A*> v;
    std::list<A*>::iterator it;
    for (it = l.begin(); it != l.end(); ++it) {
        v.push_back(*it);
    }

    del(v);
    for (it = l.begin(); it != l.end(); ++it) {
        delete* it;
    }
    return 0;
}
