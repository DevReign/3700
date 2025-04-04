#include <iostream>
#include <iomanip>
#include "stack.h"
using namespace std;

#define FILLED_IN(b) (((b)&IS_FILLED_IN)!=0)//#define HEX( x ) setw(2) << setfill('0') << hex << (int)(x)

const uint32_t
	IS_FILLED_IN = 0x80000000,
	VALUE_MASK = 0x0000000f,
	IS_0_VALID = 0x00000010,
	VALID_BITS = 0x000ffff0;

void DrawBoard(uint32_t* b) {
	char hex_digits[17] = { "0123456789ABCDEF" };

	//draw board
	for (int i = 0; i < 256; i++) {
		if (i % 4 == 0)
			cout << " ";
		if (i % 16 == 0)
			cout << endl;
		if (i % 64 == 0)
			cout << endl;

		if (FILLED_IN(b[i]))
			cout << hex_digits[(b[i] & VALUE_MASK)];
		else
			cout << '.';
	}
	cout << endl;
}

int countBits(unsigned int n) {
	int count = 0;

	while (n != 0) {
		count++;
		n &= n - 1;
	}
	return count;
}

bool findBest(uint32_t* b, Stack<uint32_t> *s) {
	for (int i = 0; i < 256; i++)
		if (!FILLED_IN(b[i]))
			b[i] |= VALID_BITS;

	for (int i = 0; i < 256; i++) {
		if (FILLED_IN(b[i])) {
			int column = i % 16;
			int row = i / 16; int k = b[i] & VALUE_MASK;
			//row
			for (int r = 0; r < 16; r++)
				if(!FILLED_IN(b[r * 16 + column]))
					b[r * 16 + column] &= ~(IS_0_VALID << k);
			//col
			for (int c = 0; c < 16; c++)
				if (!FILLED_IN(b[row * 16 + c]))
					b[row * 16 + c] &= ~(IS_0_VALID << k);
			//4x4 block 
			for (int r = 0; r < 4; r++)
				for (int c = 0; c < 4; c++)
					if (!FILLED_IN(b[(r+row-(row%4)) * 16 + (c+column-(column%4))]))
						b[(r + row - (row % 4)) * 16 + (c + column - (column % 4))] &= ~(IS_0_VALID << k);
		}
	}

	int pos_best, low = 17;
	for (int i = 0; i < 256; i++) {
		if (!FILLED_IN(b[i])) {
			int count = countBits(b[i] & VALID_BITS);
			if (count < low) {
				low = count;
				pos_best = i;
			}
		}
	}

	if (low == 17)
		return false; //no empty cells

	b[pos_best] |= IS_FILLED_IN;
	s->push(pos_best);
	return true;
}

void solve(uint32_t* b, Stack<uint32_t>* s) {
	findBest(b, s);
	while (true){
		int k, i = s->peek();

		for (k = 0; k < 16; k++) {
			uint32_t choice = (b[i] & (IS_0_VALID << k));
			if (choice != 0) {
				b[i] &= ~(choice|VALUE_MASK);
				b[i] |= k;
				break;
			}
		}

		if (k >  15) {
			b[i] &= ~IS_FILLED_IN;
			s->pop();
			if (s->isEmpty())
				return;
			continue;
		}
		
		if (!findBest(b, s))
			break;
	}

	//output solution
	DrawBoard(b);
}

int main() {
	char data;
	uint32_t board[256] = { 0 };
	Stack<uint32_t> *stack = new Stack<uint32_t>();

	//Format data
	for (int i = 0; i < 256; i++) {
		cin >> data;
		if (data == '.') {
			board[i] = 0;
		}
		else if (isdigit(data))
			board[i] = (data - '0') | IS_FILLED_IN;
		else
			board[i] = (tolower(data) - 'a'+10) | IS_FILLED_IN;
	}

	solve(board, stack);

	delete stack;
	return 0;
}
