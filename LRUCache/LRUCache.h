#include<iostream>
#include<map>
#include"DoubleLinkedListNode.h"
using namespace std;

class LRUCache {
public:
	int capacity;
	DoubleLinkedListNode* head;
	DoubleLinkedListNode* tail;
	map<int,DoubleLinkedListNode*>hmap;
	LRUCache();
	LRUCache(int cap);

	int get(int key);

	void put(int key, int value);

private:
	DoubleLinkedListNode* removeNode(int key);

	void addNode(DoubleLinkedListNode* node);
};