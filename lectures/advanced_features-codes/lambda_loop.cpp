#include <vector>

template <typename V, typename T> void loop(V &vec, T f) {
  for (auto d : vec) {
    auto res = f(d);
  }
}

int main() {
  int a = 2;
  std::vector<double> vec(10);
  loop(vec, [a](double d) { return d * a; });
}