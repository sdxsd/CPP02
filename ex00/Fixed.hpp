#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
		static const int	FractionalBitCount = 8;
		int					FixedPointValue;
	public:
		Fixed(void);
		Fixed(Fixed &copy);
		~Fixed(void);
		void	operator=(Fixed &copy);
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
};

#endif // FIXED_H
