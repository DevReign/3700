#include <iostream>
#include "fraction.h"

#ifndef POINT_H
#define POINT_H

class Point
{
private:
	Fraction x, y;
public:
	Point(Fraction _x=Fraction(),Fraction _y=Fraction());
	~Point()=default;

	Point operator+(Point rhs);
	Point operator-(Point rhs);
	Point operator/(Point rhs);
	Point operator*(Point rhs);
	Point operator=(Point rhs);

	bool operator==(Point rhs);
	bool operator!=(Point rhs);
	bool operator<=(Point rhs);
	bool operator>=(Point rhs);
	bool operator<(Point rhs);
	bool operator>(Point rhs);

	Fraction getX() { return x; }
	Fraction getY() { return y; }
	void print() { std::cout<<"("<< x << ", " << y <<")\n"; }
};

#endif