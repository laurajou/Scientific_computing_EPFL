#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
/* -------------------------------------------------------------------------- */
struct Triplet {

  Triplet(){};

  Triplet(double x, double y, double z) {
    coords[0] = x;
    coords[1] = y;
    coords[2] = z;
  };

  double coords[3];
};

/* -------------------------------------------------------------------------- */

inline std::ostream &operator<<(std::ostream &stream, Triplet &_this) {
  stream << _this.coords[0] << " " << _this.coords[1] << " " << _this.coords[2];
  return stream;
}

/* -------------------------------------------------------------------------- */

int main(int argc, char **argv) {

  /*
     Exercice 1
  */

  std::vector<double> array;
  int npoints = 100;

  // with a simple loop
  for (int i = 0; i < npoints; ++i) {
    array.push_back(2. * M_PI / npoints * i);
  }

  // with iota + functor
  array.resize(npoints);
  std::iota(array.begin(), array.end(), 0);
  std::for_each(array.begin(), array.end(),
                [npoints](double &v) { v = 2. * M_PI / npoints * v; });

  std::vector<double> sin_array;

  // with range loop
  // for (auto v: array){
  //   sin_array.push_back(sin(v));
  // }

  // with for_each + lambda
  std::for_each(array.begin(), array.end(),
                [&sin_array](double &v) { sin_array.push_back(sin(v)); });

  std::ofstream f("toto.txt");
  auto it_sin = sin_array.begin();

  std::for_each(array.begin(), array.end(), [&it_sin, &f](double &v) {
    f << std::scientific << std::setprecision(20) << v << " " << *it_sin
      << std::endl;
    ++it_sin;
  });

  /*
     Exercice 2
  */

  std::map<std::string, Triplet> map;
  Triplet origin_coordinates(0., 0., 0.);
  map["sun"] = origin_coordinates;

  auto end = map.end();
  origin_coordinates.coords[0] = 1.;
  auto it = map.find("earth");
  if (it == end)
    map["earth"] = origin_coordinates;

  std::cout << std::endl << "The complete map content is:" << std::endl;

  // in C++11
  for (auto &key_val : map) {
    std::cout << key_val.first << std::endl;
    std::cout << key_val.second << std::endl;
  }

  // only in C++14
  // std::for_each(map.begin(), map.end(), [](auto & key_val) {
  //  std::cout << key_val.first << std::endl;
  //  std::cout << key_val.second << std::endl;
  //});

  return EXIT_SUCCESS;
}
