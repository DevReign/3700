#include "dictionary.h"

Dictionary::Dictionary(){
	count = 0;
}
//bool Dictionary::isEmpty(){ return count = 0;}
//uint32_t Dictionary::size() { return count; }
//void Dictionary::clear(){ count = 0; }

void Dictionary::insert(uint32_t key, uint32_t value){
	for (int i = 0; i < count; ++i)
	{
		if(keys[i]==key){
			values[i]=value;
			return;
		}
	}

	if(count == DICTIONARY_SIZE){
		throw std::overflow_error("insert: Key not found");
	}

	keys[count] =key;
	values[count]=value;
	count++;
}


uint32_t Dictionary::search(uint32_t key){
	for (int i = 0; i < count; ++i)
	{
		if(keys[i]==key){
			return values[i];
		}
	}
	throw std::domain_error("search: Key not found");
}

void Dictionary::remove(uint32_t key){
	for (int i = 0; i < count; ++i)
	{
		if(keys[i]==key){
			count -= 1;
			keys[i] = keys[count];
			values[i]=values[count];
			return;
		}
	}
	throw std::domain_error("remove: Key not found");
}
