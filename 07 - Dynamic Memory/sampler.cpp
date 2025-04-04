#include "sampler.h"

Sampler::Sampler(uint32_t n) {
	std::random_device rd;
	mt = new std::mt19937(rd());
	
	elements = new uint32_t[n];
	count = n;

	for (uint32_t i = 0; i < n; i++)
		elements[i] = i;
}

uint32_t Sampler::getSample() {
	if (count < 1)
		throw std::underflow_error("sampler count is < 0. ");

	std::uniform_int_distribution<uint32_t> dis(0, count - 1);
	uint32_t i = dis(*mt);//rand() % count;
	uint32_t e = elements[i];
	count--;
	elements[i] = elements[count];
	return e;
}
