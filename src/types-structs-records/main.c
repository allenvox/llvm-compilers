#include <stdio.h>
#include <inttypes.h>

struct S {
  uint8_t visible;
  uint64_t x, y;
};

int main() {
    struct S s1 = {1, 2, 3};
    printf("%d %llu %llu\n", s1.visible, s1.x, s1.y);
    return 0;
}