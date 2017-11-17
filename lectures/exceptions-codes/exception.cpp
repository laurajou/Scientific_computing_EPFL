#include <cmath>
#include <iostream>
#include <string>

struct Exception {
  Exception(const std::string &mesg);

  const std::string &what() { return mesg; };

  std::string mesg;
};

double sqrt(double x) {
  if (x < 0) {
    throw Exception("no negative number sqrt");
  }
  return std::sqrt(x);
}

int main(int argc, char **argv) {

  try {
    double res = sqrt(-1);
    std::cout << res << std::endl;
  } catch (Exception &e) {
    std::cout << e.what() << std::endl;
  }
}