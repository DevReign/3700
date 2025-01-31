#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include "point.h"

using namespace std;

int main(int argc, char *args[])
{
	//Fraction x(5,5);
	Fraction y(2,7);
	Point b(Fraction(5,5), y);

	b.print();
	
	return 0;
}
