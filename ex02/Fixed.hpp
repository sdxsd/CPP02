#ifndef FIXED_H
#define FIXED_H
#define CMESSAGE 0

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
		void			operator=(const Fixed &fix);
		Fixed			operator+(const Fixed &fix) const;
		Fixed			operator-(const Fixed &fix) const;
		Fixed			operator/(const Fixed &fix) const;
		Fixed			operator*(const Fixed &fix) const;
		bool			operator<(const Fixed &fix) const;
		bool			operator>(const Fixed &fix) const;
		bool			operator<=(const Fixed &fix) const;
		bool			operator>=(const Fixed &fix) const;
		bool			operator==(const Fixed &fix) const;
		bool			operator!=(const Fixed &fix) const;
		Fixed&			operator++(void);
		Fixed&			operator--(void);
		Fixed			operator++(int);
		Fixed			operator--(int);
		// Static member functions.
		static Fixed&		min(Fixed &x, Fixed &y);
		static Fixed&		max(Fixed &x, Fixed &y);
		static const Fixed&	min(const Fixed &x, const Fixed &y);
		static const Fixed&	max(const Fixed &x, const Fixed &y);
};

#endif // FIXED_H
