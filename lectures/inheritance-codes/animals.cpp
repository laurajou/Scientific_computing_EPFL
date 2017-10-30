#include <iostream>

class Animal {

public:
  void scream() {
    std::cout << name;
    std::cout << ": AAAAAAA" << std::endl;
  }

private:
  std::string name;
};

class Cat {
public:
  void scream() { std::cout << name << ": MIAOU\n"; }

private:
  std::string name;
};

class Dog {
public:
  void scream() { std::cout << name << ": OUAFF\n"; }

private:
  std::string name;
};

int main(){
//what you want
}
