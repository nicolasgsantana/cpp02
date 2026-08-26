#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
private:
	int					m_value;
	static const int	m_fractionalBits = 8;
public:
	Fixed(void);
	Fixed(const Fixed &obj);
	Fixed &operator= (const Fixed &obj);
	~Fixed(void);

	Fixed(const int value);
	Fixed(const float value);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	bool operator> (const Fixed &obj) const;
	bool operator< (const Fixed &obj) const;
	bool operator>= (const Fixed &obj) const;
	bool operator<= (const Fixed &obj) const;
	bool operator== (const Fixed &obj) const;
	bool operator!= (const Fixed &obj) const;

	Fixed operator+ (const Fixed &obj) const;
	Fixed operator- (const Fixed &obj) const;
	Fixed operator/ (const Fixed &obj) const;
	Fixed operator* (const Fixed &obj) const;

	Fixed &operator-- (void);
	Fixed operator-- (int);
	Fixed &operator++ (void);
	Fixed operator++ (int);

	static Fixed &min(Fixed &n1, Fixed &n2);
	static Fixed &min(const Fixed &n1, const Fixed &n2);
	static Fixed &max(Fixed &n1, Fixed &n2);
	static Fixed &max(const Fixed &n1, const Fixed &n2);
};

std::ostream& operator<< (std::ostream &os, const Fixed &fixed);

#endif
