#include "Node.h"

ofstream OutFileNumer;

Node* StartNode;
const int ListNum = 9;
List* AllList[ListNum];


void AddNode(int Count, string Word, Node* CurrentNode)
{
	if(1 == Count)
	{
		OutFileNumer << Count << "   " << Word << " \n" << "\n";
		return;
	}
	else if(Count < 11)
	{
		AddList(Count, Word, AllList[Count - 2]);
		return;
	}
	if(NULL == StartNode)
	{
		StartNode = new Node;
		StartNode->Frequence = Count;
		StartNode->Name = Word;
		StartNode->LeftNode = NULL;
		StartNode->RightNode = NULL;
	}
	else
	{
		if(Count < CurrentNode->Frequence)
		{
			if(NULL != CurrentNode->LeftNode)
			{
				AddNode(Count, Word, CurrentNode->LeftNode);
			}
			else
			{
				Node* NewNode = new Node;
				NewNode->Frequence = Count;
				NewNode->Name = Word;
				NewNode->LeftNode = NULL;
				NewNode->RightNode = NULL;
				CurrentNode->LeftNode = NewNode;
			}
		}
		else
		{
			if(NULL != CurrentNode->RightNode)
			{
				AddNode(Count, Word, CurrentNode->RightNode);
			}
			else
			{
				Node* NewNode = new Node;
				NewNode->Frequence = Count;
				NewNode->Name = Word;
				NewNode->LeftNode = NULL;
				NewNode->RightNode = NULL;
				CurrentNode->RightNode = NewNode;
			}
		}
	}
}

void InitList()
{
	for(int i = 0; i < ListNum;i++)
	{
		AllList[i] = NULL;
	}
}

void AddList(int Count, string Word, List* CurrentList)
{
	List* NewList = new List;
	NewList->Frequence = Count;
	NewList->Name = Word;
	NewList->Next = AllList[Count - 2];
	AllList[Count - 2] = NewList;
}
void PrintAllList()
{
	for(int i = 0;i < ListNum;i++)
	{
		if(NULL != AllList[i])
		{
			PrintList(OutFileNumer, AllList[i]);
		}
	}
}
void PrintList(std::ofstream& OutFile, List* CurrentList)
{
	if(NULL != CurrentList->Next)
	{
		PrintList(OutFile, CurrentList->Next);
	}
	OutFile << CurrentList->Frequence << "   " << CurrentList->Name << " \n" << "\n";
}

void PrintNode(std::ofstream& OutFile, Node* CurrentNode)
{
	if(NULL != CurrentNode->LeftNode)
	{
		PrintNode(OutFile, CurrentNode->LeftNode);
	}
	OutFile << CurrentNode->Frequence << "   " << CurrentNode->Name << " \n" << "\n";
	if(NULL != CurrentNode->RightNode)
	{
		PrintNode(OutFile, CurrentNode->RightNode);
	}
}