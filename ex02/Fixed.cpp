#include "Fixed.hpp"

Fixed::Fixed(void) : m_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->m_value = (value  * (1 << this->m_fractionalBits));
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->m_value = int(value * (float(1 << this->m_fractionalBits)) + (value >= 0 ? 0.5 : -0.5));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->setRawBits(obj.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->m_value;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->m_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float(this->m_value) / float(1 << this->m_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->m_value / (1 << this->m_fractionalBits));
}

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->getRawBits() != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result(this->getRawBits() + obj.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed result(this->getRawBits() - obj.getRawBits());
	return (result);
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits(int((long(this->getRawBits()) << Fixed::m_fractionalBits) / long(obj.getRawBits())));
	return (result);
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits(int((long(this->getRawBits()) * long(obj.getRawBits())) >> Fixed::m_fractionalBits));
	return (result);
}

Fixed &Fixed::operator--(void)
{
	this->m_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->m_value -= 1;
	return (temp);
}

Fixed &Fixed::operator++(void)
{
	this->m_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->m_value -= 1;
	return (temp);
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	return (n1 < n2 ? n1 : n2);
}

Fixed &Fixed::min(const Fixed &n1, const Fixed &n2)
{
	return (n1 < n2 ? n1 : n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	return (n1 > n2 ? n1 : n2);
}

Fixed &Fixed::max(const Fixed &n1, const Fixed &n2)
{
	return (n1 > n2 ? n1 : n2);
}
