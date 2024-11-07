#include <stdio.h>

int main()
{
    struct point {
        float x, y;
        int color;
    };
    struct point p;

    p.color = 4;

    printf("%d\n", p.color);
    return 0;
}