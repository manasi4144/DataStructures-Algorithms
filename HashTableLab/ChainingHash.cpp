
#include "Header_unordered.h"

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <string> 
#include <sstream>
#include <math.h>

using namespace std;


chaining::chaining()
{
	this->m = 0;
}

chaining::~chaining()
{
	hashtable.clear();
}

int chaining::initializec(int size)
{

	this->m = size;

	//clears all the previous existing data elements before adding new ones
	this->hashtable.clear();

	//place the first head node in each cell of the table
	for (int i = 0; i < size; i++)
	{
		node* head;
		head = new node;
		head->next = NULL;
		head->key = -1;
		hashtable.push_back(head);
	}

	return 1;

}

//function to create nodes 
void chaining::create_node(int k, int probe)
{
	node* temp = hashtable[probe];

	//checking is head or not 
	if (temp->key == -1 && temp->next == NULL)
	{
		//creating the head
		temp = new node;
		temp->key = k;
		temp->next = NULL;
		hashtable[probe] = temp;
	}
	else if (temp->key == -1 && temp->next != NULL)
	{
		hashtable[probe]->key = k;
	}
	else
	{
		//not head, adding to the list
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new node;
		temp = temp->next;
	}

	//setting the values
	temp->key = k;
	temp->next = NULL;
}

//inserting a key into the hash table
int chaining::insertc(int k)
{
	//check to make sure that key isn't already there
	int result = this->searchc(k);

	if (result < this->m)
	{
		return 0; //failure
	}

	int probe = k % m;

	//cout << "probe:" << probe << endl;

	this->create_node(k, probe);

	return 1;

}

//searching a key from the hash table 

int chaining::searchc(int k)
{
	//go through just one element of the vector table to find it

	int probe = k % m;

	node* temp = hashtable[probe];

	if (temp->key == k)
	{
		return probe;
	}

	while (true)
	{
		if (temp->key == k)
		{
			return probe;
			break;
		}
		if (temp->next == NULL)
		{
			return this->m + 1;
			break;
		}
		temp = temp->next;
	}

	return this->m + 1;
}

//deleting a key from the hash table 

int chaining::erasec(int k)
{
	//check to make sure that key is there
	int result = this->searchc(k);

	if (result > this->m)
	{
		return 1;
		//failure case
	}

	node* temp = hashtable[result];

	//if deleting head
	if (temp->key == k)
	{
		hashtable[result]->key = -1;
		return 0;
	}

	node* current = temp->next;

	while (current->next != NULL)
	{
		if (current->key == k)
		{
			temp->next = current->next;
			return 0;
		}

		current = current->next;
		temp = temp->next;
	}

	temp->next = NULL;
	return 0;

}

//MAIN FOR CHAINING

int main()
{

	//declaring variables
	int m;
	string input;
	string word;
	int key;

	chaining hash;

	while (getline(cin, input))
	{
		//get single line
		stringstream eachline(input);

		getline(eachline, word, ' ');

		//INSERT FUNCTION
		if (word == "i")
		{
			//cout << "insert" << endl;
			getline(eachline, word, ' ');
			key = stoi(word);

			int result = 0;

			result = hash.insertc(key);

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

			int result = hash.initializec(m);

			cout << "success" << endl;
		}

		//SEARCH FUNCTION
		else if (word == "s")
		{
			getline(eachline, word, ' ');
			key = stoi(word);

			int result;

			result = hash.searchc(key);

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

			result = hash.erasec(key);

			if (result == 1)
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

