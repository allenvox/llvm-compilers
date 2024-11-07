#include <iostream>

struct Shape {
public:
    Shape(int color): color{color}, weight{0} { }
    Shape(int color, int weight): color{color}, weight{weight} { }
    int getColor() const { return color; }

private:
    int color = 0;
    int weight = 0;
};

struct Circle: public Shape {
public:
    Circle(int r): Shape(1, 1), r{r} { }
private:
    int r = 1;
};

int main()
{
    Circle c = {10};

    return 0;
}
