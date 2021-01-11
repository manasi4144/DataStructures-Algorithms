// hash2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Manasi Tirukachi
#include "header.h"

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <string> 
#include <sstream>
#include <math.h>

using namespace std;

linearprob::linearprob()
{
	this->m = 0;
	this->full = 0;
	//m is the size of the hash table
	//start by inserting m spaces into the hash table

}

linearprob::~linearprob()
{
	//clearing the entire list
	hashtable.clear();
}

int linearprob::initialize(int size)
{

	this->m = size;


	//clears all the previous existing data elements before adding new ones
	this->hashtable.clear();

	for (int i = 0; i < size; i++)
	{
		node *temp = new node;
		temp->key = -1;
		temp->nul = true;
		hashtable.push_back(temp);
	}

	return 1;
}

int linearprob::insert(int key)
{

	int s = this->search(key); //check this correctly

	//search shows that the key exists
	if (s < this->m)
	{
		return 0;
	}

	//check if table is full

	else if (this->full == this->m)
	{
		return 0;
	}

	//if not full and key not already present
	else
	{
		//find the probe number
		int probe = key % this->m;
		while (true)
		{
			//check through the hash table to find a non-occupied spot
			if (this->hashtable[probe]->key != -1)
			{
				probe = probe + 1;
				if (probe >= this->m)
				{
					probe = 0;
				}
			}
			else
			{
				break;
			}
		}
		this->full++;
		this->hashtable[probe]->key = key;
		hashtable[probe]->nul = false;

		return 1;
	}

	return 1;
	//returns 1 for success and 0 for failure
}


int linearprob::search(int key)
{
	//search for the key to see if it already exists
	int probe = key % this->m;
	int count = 0;

	while(count < this->m)
	{
		if ((this->hashtable[probe]->key == key))
		{
			return probe;
		}

		else if (this->hashtable[probe]->nul == true)
		{
			break;
		}

		probe = probe + 1;
		count++;

		if (probe >= this->m)
		{
			probe = 0;
		}

	}

	int r = this->m + 1;
	return r;
}

int linearprob::erase(int key)
{
	int result = this->search(key);

	if (result > this->m)
	{
		return 0;
	}

	else
	{
		this->hashtable[result]->key = -1;
	}

	full--;
	return 1;

	//return 1 for success and 0 for failure
}


//MAIN FUNCTION

int main()
{

	//declaring variables
	int m;
	string input;
	string word;
	int key;

	linearprob hash;

	while (getline(cin, input))
	{
		//get single line
		stringstream eachline(input);

		getline(eachline, word, ' ');

		//INSERT FUNCTION
		if (word == "i")
		{
			getline(eachline, word, ' ');
			key = stoi(word);

			int result = 0;

			result = hash.insert(key);

			if (result == 0)
			{
				//failure case
				cout << "failure" << endl;
			}
			else
			{
				//success case
				cout << "success" << endl;
			}
		}

		//INITIALIZE
		else if (word == "n")
		{
			getline(eachline, word, ' ');
			m = stoi(word);

			int result = hash.initialize(m);

			cout << "success" << endl;
		}

		//SEARCH FUNCTION
		else if (word == "s")
		{
			getline(eachline, word, ' ');
			key = stoi(word);

			int result = 0;

			result = hash.search(key);

			if (result > hash.m)
			{
				//failure case
				cout << "not found " << endl;
			}
			else
			{
				//success case
				cout << "found in " << result << endl;
			}

		}

		//ERASE FUNCTION
		else if (word == "d")
		{
			getline(eachline, word, ' ');
			key = stoi(word);

			int result = 0;

			result = hash.erase(key);

			if (result == 0)
			{
				//failure case
				cout << "failure " << endl;
			}
			else
			{
				//success case
				cout << "success" << endl;
			}

		}

	}
	return 0;
}



