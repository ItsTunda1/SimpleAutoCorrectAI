#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

typedef std::map<string, int> BasePairMap;




int main()
{
    string text = "Hello Hi Bye";
    const int wordCount = 2;

    BasePairMap dictionary;
    int dataTable[wordCount][wordCount] = { {0} };



    dictionary["Hello"] = 0;
    dictionary["Hi"] = 1;

    std::cout << "Dictionary:" << std::endl;
    std::cout << "Hello:\t" << dictionary["Hello"] << std::endl;
    std::cout << "Hi:\t" << dictionary["Hi"] << std::endl;





    string word = "";
    list<string> words;
    for (int i = 0; i < text.length(); i++)
    {
        word += text[i];
        if (text[i] == ' ')
        {
            words.push_back(word);
            word = "";
        }

    }
    words.push_back(word);



    //Print the words
    std::cout << "\n\n\nParsed Words:\n";
    for (auto item : words)
    {
        std::cout << item << std::endl;
    }



    //Convert to Dictionary Values
    /*int wordsEncoded[words.size()];
    for (int i = 0; i < words.size(); i++)
    {
        wordsEncoded[i] = dictionary[words[i]];
    }*/






	std::cout << "\n\n\n\n\n";
	return 0;
}