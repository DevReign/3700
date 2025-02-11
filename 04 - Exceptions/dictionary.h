#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <cstdint>
#include <stdexcept>

const uint32_t DICTIONARY_SIZE = 100;

class Dictionary
{
private:
	int32_t keys[DICTIONARY_SIZE], values[DICTIONARY_SIZE];
	uint32_t count;

public:
	Dictionary();
	~Dictionary()=default;
	
	bool isEmpty(){ return count == 0;}
	uint32_t size() { return count; }

	void clear(){ count = 0; }
	void insert(uint32_t key, uint32_t value);
	uint32_t search(uint32_t key);

	void remove(uint32_t key);
};

#endif