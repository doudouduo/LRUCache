#pragma once
#include<iostream>
using namespace std;

class DoubleLinkedListNode
{
public:
	int key;
	int value;
	DoubleLinkedListNode* pre;
	DoubleLinkedListNode* next;
	DoubleLinkedListNode();
	DoubleLinkedListNode(int k, int v);
};
