#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
		static const int	FractionalBitCount = 8;
		int			FixedPointValue;
	public:
		Fixed(void);
		Fixed(Fixed &copy);
		Fixed(float f);
		Fixed(int n);
		~Fixed(void);
		void	operator=(Fixed &copy);
		void	setRawBits(int const raw);
		int	getRawBits(void) const;
		void	test(void) const;
		int	toInt(void) const;
		friend std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);
};

#endif // FIXED_H
