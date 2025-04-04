#include "disjointSet.h"

DisjointSet::DisjointSet(int n)
{
	elements = new int[n];
	rank = new int[n];
	count = n;

	for (int i = 0; i < n; i++) {
		elements[i] = i;
		rank[i] = 0;
	}
}
int DisjointSet::find(int a) {
	if (elements[a] != a)
		elements[a] = find(a);
	return elements[a];
}
void DisjointSet::join(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		if (rank[a] < rank[b]) {
			elements[a] = b;
		}
		else {
			if (rank[a] = rank[b]) {
				rank[a] = rank[a] + 1;
			}
			elements[b] = a;
		}
	}
}