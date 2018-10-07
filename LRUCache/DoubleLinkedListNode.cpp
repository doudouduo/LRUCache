#include<iostream>
#include"DoubleLinkedListNode.h"
using namespace std;


DoubleLinkedListNode::DoubleLinkedListNode() {
	key = 0;
	value = 0;
	pre = nullptr;
	next = nullptr;
}

DoubleLinkedListNode::DoubleLinkedListNode(int k,int v) {
	key = k;
	value = v;
	pre = nullptr;
	next = nullptr;
}