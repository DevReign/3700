#pragma once

class DisjointSet
{
public:
	DisjointSet(int n);
	~DisjointSet() { delete[] elements; delete[] rank; }

	int find(int a);
	void join(int a, int b);
private:
	int* elements, * rank, count;
};
