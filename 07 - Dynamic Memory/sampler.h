#pragma once
#include <iostream>
#include <random>

class Sampler
{
public:
	Sampler(uint32_t n);
	~Sampler(){ delete[] elements; }
	uint32_t getSample();
private:
	uint32_t* elements;
	uint32_t count;
	std::mt19937* mt;
};
