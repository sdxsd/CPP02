#include <iostream>
#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);
  a = Fixed(1234.4321f);

  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  if (c > b)
    std::cout << "c > b = TRUE" << std::endl;
  std::cout << "c + b = " << c + b << std::endl;
  std::cout << "(c + b) - c = " << (c + b) - c << std::endl;
  if ((c < b) == false)
    std::cout << "c < b = false" << std::endl;
  return (0);
}
