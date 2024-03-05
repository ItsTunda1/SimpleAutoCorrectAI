#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "DictionaryMaker.h"

typedef std::map<std::string, int> BasePairMap;



int ReadDictionary(std::string input, std::string dictionary[], int wordCount);


int main()
{
    std::string text[] = { "the I a am",
                           "I am",
                           "the"};



    
    // Dictionary Setup

    //the be to of and a in that have I it for not on with he as you do at this but his by from they we say her she or an will my one all would their what so up out if about who get which go me when make can like
    std::string input = "the I a am";
    const int wordCount = 4;
    DictionaryMaker dictionaryMaker = DictionaryMaker(input);
    std::string* dictionary = dictionaryMaker.dictionary;
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << dictionary[i] << std::endl;
    }



    // Layers of data tables
    int dataTable[wordCount][wordCount][5] = {{0}};








    for (int setI = 0; setI < 3; setI++)
    {



        std::string word = "";
        std::vector<std::string> words;
        std::cout << "\nText: " << text[setI] << std::endl;
        for (int i = 0; i < text[setI].length(); i++)
        {
            if (text[setI][i] == ' ')
            {
                words.push_back(word);
                word = "";
                continue;
            }

            word += text[setI][i];

        }
        words.push_back(word);



        //Print the words
        std::cout << "\n\n\nParsed Words:\n";
        /*for (auto item : words)
        {
            std::cout << item << std::endl;
        }*/



        //Convert to Dictionary Values
        std::vector<int> wordsEncoded;
        for (int I = 0; I < words.size(); I++)
        {
            wordsEncoded.push_back(ReadDictionary(words[I], dictionary, wordCount));
            std::cout << words[I] << ":\t" << wordsEncoded[I] << std::endl;
        }





        //Create Data Set 1
        for (int i = 0; i < wordsEncoded.size() - 1; i++)
        {
            if (wordsEncoded[i] > -1)
                dataTable[wordsEncoded[i]][wordsEncoded[i + 1]][0]++;
        }

        std::cout << "\nData Table 1:\n";
        for (size_t y = 0; y < wordCount; y++)
        {
            for (size_t x = 0; x < wordCount; x++)
            {
                std::cout << dataTable[x][y][0];
            }
            std::cout << "\n";
        }



        //Create Data Set 2
        if (wordsEncoded.size() >= 2)
        {
            for (int i = 0; i < wordsEncoded.size() - 2; i++)
            {
                if (wordsEncoded[i] > -1)
                    dataTable[wordsEncoded[i]][wordsEncoded[i + 2]][1]++;
            }
        }

        std::cout << "\nData Table 2:\n";
        for (size_t y = 0; y < wordCount; y++)
        {
            for (size_t x = 0; x < wordCount; x++)
            {
                std::cout << dataTable[x][y][1];
            }
            std::cout << "\n";
        }



        //Create Data Set 3
        if (wordsEncoded.size() >= 3)
        {
            for (int i = 0; i < wordsEncoded.size() - 3; i++)
            {
                if (wordsEncoded[i] > -1)
                    dataTable[wordsEncoded[i]][wordsEncoded[i + 3]][2]++;
            }
        }

        std::cout << "\nData Table 3:\n";
        for (size_t x = 0; x < wordCount; x++)
        {
            for (size_t y = 0; y < wordCount; y++)
            {
                std::cout << dataTable[x][y][2];
            }
            std::cout << "\n";
        }



        //Create Data Set 4
        if (wordsEncoded.size() >= 4)
        {
            for (int i = 0; i < wordsEncoded.size() - 4; i++)
            {
                if (wordsEncoded[i] > -1)
                    dataTable[wordsEncoded[i]][wordsEncoded[i + 4]][3]++;
            }
        }

        std::cout << "\nData Table 4:\n";
        for (size_t x = 0; x < wordCount; x++)
        {
            for (size_t y = 0; y < wordCount; y++)
            {
                std::cout << dataTable[x][y][3];
            }
            std::cout << "\n";
        }



        //Create Data Set 5
        if (wordsEncoded.size() >= 5)
        {
            for (int i = 0; i < wordsEncoded.size() - 5; i++)
            {
                if (wordsEncoded[i] > -1)
                    dataTable[wordsEncoded[i]][wordsEncoded[i + 5]][4]++;
            }
        }

        std::cout << "\nData Table 5:\n";
        for (size_t x = 0; x < wordCount; x++)
        {
            for (size_t y = 0; y < wordCount; y++)
            {
                std::cout << dataTable[x][y][4];
            }
            std::cout << "\n";
        }



    }




    std::cout << "\n\n\n\n\n";
    return 0;
}






/*void MakeDictionary(std::string text[], int length)
{
    //std::string* dictionary = new std::string[length];



    for (int i = 0; i < length; i++)
    {
        dictionary1[i] = text[i];
    }


    //delete[] dictionary;
}*/




int ReadDictionary(std::string input, std::string dictionary[], int wordCount)
{
    for (int i = 0; i < wordCount; i++)
    {
        if (input == dictionary[i])
            return i;
    }

    return -1;
}



void CreateDataSet(std::vector<int> wordsEncoded, int dataTable[1][1][1], int wordCount, int scope)
{

    //Create Data Set
    if (wordsEncoded.size() >= scope)
    {
        for (int i = 0; i < wordsEncoded.size() - scope; i++)
        {
            if (wordsEncoded[i] > -1)
                dataTable[wordsEncoded[i]][wordsEncoded[i + scope]][scope - 1]++;
        }
    }

    std::cout << "\nData Table " << scope << ":\n";
    for (size_t x = 0; x < scope; x++)
    {
        for (size_t y = 0; y < wordCount; y++)
        {
            std::cout << dataTable[x][y][scope - 1];
        }
        std::cout << "\n";
    }
}