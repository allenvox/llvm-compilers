struct Shape {
public:
    Shape(int color): color{color}, weight{0} { }
    Shape(int color, int weight): color{color}, weight{weight} { }

private:
    int color = 0;
    int weight = 0;
};

int main()
{
    Shape s1 = {1};
    Shape s2 = {1, 1};
    
    int *p = new int[10];
    p[0] = 4;
    
    return p[0];
}