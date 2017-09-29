#include <iostream>

void bool_test() {

  bool flag = true;
  if (flag) {
    std::cout << "This will be printed\\n";
  } else {
    // flag is false
    std::cout << "This won't be printed\\n";
  }
}

void and_test() {
  double x, z, p, q;
  double y;
  if ((x > z) && (p > q)) {
    // Both conditions have been met
    y = 10.0;
  }
}

void and_test() {
  double x, z, p, q;
  double y;
  if ((x > z) && (p > q)) {
    // Both conditions have been met
    y = 10.0;
  }
}

void or_test() {

  double p, q;
  double i;
  double y;

  if ((y > q) || (i != 1)) {
    // One or both conditions have been met
    y = 10.0;
  } else {
    // Neither condition has been met: p<=q and i==1
    y = -10.0;
  }
}

void negation_test() {
  int i;
  bool flag = false;
  if (!flag) {
    // !flag is true when flag is false
    i += 2;
  }
}

int main() {
  bool_test();
  and_test();
  or_test();
}
