#include <iostream>

struct Shape {
public:
    Shape(int color): color{color}, weight{0} { }
    Shape(int color, int weight): color{color}, weight{weight} { }
    int getColor() const { return color; }
    virtual int getType() = 0;
    virtual int getKind() = 0;

private:
    int color = 0;
    int weight = 0;
    int type = 0;
    int kind = 0;
};

struct Circle: public Shape {
public:
    Circle(int r): Shape(1, 1), r{r} { }
    int getType() { return 1; }
    int getKind() { return 333; }
private:
    int r = 1;
};

void processShape(Shape *shape)
{
    std::cout << shape->getColor() << "\n";
    
    std::cout << shape->getType() << "\n";
    std::cout << shape->getKind() << "\n";
}

int main()
{
    Circle c = {10};

    return 0;
}
