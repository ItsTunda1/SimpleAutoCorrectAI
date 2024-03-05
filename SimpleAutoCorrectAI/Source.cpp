#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "DictionaryMaker.cpp"

typedef std::map<std::string, int> BasePairMap;




int main()
{
    std::string text[] = { "I like to talk",
                           "Hi Bye",
                           "Hi Hello"};
    const int wordCount = 7;

    BasePairMap dictionary;
    int dataTable1[wordCount][wordCount] = { {0} };
    int dataTable2[wordCount][wordCount] = { {0} };
    int dataTable3[wordCount][wordCount] = { {0} };
    int dataTable4[wordCount][wordCount] = { {0} };
    int dataTable5[wordCount][wordCount] = { {0} };



    //This is 1 more than the real value stored
    dictionary["Hello"] = 1;
    dictionary["Hi"] = 2;
    dictionary["I"] = 3;
    dictionary["like"] = 4;
    dictionary["to"] = 5;
    dictionary["talk"] = 6;
    dictionary["Bye"] = 7;
    //the be to of and a in that have I it for not on with he as you do at this but his by from they we say her she or an will my one all would their what so up out if about who get which go me when make can like

    std::cout << "Dictionary:" << std::endl;
    std::cout << "Hello:\t" << dictionary["Hello"] << std::endl;
    std::cout << "Hi:\t" << dictionary["Hi"] << std::endl;





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
            wordsEncoded.push_back(dictionary[words[I]] - 1);
            std::cout << words[I] << ":\t" << wordsEncoded[I] << std::endl;
        }





        //Create Data Set 1
        for (int i = 0; i < wordsEncoded.size() - 1; i++)
        {
            if (wordsEncoded[i] > -1)
                dataTable1[wordsEncoded[i]][wordsEncoded[i + 1]]++;
        }

        std::cout << "\nData Table 1:\n";
        for (size_t y = 0; y < 7; y++)
        {
            for (size_t x = 0; x < 7; x++)
            {
                std::cout << dataTable1[x][y];
            }
            std::cout << "\n";
        }



        //Create Data Set 2
        if (wordsEncoded.size() >= 2)
        {
            for (int i = 0; i < wordsEncoded.size() - 2; i++)
            {
                if (wordsEncoded[i] > -1)
                    dataTable2[wordsEncoded[i]][wordsEncoded[i + 2]]++;
            }
        }

        std::cout << "\nData Table 2:\n";
        for (size_t y = 0; y < 7; y++)
        {
            for (size_t x = 0; x < 7; x++)
            {
                std::cout << dataTable2[x][y];
            }
            std::cout << "\n";
        }



        //Create Data Set 3
        if (wordsEncoded.size() >= 3)
        {
            for (int i = 0; i < wordsEncoded.size() - 3; i++)
            {
                if (wordsEncoded[i] > -1)
                    dataTable3[wordsEncoded[i]][wordsEncoded[i + 3]]++;
            }
        }

        std::cout << "\nData Table 3:\n";
        for (size_t x = 0; x < 7; x++)
        {
            for (size_t y = 0; y < 7; y++)
            {
                std::cout << dataTable3[x][y];
            }
            std::cout << "\n";
        }



        //Create Data Set 4
        if (wordsEncoded.size() >= 4)
        {
            for (int i = 0; i < wordsEncoded.size() - 4; i++)
            {
                if (wordsEncoded[i] > -1)
                    dataTable4[wordsEncoded[i]][wordsEncoded[i + 4]]++;
            }
        }

        std::cout << "\nData Table 4:\n";
        for (size_t x = 0; x < 7; x++)
        {
            for (size_t y = 0; y < 7; y++)
            {
                std::cout << dataTable4[x][y];
            }
            std::cout << "\n";
        }



        //Create Data Set 5
        if (wordsEncoded.size() >= 5)
        {
            for (int i = 0; i < wordsEncoded.size() - 5; i++)
            {
                if (wordsEncoded[i] > -1)
                    dataTable5[wordsEncoded[i]][wordsEncoded[i + 5]]++;
            }
        }

        std::cout << "\nData Table 5:\n";
        for (size_t x = 0; x < 7; x++)
        {
            for (size_t y = 0; y < 7; y++)
            {
                std::cout << dataTable5[x][y];
            }
            std::cout << "\n";
        }



    }


    MakeDictionary(text, 3);



    std::cout << "\n\n\n\n\n";
    return 0;
}