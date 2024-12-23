#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Hi! It's a constructor\n";
    }
    ~Test() {
        std::cout << "Hi! It's a destructor\n";
    }
};

int bar(int i) {
    if (i == 1) {
        throw 1;
    }
    if (i == 2) {
        throw 2;
    }
}

int foo(int i) {
    Test b, c;
    int a = 0;
    try {
        a = bar(i);
    } catch(int e) {
        a = e;
    }
    return a;
}

int main(int argc, char** argv) {
    std::cout << foo(argc) << '\n';
    return 0;
}
