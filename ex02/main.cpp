#include "Fixed.hpp"
#include <iostream>

static void separator(const std::string &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
	separator("Constructors / destructor / copy / assignment");
	{
		Fixed a;
		Fixed b(10);
		Fixed c(5.5f);
		Fixed d(c);
		Fixed e;
		e = b;

		std::cout << "a (default) = " << a << std::endl;
		std::cout << "b (int 10)  = " << b << std::endl;
		std::cout << "c (float 5.5) = " << c << std::endl;
		std::cout << "d (copy of c) = " << d << std::endl;
		std::cout << "e (assigned from b) = " << e << std::endl;
	}

	separator("Negative values (constructor overflow/UB checks)");
	{
		Fixed neg(-5);
		Fixed negf(-5.9f);
		Fixed negf2(-5.1f);
		std::cout << "Fixed(-5)    = " << neg << " (raw " << neg.getRawBits() << ")" << std::endl;
		std::cout << "Fixed(-5.9f) = " << negf << " (expect -6, raw " << negf.getRawBits() << ")" << std::endl;
		std::cout << "Fixed(-5.1f) = " << negf2 << " (expect -5, raw " << negf2.getRawBits() << ")" << std::endl;
		std::cout << "toInt(-5.9f) = " << negf.toInt() << std::endl;
	}

	separator("Rounding checks (float constructor)");
	{
		Fixed r1(5.5f);
		Fixed r2(5.501f);
		Fixed r3(5.499f);
		std::cout << "5.5f   -> " << r1 << std::endl;
		std::cout << "5.501f -> " << r2 << std::endl;
		std::cout << "5.499f -> " << r3 << std::endl;
	}

	separator("getRawBits / setRawBits");
	{
		Fixed a(5.5f);
		std::cout << "raw bits of 5.5f = " << a.getRawBits() << std::endl;
		Fixed b;
		b.setRawBits(a.getRawBits());
		std::cout << "b built from same raw bits = " << b << std::endl;
	}

	separator("Comparison operators");
	{
		Fixed a(5.5f);
		Fixed b(10.0f);
		std::cout << "a=" << a << " b=" << b << std::endl;
		std::cout << "a > b  : " << (a > b) << std::endl;
		std::cout << "a < b  : " << (a < b) << std::endl;
		std::cout << "a >= a : " << (a >= a) << std::endl;
		std::cout << "a <= a : " << (a <= a) << std::endl;
		std::cout << "a == a : " << (a == a) << std::endl;
		std::cout << "a != b : " << (a != b) << std::endl;
	}

	separator("Arithmetic operators");
	{
		Fixed a(5.5f);
		Fixed b(2.0f);
		std::cout << "a=" << a << " b=" << b << std::endl;
		std::cout << "a + b = " << (a + b) << " (expect 7.5)" << std::endl;
		std::cout << "a - b = " << (a - b) << " (expect 3.5)" << std::endl;
		std::cout << "a * b = " << (a * b) << " (expect 11)" << std::endl;
		std::cout << "a / b = " << (a / b) << " (expect 2.75)" << std::endl;
	}

	separator("Increment / decrement (pre and post)");
	{
		Fixed a(5.5f);
		std::cout << "a       = " << a << std::endl;
		std::cout << "a++     = " << (a++) << " (old value, expect 5.5)" << std::endl;
		std::cout << "a after = " << a << " (expect 5.5 + 2^-8 = 5.50390625)" << std::endl;
		std::cout << "++a     = " << (++a) << " (expect 5.5078125)" << std::endl;

		Fixed b(5.5f);
		std::cout << "\nb       = " << b << std::endl;
		std::cout << "b--     = " << (b--) << " (old value, expect 5.5)" << std::endl;
		std::cout << "b after = " << b << " (expect 5.49609375)" << std::endl;
		std::cout << "--b     = " << (--b) << " (expect 5.4921875)" << std::endl;
	}

	separator("min / max (non-const overload)");
	{
		Fixed a(5.5f);
		Fixed b(10.0f);
		std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

		// modify through the returned reference to prove it's the real object
		Fixed::min(a, b) = Fixed(100.0f);
		std::cout << "after Fixed::min(a, b) = 100: a = " << a << ", b = " << b << std::endl;
	}

	separator("min / max (const overload)");
	{
		const Fixed a(3.25f);
		const Fixed b(7.75f);
		std::cout << "const min(a, b) = " << Fixed::min(a, b) << std::endl;
		std::cout << "const max(a, b) = " << Fixed::max(a, b) << std::endl;
	}

	separator("toInt / toFloat round trip");
	{
		Fixed a(42);
		Fixed b(3.14159f);
		std::cout << "Fixed(42).toInt()      = " << a.toInt() << std::endl;
		std::cout << "Fixed(3.14159f).toFloat() = " << b.toFloat() << std::endl;
	}

	return (0);
}