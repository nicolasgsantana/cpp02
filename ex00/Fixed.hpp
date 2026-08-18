#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
private:
	int					m_value;
	static const int	m_fractionalBits = 8;
public:
	Fixed(void);
	Fixed(const Fixed &obj);
	Fixed &operator= (const Fixed &obj);
}

#endif
