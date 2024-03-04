#include <iostream>
#include <map>
using namespace std;

typedef std::map<string, int> BasePairMap;




int main()
{
    string text = "Hello Hi Bye";


    
    BasePairMap dictionary;
    dictionary["Hello"] = 0;
    dictionary["Hi"] = 1;

    std::cout << "Dictionary:" << std::endl;
    std::cout << "Hello:\t" << dictionary["Hello"] << std::endl;
    std::cout << "Hi:\t" << dictionary["Hi"] << std::endl;





    std::cout << "\n\n\nParsed Words:\n";
    string word = "";
    for (int i = 0; i < text.length(); i++)
    {
        word += text[i];
        if (text[i] == ' ')
        {
            std::cout << word << std::endl;
            word = "";
        }

    }
    std::cout << word << std::endl;






	std::cout << "\n\n\n\n\n";
	return 0;
}