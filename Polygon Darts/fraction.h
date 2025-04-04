// defines int32_t and related aliases
#include <cstdint>
#include <numeric>
#include <istream>
#include <ostream>

#ifndef _FRACTION_H
#define _FRACTION_H
// see how the _FRACTION_H looks like the file name? Not a coincidence!
// stuff goes here and nowhere else!

class Fraction {
public:
	Fraction(int32_t n=0,int32_t d=1);
	~Fraction() = default;

	// rhs == right hand side, as in the right hand side of an operator
	Fraction operator+(Fraction rhs);
	Fraction operator-(Fraction rhs);
	Fraction operator*(Fraction rhs);
	Fraction operator/(Fraction rhs);

	Fraction operator=(Fraction rhs);

	bool operator==(Fraction rhs);
	bool operator!=(Fraction rhs);
	bool operator<(Fraction rhs);
	bool operator<=(Fraction rhs);
	bool operator>(Fraction rhs);
	bool operator>=(Fraction rhs);


	int32_t getNum() { return num; }
	int32_t getDen() { return den; }
private:
	int32_t
	num,
	den;
};

std::istream &operator>>(std::istream &, Fraction &);
std::ostream &operator<<(std::ostream &, Fraction);
#endif