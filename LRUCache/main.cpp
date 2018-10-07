#include<iostream>
#include<cstdio>
#include"LRUCache.h"
using namespace std;

int main() {
	LRUCache cache=LRUCache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	cache.put(3, 3);
	cout<<cache.get(1)<<endl;
	cout<<cache.get(3)<<endl;

}

