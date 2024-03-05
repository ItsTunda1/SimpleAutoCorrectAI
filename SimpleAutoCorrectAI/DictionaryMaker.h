#ifndef DICTIONARYMAKER_H
#define DICTIONARYMAKER_H

#include <iostream>


class DictionaryMaker {

	private:
		std::string* dictionary;

	DictionaryMaker(std::string text[], int length);
	~DictionaryMaker();
};





#endif