#include <stdio.h>

void func_with_two_args(int a, int b) {
  printf("Function with two args: %d, %d\n", a, b);
}

void func_with_one_arg(int a) {
  printf("Function with one arg: %d\n", a);
}

int main() {
  func_with_two_args(10, 20);
  func_with_one_arg(30);
  return 0;
}
