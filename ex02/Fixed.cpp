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

Fixed Fixed::operator+(const Fixed &fix) const {
	Fixed result;

	result = Fixed(this->toFloat() + fix.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed &fix) const {
	Fixed result;

	result = Fixed(fix.toFloat() - this->toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed &fix) const {
	Fixed f;

	f.FixedPointValue = this->getRawBits() * fix.getRawBits();
	return (f);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	float	num = fixed.getRawBits();

	for (int i = 0; i < 8; i++)
		num /= 2;
	os << num;
	return (os);
}

void Fixed::setRawBits(const int raw) {
	FixedPointValue = raw;
}

int Fixed::getRawBits(void) const {
	return (FixedPointValue);
}

int Fixed::toInt(void) const {
	return (FixedPointValue >> FractionalBitCount);
}

float Fixed::toFloat(void) const {
	float	num = this->getRawBits();

	for (int i = 0; i < 8; i++)
		num /= 2;
	return (num);
}


