#include "Fixed.hpp"
#include <math.h>

// void Fixed::Multiply(int n, int x)
// {
// 	long number = (long)n;
// 	long multiplier = (long)x;

// 	y = n * x
// 	y << 8;
// 	return (number * multiplier << FractionalBitCount * 2);
// }

Fixed::Fixed(void) {
	FixedPointValue = 0;
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(Fixed& copy) {
	FixedPointValue = copy.FixedPointValue;
	std::cout << "Copy constructor called." << std::endl;
}

Fixed::Fixed(float f) {
	for (int i = 0; i < 8; i++)
		f *= 2;
	f = roundf(f);
	FixedPointValue = f;
}

Fixed::Fixed(int n) {
	FixedPointValue = n << FractionalBitCount;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called." << std::endl;
}

void Fixed::operator=(Fixed &copy) {
	FixedPointValue = copy.FixedPointValue;
	std::cout << "Copy assignment operator called." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	float	num = fixed.getRawBits();

	for (int i = 0; i < 8; i++)
		num /= 2;
	os << num;
	return (os);
}

void Fixed::test(void) const {
	float	num = FixedPointValue;
	for (int i = 0; i < FractionalBitCount; i++)
		num /= 2;
	std::cout << num << std::endl;
}

int Fixed::toInt(void) const {
	return (FixedPointValue >> FractionalBitCount);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits() called." << std::endl;
	return (FixedPointValue);
}

void Fixed::setRawBits(const int raw) {
	FixedPointValue = raw;
	std::cout << "setRawBits() called." << std::endl;
}
