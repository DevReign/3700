#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include "point.h"

//#define DEBUG 0

using namespace std;

void Sort(Point *p, uint32_t k){
	for (uint32_t i = 0; i < k-1; i++) {
		int n = i;
		for (uint32_t j = i+1; j < k; j++) {
			if (p[j] < p[n]) {
				n = j;
			}
		}
		Point t;
		t = p[i];
		p[i] = p[n];
		p[n] = t;
	}
}
bool turnLeft(Point a, Point b, Point c) {
	Fraction z(0);
	return (b - a)*(c - a) > z;
}
Fraction findPolygonArea(Point p[], int len) {
	Fraction area;
	for (int i = 0; i < len-1; i++){
		area = area + (p[i] * p[i+1]);
		//cout << area << '\n';
	}
	area = area + (p[len-1] * p[0]);
	return area * Fraction(1,2);
}

uint32_t findHull(Point* p, uint32_t k) {
	Sort(p,k);
	// remove duplicate points, adj for k
	int j = 1;
	for (uint16_t i = 1; i < k; i++){
		//Point pi = p[i];
		if(p[i]!= p[i-1])
			p[j++]=p[i];
	}
	k=j;//new size
#ifdef DEBUG
	cout << "K: " << k << '\n' << "SORTED: '\n";
	for (int i = 0; i < k; i++) {
		cout << p[i] << '\n';

	}
#endif

	if (k < 3)
		return 0;

	//Point* lower[512] = p[0];
	Point lower[k];
	lower[0] = p[0];
	uint32_t t = 0;
	for (uint32_t i = 1; i < k; i++){
		while (t > 0 && !turnLeft(lower[t-1], lower[t],p[i])) {
			t--;
		}
		t++;
		lower[t] = p[i];
	}

	Point upper[k];
	upper[0] = p[k-1];
	int u = 0;
	for (int32_t i = k - 2; i >=  0; i--){
		while (u > 0 && !turnLeft(upper[u - 1], upper[u], p[i])) {
			u--;
		}
		u++;
		upper[u] = p[i];
	}

	for (int i = 0; i < t; ++i){
		p[i] = lower[i];
	}
	for (int i = 0; i < u; ++i){
		p[i+t] = upper[i];
	}
#ifdef DEBUG
	std::cout << u << " " << t << '\n';
#endif
	return u+t;
}

int main(int argc, char *args[])
{
	Point a(Fraction(0,1), Fraction(0,1));
	Point b(Fraction(0, 1), Fraction(0, 1));
	Fraction Aboard(0, 1); //area of board
	Point* C; //hull points
	Fraction Ahull(0, 1); //area of C
	Fraction score(0, 1);
	Point points[64];
	uint32_t numPoints = 0;
	uint32_t numDarts = 0;

	//cout << "Enter board width as n/d,n/d: ";
	cin >> b;
	//cout << "Enter num darts: ";
	cin >> numDarts;

	Aboard = b.getX()*b.getY(); //area of board

	for (uint32_t i=0; i < numDarts; i++) {
		Point pn;
		//cout << "Enter dart pos as x/x,y/y: ";
		cin >> pn;
		points[i] = pn;
	}

	numPoints = findHull(points, numDarts);
	C = points;
	Ahull = findPolygonArea(C, numPoints);
	
	//DEBUG
#ifdef DEBUG
	for (uint32_t i = 0; i < numDarts; i++) {
		cout << points[i] << endl;
	}
	cout << "AREA: " << Ahull << '\n';
	cout << "numPoints: " << numPoints << '\n';
#endif
	
	if (Ahull == 0) {
		score = Aboard * Fraction(3, 1);
	}
	else {
		score = Aboard/ Ahull;
		//score = sp.getX() * sp.getY();
	}
	for (uint32_t i = 0; i < numPoints; i++){
		//if point is on the board
		if (points[i].getX() < 0 || points[i].getX() > b.getX() || points[i].getY() < 0 || points[i].getY() > b.getY()){
			score = Fraction(0,1);
			break;
		}
	}

	cout << score << endl;

	return 0;
}
