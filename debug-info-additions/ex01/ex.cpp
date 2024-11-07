#include <iostream>

int bar(int x)
{
    if (x == 1) throw 1;
    if (x == 2) throw 42.0;
    return x;
}

int foo(int x)
{
    int y = 0;

    // Какие варианты передачи потока управления после вызова bar()?
    try {
        y = bar(x);
    } catch (int e) {
        // 
        y = e;
    }
    // stack unwind
    return y;
}

int main(int argc, char **argv)
{
    std::cout << foo(argc) << "\n";
    return 0;
}
