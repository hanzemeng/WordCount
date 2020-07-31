#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

class Dictionary
{
public:
	unsigned short Count;
	Dictionary* NextChar[26];
	void Init();
};

extern ofstream OutFileAlpha;

void ReadFile(Dictionary*, std::ifstream&);

void AddtoDic(Dictionary*, string, int = 0);

void PrintDic(Dictionary*, std::ofstream& = OutFileAlpha, Node* = StartNode, string = "");
