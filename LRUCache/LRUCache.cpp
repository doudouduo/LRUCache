#include<iostream>
#include<map>
#include"LRUCache.h"

LRUCache::LRUCache(int cap) {
	capacity = cap;
	head = nullptr;
	tail = nullptr;
}

LRUCache::LRUCache() {
	capacity = 0;
	head = nullptr;
	tail = nullptr;
}

int LRUCache::get(int key) {
	
	if (hmap.find(key) != hmap.end()) {
		DoubleLinkedListNode* node = removeNode(key);
		addNode(node);
		return node->value;
	}
	else return -1;
}

void LRUCache::put(int key, int value) {
	DoubleLinkedListNode* node = new DoubleLinkedListNode(key, value);
	if (hmap.size() < capacity) {
		addNode(node);
	}
	else {
		DoubleLinkedListNode* tnode = removeNode(head->key);
		addNode(node);
		hmap.erase(tnode->key);
		if (hmap.size() == 0) {
			head = nullptr;
			tail = nullptr;
		}
	}
}

DoubleLinkedListNode* LRUCache::removeNode(int key) {
	DoubleLinkedListNode* node = hmap[key];
	if (node == head) {
		if (node->next==node) {
			head = nullptr;
			tail = nullptr;
		}
		else head = node->next;
	}
	else if (node == tail) {
		tail = node->pre;
	}
	else {
		int pre = node->pre->key;
		int next = node->next->key;
		hmap[pre]->next = hmap[next];
		hmap[next]->pre = hmap[pre];
	}
	return node;
}

void LRUCache::addNode(DoubleLinkedListNode* node) {
	if (head == nullptr && tail == nullptr) {
		node->pre = node;
		node->next = node;
		hmap[node->key] = node;
		head = node;
		tail = node;
	}
	else {
		node->pre = tail;
		node->next = node;
		hmap[node->key] = node;
		hmap[tail->key]->next = node;
		tail = node;
	}
}

