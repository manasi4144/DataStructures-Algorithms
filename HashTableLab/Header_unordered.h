#pragma once

// Author: Manasi Tirukachi

#include <iostream>
#include <vector>
using namespace std;
#ifndef HEADER_UNORDERED
#define HEADER_UNORDERED

struct node
{
	int key;
	node* next;
};

class chaining
{
public:
	vector <node*> hashtable;
	int m;


	chaining();
	~chaining();

	int initializec(int size);

	//inserting a key into the hash table
	int insertc(int key);

	//searching a key from the hash table 

	int searchc(int key);

	//deleting a key from the hash table 

	int erasec(int key);

	void create_node(int k, int probe);
};
#endif
