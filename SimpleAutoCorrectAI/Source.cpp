#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include "DictionaryMaker.h"

typedef std::map<std::string, int> BasePairMap;



int ReadDictionary(std::string input, std::string dictionary[], int wordCount);
void CreateDataSet(std::vector<int> wordsEncoded, int*** dataTable, int wordCount, int scope, int sentence);
std::vector<std::string> ConvertFileToStringArray(std::string fileName);
std::string getInput();
std::vector<std::string> separateWords(std::string input);
//std::vector<std::string> SentenceToWords(std::string sentence);
std::vector<std::string> CheckForRepeatsInDict(std::string* dict, int wordCount);


int main()
{
    srand((int)time(0));
    bool showStats = false;
    bool checkMissing = false;



    /*std::string text[] = {"we can have this",
                           "ask why men change",
                           "together why children begin",
                           "long ago I ran dry",
                           "they have some other number",
                           "I ran dry of some other number"};*/

    std::vector<std::string> text;
    text = ConvertFileToStringArray("100sentences.txt");
    int sentenceSamples = 628;



    
    // Dictionary Setup

    //the be to of and a in that have I it for not on with he as you do at this but his by from they we say her she or an will my one all would their what so up out if about who get which go me when make can like
    std::string input = "";
    std::ifstream MyReadFile("1-1000.txt");

    // Use a while loop together with the getline() function to read the file line by line
    std::string temp;
    int lengthFile = 0;
    while (getline(MyReadFile, temp)) {
        // Output the text from the file
        lengthFile++;
    }
    MyReadFile.close();
    MyReadFile.open("1-1000.txt");
    for (size_t i = 0; i < lengthFile - 1; i++)
    {
        getline(MyReadFile, temp);
        input += (temp + ' ');
    }
    getline(MyReadFile, temp);
    input += temp;
    MyReadFile.close();



    const int wordCount = lengthFile;
    DictionaryMaker dictionaryMaker = DictionaryMaker(input);
    std::string* dictionary = dictionaryMaker.dictionary;
    /*for (size_t i = 0; i < wordCount; i++)
    {
        std::cout << dictionary[i] << std::endl;
    }*/

    //Check for repeating words in the dictionary
    //CheckForRepeatsInDict(dictionary, wordCount);



    // Layers of data tables
    int*** dataTable = new int**[wordCount];
    for (size_t i = 0; i < wordCount; i++)
    {
        dataTable[i] = new int* [wordCount];
        for (size_t j = 0; j < wordCount; j++)
        {
            dataTable[i][j] = new int[5];
            for (size_t k = 0; k < 5; k++)
            {
                dataTable[i][j][k] = 0;
            }
        }
    }



    //For missing words
    std::vector<std::string> missingWords;








    for (int setI = 0; setI < sentenceSamples; setI++)
    {



        std::string word = "";
        std::vector<std::string> words;

        if (showStats == true)
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
        if (showStats == true)
        {
            std::cout << "\n\n\nParsed Words:\n";
            for (auto item : words)
            {
                std::cout << item << std::endl;
            }
        }



        //Convert to Dictionary Values
        std::vector<int> wordsEncoded;
        for (int I = 0; I < words.size(); I++)
        {
            wordsEncoded.push_back(ReadDictionary(words[I], dictionary, wordCount));

            if (showStats == true)
                std::cout << words[I] << ":\t" << wordsEncoded[I] << std::endl;

            if (wordsEncoded[I] < 0)
                missingWords.push_back(words[I]);
        }






        //Create Data Sets
        if (checkMissing == false)
        {
            for (size_t i = 1; i <= 5; i++)
            {
                CreateDataSet(wordsEncoded, dataTable, wordCount, i, setI);
            }
        }



    }



    std::cout << "Missing Words:" << std::endl;
    for (int i = 0; i < missingWords.size(); i++)
    {
        std::cout << missingWords[i] << std::endl;
    }
    if (missingWords.size() == 0)
        std::cout << "None" << std::endl;




    

    //User input (filter size)
    int filterSize = 1;
    std::cout << "\n\n\nFilter Size (1-5): ";
    std::cin >> filterSize;
    if (filterSize > 5 || filterSize < 1)
    {
        filterSize = 1;
        std::cout << "Cannot accept, setting to " << filterSize << std::endl;
    }

    //Ask to find the next word
    std::string inputWords;
    while(inputWords != "Exit")
    {

        //User input
        std::cout << "\nInput a word to find the next possible words: ";
        
        //Seperate out the words
        std::vector<std::string> sentence;
        sentence = separateWords(getInput());



        //Until the sentence is finished (bounded by a size)
        int maxBound = 100;
        for (size_t i = 0; i < maxBound; i++)
        {
            std::vector<int> parsedInput;
            int errorCount = 0;
            for (size_t wordI = 0; wordI < sentence.size(); wordI++)
            {
                parsedInput.push_back(ReadDictionary(sentence[wordI], dictionary, wordCount));

                if (parsedInput[wordI] == -1)
                {
                    std::cout << "'" << sentence[wordI] << "'" << " does NOT exist in the dictionary" << std::endl;
                    errorCount++;
                }
            }

            if (errorCount > 0)
                break;

            //Generate a sentence
            std::vector<std::string> possibleWords;
            for (size_t i = 0; i < wordCount; i++)
            {

                //Check all parts of the input (layer limit)
                bool checked = true;
                for (size_t wordIndex = 0; wordIndex < filterSize; wordIndex++)
                {
                    if (parsedInput.size() <= wordIndex)     //Is this layer check possible given the size of the sentence?
                    {
                        break;
                    }

                    if (dataTable[parsedInput[parsedInput.size() - wordIndex - 1]][i][wordIndex] == 0)
                        checked = false;
                }
                if (checked == true)
                    possibleWords.push_back(dictionary[i]);



            }

            

            //Stop when done
            if (possibleWords.size() == 0)
            {
                //Stop
                break;
            }

            //Pick a random word                                        <<------ ADD BETTER PROPABILITIES
            int random = rand() % possibleWords.size();
            //words.push_back(possibleWords[random]);
            sentence.push_back(possibleWords[random]);
            possibleWords.clear();

        }

        //Print the sentence
        for (int i = 0; i < (int)sentence.size() - 1; i++)
        {
            std::cout << sentence[i] << " ";
        }
        if (sentence.size() > 0)
            std::cout << sentence[sentence.size() - 1];
        std::cout << "." << std::endl;


    }






    delete[] dataTable;

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



void CreateDataSet(std::vector<int> wordsEncoded, int*** dataTable, int wordCount, int scope, int sentence)
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

    //std::cout << "\nData Table " << scope << ":\n";
    /*if (scope == 1 && sentence == 5)
    {
        for (size_t x = 0; x < wordCount; x++)
        {
            for (size_t y = 0; y < wordCount; y++)
            {
                std::cout << dataTable[x][y][scope - 1];
            }
            std::cout << "\n";
        }
    }*/
}




std::vector<std::string> ConvertFileToStringArray(std::string fileName)
{
    std::vector<std::string> data;

    std::ifstream MyReadFile(fileName);

    // Use a while loop together with the getline() function to read the file line by line
    std::string temp;
    while (getline(MyReadFile, temp)) {
        // Output the text from the file
        data.push_back(temp);
    }
    MyReadFile.close();

    return data;
}



std::vector<std::string> separateWords(std::string input) {
    //create vector
    std::vector<std::string> words;
    
    //create string stream
    std::stringstream ss;
    
    //make sure its empty
    ss.clear();
    ss.str("");
    
    //give to ss
    ss << input;
    
    //go thru each word
    std::string temp = "";
    while(std::getline(ss, temp, ' ')) {
        //push to vector
        words.push_back(temp);
    }
    
    return words;
}


std::string getInput() {
    //inputted string
    std::string input = "";
    
    //get input and give it to string
    std::getline(std::cin, input);
    
    return input;
}


std::vector<std::string> CheckForRepeatsInDict(std::string* dict, int wordCount)
{
    std::vector<std::string> allwords;

    for (size_t i = 0; i < wordCount; i++)
    {
        allwords.push_back(dict[i]);
    }


    std::cout << "Repeated words:\n" << std::endl;

    //For every entry
    for (size_t i = 0; i < allwords.size(); i++)
    {
        std::string curWord = allwords[i];

        for (size_t j = i + 1; j < allwords.size(); j++)
        {
            //Find if it exists
            if (curWord == allwords[j])
            {
                allwords.erase(std::next(allwords.begin(), j));
            }
        }
    }

    for (size_t i = 0; i < allwords.size(); i++)
    {
        std::cout << allwords[i] << std::endl;
    }

    return allwords;
}