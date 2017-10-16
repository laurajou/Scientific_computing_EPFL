#include <cstdlib>

double foo(double a) { return a + 1; }

int main() {

  double (*ptr_foo)(double a) = &foo;

  ptr_foo(10);
}