#include "Dictionary.h"
#include "Node.h"

ofstream OutFileAlpha;

void Dictionary::Init() 
{
    for(int i = 0; i < 26; i++)
    {
        Count = 0;
        NextChar[i] = NULL;
    }
}

void ReadFile(Dictionary* Dict, std::ifstream& InputFile)
{
    if(InputFile.is_open())
    {
        std::cout << "File Opened" << "\n";
        string Sentence;
        while(std::getline(InputFile, Sentence))
        {
            string Word;
            for(int i = 0; i < Sentence.size(); i++)
            {
                if(tolower(Sentence[i]) != toupper(Sentence[i]))
                {
                    Word += tolower(Sentence[i]);
                }
                else
                {
                    if(39 == int(Sentence[i]))
                    {
                        i++;
                    }
                    if("" != Word)
                    {
                        AddtoDic(Dict, Word);
                    }
                    Word = "";
                }
            }
        }
    }
    else
    {
        std::cout << "File Did NOT Open" << "\n";
    }
}

void AddtoDic(Dictionary* Dict, string Word, int Count)
{
    char Char = Word[Count];
    int8_t Index = int(Char) - 97;
    if(NULL == Dict->NextChar[Index])
    {
        Dictionary* NextDic = new Dictionary;
        NextDic->Init();
        Dict->NextChar[Index] = NextDic;
    }
    if(Count + int32_t(1) < int32_t(Word.size()))
    {
        AddtoDic(Dict->NextChar[Index], Word, Count + 1);
    }
    else
    {
        if(Dict->NextChar[Index]->Count < 65535)
        {
            Dict->NextChar[Index]->Count++;
        }
    }
    return;
}

void PrintDic(Dictionary* Dic, std::ofstream& OutFile, Node* Sort, string Word)
{
    for(int8_t i = 0; i < 26; i++)
    {
        if(Dic->Count > 0)
        {
            OutFile << Dic->Count << "   " << Word << " \n" << "\n";
            AddNode(Dic->Count, Word);
            Dic->Count = 0;
        }
        if(NULL != Dic->NextChar[i])
        {
            Word += char(i + 97);
            PrintDic(Dic->NextChar[i], OutFile, Sort, Word);
            Word.pop_back();
        }
    }
    return;
}