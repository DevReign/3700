#include <iostream>

using namespace std;

void showBits(unsigned int n) {

	for (int i = 31; i >= 0; i--) {
		if (n & (1 << i))
			cout << '1';
		else
			cout << '0';
	}
	cout << endl;
}

int countBits(unsigned int n) {
	int count=0;

	while (n != 0) {
		count++;
		n &= n - 1;
	}
	return count;
}


int main(void) {
	unsigned int
	a,b,c;

	cout << "Enter two nonnegative integers: ";
	cin >> a >> b;

	// your code goes here
	cout << "a in bits: ";
	showBits(a);

	cout << "b in bits: ";
	showBits(b);

	cout << "Bit &: ";
	c = a & b;
	showBits(c);

	cout << "Bit |: ";
	c = a | b;
	showBits(c);

	cout << "Bit ~a: ";
	c = ~a;
	showBits(c);

	cout << "Bit ^: ";
	c = a ^ b;
	showBits(c);

	cout << "Bit << by 4: ";
	c = a << 4;
	showBits(c);

	cout << "Bit >> by 4: ";
	c = a >> 4;
	showBits(c);

	cout << "Number of on bits in a: " << countBits(a) << endl;

	return 0;
}
