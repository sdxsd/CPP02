#include "Fixed.hpp"
#include <math.h>

/* === / CONSTRUCTORS & DESTRUCTORS / === */

Fixed::Fixed(void) {
	if (CMESSAGE)
		std::cout << "Default constructor called." << std::endl;
	FixedPointValue = 0;
}

Fixed::Fixed(const Fixed& copy) {
	if (CMESSAGE)
		std::cout << "Copy constructor called." << std::endl;
	FixedPointValue = copy.FixedPointValue;
}

Fixed::Fixed(float f) {
	if (CMESSAGE)
		std::cout << "Float constructor called." << std::endl;
	for (int i = 0; i < 8; i++)
		f *= 2;
	f = roundf(f);
	FixedPointValue = f;
}

Fixed::Fixed(int n) {
	if (CMESSAGE)
		std::cout << "Int constructor called." << std::endl;
	FixedPointValue = n << FractionalBitCount;
}

Fixed::~Fixed(void) {
	if (CMESSAGE)
		std::cout << "Destructor called." << std::endl;
}

/* === / METHODS / === */

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

	num = (float)FixedPointValue / (1 << FractionalBitCount);
	return (num);
}

/* === / OPERATORS / === */

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

void Fixed::operator=(const Fixed &fix) {
	if (CMESSAGE)
		std::cout << "Copy assignment operator called." << std::endl;
	FixedPointValue = fix.FixedPointValue;
}

Fixed Fixed::operator+(const Fixed &fix) const {
	Fixed result;

	result = Fixed(fix.toFloat() + this->toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed &fix) const {
	Fixed result;

	result = Fixed(fix.toFloat() - this->toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed &fix) const {
	Fixed result;

	result = Fixed(fix.toFloat() / this->toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed &fix) const {
	Fixed result;

	result = Fixed(fix.toFloat() * this->toFloat());
	return (result);
}

bool Fixed::operator>(const Fixed &fix) const {
	return (this->toFloat() > fix.toFloat());
}

bool Fixed::operator<(const Fixed &fix) const {
	return (this->toFloat() < fix.toFloat());
}

bool Fixed::operator>=(const Fixed &fix) const {
	return (this->toFloat() >= fix.toFloat());
}

bool Fixed::operator<=(const Fixed &fix) const {
	return (this->toFloat() <= fix.toFloat());
}

bool Fixed::operator==(const Fixed &fix) const {
	return (this->toFloat() == fix.toFloat());
}

bool Fixed::operator!=(const Fixed &fix) const {
	return (this->toFloat() != fix.toFloat());
}

Fixed &Fixed::operator++(void) {
	++(this->FixedPointValue);
	return (*this);
}

Fixed &Fixed::operator--(void) {
	--(this->FixedPointValue);
	return (*this);
}

Fixed &Fixed::operator++(int x) {
	if (x >= 0) {
		for (int i = 0; i < x; i++)
			++(this->FixedPointValue); }
	else if (x <= 0) {
		for (int i = 0; i < x; i++)
			--(this->FixedPointValue); }
	return (*this);
}

Fixed &Fixed::operator--(int x) {
	if (x <= 0) {
		for (int i = 0; i < x; i++)
			++(this->FixedPointValue); }
	else if (x >= 0) {
		for (int i = 0; i < x; i++)
			--(this->FixedPointValue); }
	return (*this);
}

/* === / STATIC MEMBER FUNCTIONS / === */

Fixed& Fixed::min(Fixed &x, Fixed &y) {
	if (x.toFloat() <= y.toFloat())
		return (x);
	return (y);
}

Fixed& Fixed::max(Fixed &x, Fixed &y) {
	if (x.toFloat() >= y.toFloat())
		return (x);
	return (y);
}
