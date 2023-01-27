#include <iostream>
#include "Fixed.hpp"

int main(void) {
  Fixed x(10);
  Fixed y(8);
  Fixed z(8.5f);

  std::cout << "x + z = " << x + z << std::endl;
  std::cout << "x - y = " << x - y << std::endl;
  std::cout << "z * 2 = " << z * 2 << std::endl;
  std::cout << "(postfix) x-- " << x-- << std::endl;
  std::cout << "(after postfix) x = " << x << std::endl;
  std::cout << "++y = " << ++y << std::endl;
  for (int i = 0; i < 10; i++)
    ++y;
  std::cout << "++y 10 times = " << y << std::endl;
  return 0;
}
