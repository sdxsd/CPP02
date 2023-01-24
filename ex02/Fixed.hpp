#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
		static const int	FractionalBitCount = 8;
		int			FixedPointValue;
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(float f);
		Fixed(int n);
		~Fixed(void);
		void	operator=(const Fixed &copy);
		Fixed	operator+(const Fixed &fix) const;
		Fixed	operator-(const Fixed &fix) const;
		Fixed	operator/(const Fixed &fix) const;
		Fixed	operator*(const Fixed &fix) const;
		void	setRawBits(int const raw);
		int	getRawBits(void) const;
		void	test(void) const;
		int	toInt(void) const;
		friend std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);
};

#endif // FIXED_H
