#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include "point.h"

using namespace std;

void Sort(Point *p, uint32_t k){
	for (uint32_t i = 0; i < k; i++) {
		int n = i;
		for (uint32_t j = 0; j < k; j++) {
			if (p[j] < p[n]) {
				n = j;
			}
			Point t;
			t = p[i];
			p[i] = p[n];
			p[n] = t;
		}
	}
}
bool isClockwise(Point a, Point b){
	return (b.getX()-a.getX())*(b.getY() + a.getY()) > 0; //return (b - a)*(c - a) > 0;
}
bool turnLeft(Point a, Point b, Point c) {
	Point z(Fraction(0,1), Fraction(0,1));
	return (b - a)*(c - a) > z;
}
Point findPolygonArea(Point p[], int len) {
	Point area(Fraction(0), Fraction(0));
	for (int i = 0; i < len-1; i++){
		area = area + (p[i] * p[i+1]);
	}
	return area * Fraction(1/2);
}

uint32_t findHull(Point* p, uint32_t &k) {
	// remove duplicate points, adj for k
	for (uint16_t i = 0; i < k; i++){
		Point pi = p[i];
		for (uint16_t j = i; j < k; j++){
			if (pi == p[j] && i != j) {
				p[j] = p[k];
				k--;
				continue;
			}
		}
	}
	Sort(p,k);

	if (k < 3)
		return 0;

	//Point* lower[512] = p[0];
	Point* lower = &p[0];
	uint32_t t = 0;
	for (uint32_t i = 1; i < k; i++){
		while (t > 0 && !turnLeft(lower[t-1], lower[t],p[i])) {
			t--;
		}
		t++;
		lower[t] = p[i];
	}

	Point* upper = &p[k-1];
	uint32_t u = 0;
	for (uint32_t i = k - 2; i << k >  0; i--){
		while (t > 0 && !turnLeft(upper[u - 1], upper[u], p[i])) {
			u--;
		}
		u++;
		upper[u] = p[i];
	}
	return k;
}

int main(int argc, char *args[])
{
	Point a(Fraction(0,1), Fraction(0,1));
	Point b(Fraction(0, 1), Fraction(0, 1));
	Fraction Aboard(0, 1); //area of board
	Point* C; //hull points
	Point Ahull(0, 1); //area of C
	Fraction score(0, 1);
	Point points[64];
	uint32_t numPoints = 0;

	Fraction ix, iy;
	uint32_t numDarts = 0;

	cout << "Enter board width as n/d,n/d: ";
	cin >> b;
	cout << "Enter num darts: ";
	cin >> numDarts;

	Aboard = b.getX()*b.getY(); //area of board

	for (uint32_t i=0; i < numDarts; i++) {
		Point pn;
		cout << "Enter dart pos as x/x,y/y: ";
		cin >> pn;
		points[i] = pn;
	}
	//DEBUG
	for (uint32_t i = 0; i < numPoints; i++) {
		cout << points[i] << endl;
	}

	findHull(points, numPoints);
	C = points;
	Ahull = findPolygonArea(C, numPoints);
	
	if (Ahull > a) {
		score = Aboard * Fraction(3, 1);
	}
	else {
		Point sp = Ahull / Aboard;
		score = sp.getX() * sp.getY();
	}
	for (uint32_t i = 0; i < numPoints; i++){
		//if point is on the board
		if (points[i] > a || points[i] < b){

		}
		else{
			score = Fraction(0,1);
			break;
		}
		cout << points[i] << endl;
	}

	cout << score << endl;
	for (uint32_t i = 0; i < numPoints; i++){
		cout << points[i] << endl;
	}
	return 0;
}
