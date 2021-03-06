#include <iostream>
#include "fraction.h"

fraction::fraction(int cnt, int dnm) : c(cnt), d(dnm)
{
	if (0 == d)
		throw std::invalid_argument("Illegal denominator 0.");

	if (0 == c % d) {
		c = c / d;
		d = 1;
	}
}

int gcf(int a, int b)
{
	return 0 == b ? a : gcf(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcf(a, b);
}

inline bool check_char(std::istream& is, char ch, bool badbit = true)
{
	char c;
	is >> c;

	if (c != ch) {
		is.putback(c);

		if (badbit)
			is.setstate(std::ios::badbit);

		return false;
	}
	return true;
}

std::ostream& operator <<(std::ostream& os, fraction f)
{
	if (1 == f.d)
		os << f.c;
	else
		os << '(' << f.c << '/' << f.d << ')';
	return os;
}

std::istream& operator >>(std::istream& is, fraction& f)
{
	int cnt, dnm;

	if (check_char(is, '(', false)) {
		is >> cnt;
	} else {
		is >> cnt;
		if (is)
			f = fraction(cnt);
		return is;
	}

	if (check_char(is, '/', false)) {
		is >> dnm;
	} else if (check_char(is, ')')) {
		if (is)
			f = fraction(cnt);
		return is;
	}

	check_char(is, ')');

	if (is)
		f = fraction(cnt, dnm);

	return is;
}

int fraction::get_counter() const
{
	return c;
}

int fraction::get_denominator() const
{
	return d;
}

fraction fraction::operator +(const fraction f) const
{
	int dnm = lcm(d, f.d);
	int cnt = c * dnm / d + f.c * dnm / f.d;

	return fraction(cnt, dnm);
}

fraction fraction::operator -(const fraction f) const
{
	int dnm = lcm(d, f.d);
	int cnt = c * dnm / d - f.c * dnm / f.d;

	return fraction(cnt, dnm);
}

fraction fraction::operator *(const fraction f) const
{
	int n = gcf(c, f.d);
	int m = gcf(f.c, d);

	return fraction((c / n) * (f.c / m), (d / m * (f.d / n)));
}

fraction fraction::operator /(const fraction f) const
{
	int n = gcf(c, f.c);
	int m = gcf(f.d, d);

	return fraction((c / n) * (f.d / m), (d / m * (f.c / n)));
}

fraction fraction::operator *(const int i) const
{
	return *this * fraction(i);
}

fraction fraction::operator /(const int i) const
{
	return *this / fraction(i);
}

bool fraction::operator ==(const fraction f) const
{
	int dnm = lcm(d, f.d);

	return c * dnm / d == f.c * dnm / f.d;
}

bool fraction::operator !=(const fraction f) const
{
	int dnm = lcm(d, f.d);

	return c * dnm / d != f.c *dnm / f.d;
}

bool fraction::operator <(const fraction f) const
{
	int dnm = lcm(d, f.d);

	return c * dnm / d < f.c * dnm / f.d;
}

bool fraction::operator >(const fraction f) const
{
	int dnm = lcm(d, f.d);

	return c * dnm / d > f.c * dnm / f.d;
}
