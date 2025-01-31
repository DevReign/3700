#include "point.h"

Point::Point(Fraction _x,Fraction _y){
	x = _x;
	y = _y;
}

Point Point::operator+(Point rhs){ 
	x = rhs.x;
	y = rhs.y;
	return *this; }
Point Point::operator-(Point rhs){ 
	x = rhs.x;
	y = rhs.y;
	return *this; }
Point Point::operator/(Point rhs){ 
	x = rhs.x;
	y = rhs.y;
	return *this; }
Point Point::operator*(Point rhs){ 
	x = rhs.x;
	y = rhs.y;
	return *this; }
Point Point::operator=(Point rhs){
	x = rhs.x;
	y = rhs.y;
	return *this;
}

bool Point::operator==(Point rhs){ return 0;}
bool Point::operator!=(Point rhs){ return 0;}
bool Point::operator<=(Point rhs){ return 0;}
bool Point::operator>=(Point rhs){ return 0;}
bool Point::operator<(Point rhs){ return 0;}
bool Point::operator>(Point rhs){
	return 0;
}