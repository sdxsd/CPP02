#include "Fixed.hpp"

Fixed::Fixed(void) {
	FixedPointValue = 0;
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(Fixed& copy) {
	FixedPointValue = copy.FixedPointValue;
	std::cout << "Copy constructor called." << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called." << std::endl;
}

void Fixed::operator=(Fixed &copy) {
	FixedPointValue = copy.FixedPointValue;
	std::cout << "Copy assignment operator called." << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits() called." << std::endl;
	return (FixedPointValue);
}

void Fixed::setRawBits(const int raw) {
	FixedPointValue = raw;
	std::cout << "setRawBits() called." << std::endl;
}
