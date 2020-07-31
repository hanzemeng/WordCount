#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <fstream>


class Node
{
	public:
		int Frequence;
		string Name;
		Node* LeftNode;
		Node* RightNode;
};

class List
{
	public:
		int Frequence;
		string Name;
		List* Next;
};

extern ofstream OutFileNumer;
extern Node* StartNode;

void AddNode(int, string, Node* = StartNode);
void InitList();
void AddList(int, string, List* = NULL);
void PrintAllList();
void PrintList(std::ofstream&, List* = NULL);
void PrintNode(std::ofstream& = OutFileNumer, Node* = StartNode);