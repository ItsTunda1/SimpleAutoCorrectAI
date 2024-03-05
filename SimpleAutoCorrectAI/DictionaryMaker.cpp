#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "DictionaryMaker.h"





DictionaryMaker::DictionaryMaker(std::string text[], int length)
{

	/*for (int i = 0; i < length; i++)
	{
		dictionary[i] = text[i];
	}*/

}

DictionaryMaker::~DictionaryMaker() {
	delete[] dictionary;
}