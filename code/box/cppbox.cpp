#include "box.hpp"

#include <iostream>

int main() {
  cppug::box box{3};

  box.push(42);
  std::cout << box.pop() << '\n';
}
