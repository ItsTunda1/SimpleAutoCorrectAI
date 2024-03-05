#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "DictionaryMaker.h"





DictionaryMaker::DictionaryMaker(std::string text): dictionary(new std::string[text.length()])
{

    // Convert a words to a list of words
    std::string word = "";
    int index = 0;
    int length = text.length();
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            dictionary[index] = word;
            index++;

            word = "";
            continue;
        }

        word += text[i];
    }
    this->dictionary[index] = word;
}

DictionaryMaker::~DictionaryMaker() {
	delete[] this->dictionary;
}