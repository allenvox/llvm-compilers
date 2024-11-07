#include <stdio.h>
#include <stdlib.h>

void getInt(int i) {
    printf("%d", i);
}

void getArray(int *i) {
    printf("%d", i[0]);
}

void get10Array(int i[10]) {
    printf("%d", i[0]);
}

struct Point {
    int x, y;
};

void getStruct(struct Point p) {
    printf("%d", p.x);
}

void get4Struct(struct Point p[4]) {
    printf("%d", p[0].x);
}

void getCharArray(char *s) {
    printf("%c", s[0]);
}

int main(int argc, char **argv) {
    getInt(4);

    int *i2 = malloc(sizeof(int) * 2);
    i2[0] = 1;
    i2[1] = 3;
    getArray(i2);

    int i10[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    get10Array(i10);

    struct Point p1 = {0, 2};
    getStruct(p1);

    struct Point p2[4] = {{1, 3}, {1, 2}, {0, 1}, {5, 3}};
    get4Struct(p2);

    char *c = "asd";
    getCharArray(c);
    return 0;
}
