#include <iostream>
#include <map>
#include <vector>
#include <string>





void MakeDictionary(std::string text[], int length)
{
	std::string* dictionary = new std::string[length];



	for (int i = 0; i < length; i++)
	{
		dictionary[i] = text[i];
	}


	delete[] dictionary;
}