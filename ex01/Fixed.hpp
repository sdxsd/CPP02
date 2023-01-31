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
		void	setRawBits(int const raw);
		int	getRawBits(void) const;
		int	toInt(void) const;
		float	toFloat(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &toPrint);

#endif // FIXED_H
