#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed(void) {
	FixedPointValue = 0;
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	FixedPointValue = copy.FixedPointValue;
	std::cout << "Copy constructor called." << std::endl;
}

Fixed::Fixed(float f) {
	std::cout << "Float constructor called." << std::endl;
	for (int i = 0; i < 8; i++)
		f *= 2;
	f = roundf(f);
	FixedPointValue = f;
}

Fixed::Fixed(int n) {
	std::cout << "Int constructor called." << std::endl;
	FixedPointValue = n << FractionalBitCount;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called." << std::endl;
}

void Fixed::operator=(const Fixed &copy) {
	FixedPointValue = copy.FixedPointValue;
	std::cout << "Copy assignment operator called." << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Fixed &toPrint) {
	os << toPrint.toFloat();
	return (os);
}

int Fixed::toInt(void) const {
	return (FixedPointValue >> FractionalBitCount);
}

float Fixed::toFloat(void) const {
	float	num = this->getRawBits();

	num = (float)FixedPointValue / (1 << FractionalBitCount);
	return (num);
}

int Fixed::getRawBits(void) const {
	return (FixedPointValue);
}

void Fixed::setRawBits(const int raw) {
	FixedPointValue = raw;
}
