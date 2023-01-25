#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
		// Member variables.
		static const int	FractionalBitCount = 8;
		int			FixedPointValue;
	public:
		// Constructors & destructors
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(float f);
		Fixed(int n);
		~Fixed(void);
		// Member functions (methods).
		void	setRawBits(int const raw);
		int	getRawBits(void) const;
		int	toInt(void) const;
		float	toFloat(void) const;
		// Operators.
		friend std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);
		void			operator=(const Fixed &copy);
		Fixed			operator+(const Fixed &fix) const;
		Fixed			operator-(const Fixed &fix) const;
		Fixed			operator/(const Fixed &fix) const;
		Fixed			operator*(const Fixed &fix) const;
};

#endif // FIXED_H
