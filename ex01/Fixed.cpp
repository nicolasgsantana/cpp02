#include "Fixed.hpp"

Fixed::Fixed(void) : m_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{

}

Fixed::Fixed(const float value)
{

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
	return (0.0f);
}

int Fixed::toInt(void) const
{
	return (0);
}


