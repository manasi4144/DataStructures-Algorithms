#pragma once

// Author: Manasi Tirukachi

#include <iostream>
#include <vector>
using namespace std;
#ifndef HEADER_H
#define HEADER_H

//class for linear probing
struct node
{
	int key;
	bool nul;
};
class linearprob
{
public:
	vector <node*> hashtable;
	int m;
	int full;
	linearprob();
	~linearprob();

	int initialize(int size);

	//inserting a key into the hash table
	int insert(int key);

	//searching a key from the hash table 

	int search(int key);

	//deleting a key from the hash table 

	int erase(int key);
};
#endif
