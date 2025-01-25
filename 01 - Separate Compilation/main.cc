#include "lab1.h"

const int MAX_SIZE = 100000;

int readData(int [], int);
void sortData(int [], int);
void printData(int [], int);

int main(void) {
  int data[MAX_SIZE],nItems;

  nItems = readData(data,MAX_SIZE);
  sortData(data,nItems);
  printData(data,nItems);

  return 0;
}
