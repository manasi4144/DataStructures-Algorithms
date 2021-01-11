// TreeQuad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//packages declaration
#include <iostream>
#include <string.h>
#include <string> 
#include<stdio.h>
#include <sstream>
#include "Header.h"
using namespace std;

//GLOBAL variables
int val = 0; //for the min, max and total
int sizee = 0; //for the size of the tree

quadtree::quadtree()
{
	//initializing all pointers to NULL
	this->root = NULL;
	this->se = NULL;
	this->ne= NULL;
	this->nw= NULL;
	this->sw= NULL;

}

quadtree::~quadtree()
{
	//what should happen here?
}

void quadtree::insert(string cityname, double x, double y, int p, int r, int sal)
{
	if (this->root == NULL)
	{
		//create new node here
		node* sample = new node;
		sample->name = cityname;
		sample->x = x;
		sample->y = y;
		sample->p = p;
		sample->r = r;
		sample->sal = sal;

		this->root = sample;
		sizee++;
		return;
	}

	//check if co-ordinates match the ne child
	if (x >= this->root->x && y > this->root->y)
	{
		if (this->ne == NULL)
		{
			this->ne = new quadtree();

		}
		return this->ne->insert(cityname, x, y, p, r, sal);
	}
	//check if co-ordinates match the nw child
	else if (x < this->root->x && y >= this->root->y)
	{
		if (this->nw == NULL)
		{
			this->nw = new quadtree();
		}

		return this->nw->insert(cityname, x, y, p, r, sal);
	}
	//check if co-ordinates match the sw child
	else if (x <= this->root->x && y < this->root->y)
	{
		if (this->sw == NULL)
		{
			this->sw = new quadtree();
		}

		return this->sw->insert(cityname, x, y, p, r, sal);
	}

	//check if co-ordinates match the se child

	else if (x > this->root->x && y <= this->root->y)
	{
		if (this->se == NULL)
		{
			this->se = new quadtree();
		}
		return this->se->insert(cityname, x, y, p, r, sal);
	}
	return;
}

string quadtree::search(double x, double y)
{
	//check the root
	if (this->root == NULL)
	{
		return "not found";
	}
	//check the root
	if (this->root->x == x && this->root->y == y)
	{
		return this->root->name;
	}

	//check if co-ordinates match the ne child
	else if (x >= this->root->x && y > this->root->y)
	{
		if (this->ne == NULL)
		{
			return "not found";
		}
		return this->ne->search(x, y);
	}

	//check if co-ordinates match the nw child
	else if (x < this->root->x && y >= this->root->y)
	{
		if (this->nw == NULL)
		{
			return "not found";
		}
		return this->nw->search(x, y);
	}

	//check if co-ordinates match the sw child
	else if (x <= this->root->x && y < this->root->y)
	{
		if (this->sw == NULL)
		{
			return "not found";
		}
		return this->sw->search(x, y);
	}

	//check if co-ordinates match the se child
	else if (x > this->root->x && y <= this->root->y)
	{
		if (this->se == NULL)
		{
			return "not found";
		}
		return this->se->search(x, y);
	}

	return "not found";
}

int quadtree::q_search(double x, double y, string d, string attr, string type)
{
	if (this->root == NULL)
	{
		return -1;
	}

	if (this->root->x == x && this->root->y == y)
	{
		//find the type required
		if (type == "min")
		{
			 val = -1; //indicator that this is first round
			 //find the direction
			if (d == "NE")
			{
				if (this->ne == NULL)
				{
					return -1;
				}
				 this->ne->q_min(attr);
				 return val;
			}
			else if (d == "NW")
			{
				if (this->nw == NULL)
				{
					return -1;
				}

				 this->nw->q_min(attr);
				 return val;

			}
			else if (d == "SW")
			{
				if (this->sw == NULL)
				{
					return -1;
				}
				 this->sw->q_min(attr);
				 return val;
			}
			else if (d == "SE")
			{
				if (this->se == NULL)
				{
					return -1;
				}
				 this->se->q_min(attr);
				 return val;
			}
			else
			{
				return -1;
			}

		}
		//find the type
		else if (type == "max")
		{
			//find the direction
			if (d == "NE")
			{
				if (this->ne == NULL)
				{
					return -1;
				}
				 this->ne->q_max(attr);
			}
			else if (d == "NW")
			{
				if (this->nw == NULL)
				{
					return -1;
				}

				this->nw->q_max(attr);


			}
			else if (d == "SW")
			{
				if (this->sw == NULL)
				{
					return -1;
				}
				this->sw->q_max(attr);
			}
			else if (d == "SE")
			{
				if (this->se == NULL)
				{
					return -1;
				}
				this->se->q_max(attr);
			}
			else
			{
				return -1;
			}
		}
		else
		{
			 val= 0; //indicator that this is first round
			if (d == "NE")
			{
				if (this->ne == NULL)
				{
					return -1;
				}
				this->ne->q_total(attr);
			}
			else if (d == "NW")
			{
				if (this->nw == NULL)
				{
					return -1;
				}

				this->nw->q_total(attr);

			}
			else if (d == "SW")
			{
				if (this->sw == NULL)
				{
					return -1;
				}
				this->sw->q_total(attr);
			}
			else if (d == "SE")
			{
				if (this->se == NULL)
				{
					return -1;
				}
				this->se->q_total(attr);
			}
			else
			{
				return -1;
			}
		}
	}
	//keep searching for the co-ordinates
	else if (x >= this->root->x && y > this->root->y)
	{
		if (this->ne == NULL)
		{
			return -1;
		}
		return this->ne->q_search(x, y, d, attr, type);
	}

	else if (x < this->root->x && y >= this->root->y)
	{
		if (this->nw == NULL)
		{
			return -1;
		}
		return this->nw->q_search(x, y, d, attr, type);
	}

	else if (x <= this->root->x && y < this->root->y)
	{
		if (this->sw == NULL)
		{
			return -1;
		}
		return this->sw->q_search(x, y, d, attr, type);
	}

	else if (x > this->root->x && y <= this->root->y)
	{
		if (this->se == NULL)
		{
			return -1;
		}
		return this->se->q_search(x, y, d, attr, type);
	}

	return val;
}

void quadtree::q_min(string attr)
{
		if (attr == "p")
		{
			if (val == -1) //first round
			{
				val = this->root->p;
			}

			//change the value of the val accordingly
			if (this->root->p < val)
			{
				val = this->root->p;
			}

		}
		else if (attr == "s")
		{
			if (val == -1) //first round
			{
				val = this->root->sal;
			}
			//check if co-ordinates match the se child
			if (this->root->sal < val)
			{
				val = this->root->sal;
			}
		}
		else if (attr == "r")
		{
			if (val == -1) //first round
			{
				val = this->root->r;
			}
			//change the value of the val accordingly

			if (this->root->r < val)
			{
				val = this->root->r;
			}
		}
		//keep recursing through the rest of the nodes
		if (this->ne != NULL)
		{
			this->ne->q_min(attr);
		}
		if (this->nw != NULL)
		{
			this->nw->q_min(attr);
		}
		if (this->se != NULL)
		{
			this->se->q_min(attr);
		}
		if (this->sw != NULL)
		{
			this->sw->q_min(attr);
		}
}

void quadtree::q_max(string attr)
{
	if (attr == "p")
	{
		if (val == -1) //first round
		{
			val = this->root->p;
		}
		//change the value of the val accordingly
		if (this->root->p > val)
		{
			val = this->root->p;
		}

	}
	else if (attr == "s")
	{
		if (val == -1) //first round
		{
			val = this->root->sal;
		}
		//change the value of the val accordingly
		if (this->root->sal > val)
		{
			val = this->root->sal;
		}
	}
	else if (attr == "r")
	{
		if (val == -1) //first round
		{
			val = this->root->r;
		}
		//change the value of the val accordingly
		if (this->root->r > val)
		{
			val = this->root->r;
		}
	}
	//keep recursing through the rest of the nodes
	if (this->ne != NULL)
	{
		this->ne->q_max(attr);
	}
	if (this->nw != NULL)
	{
		this->nw->q_max(attr);
	}
	if (this->se != NULL)
	{
		this->se->q_max(attr);
	}
	if (this->sw != NULL)
	{
		this->sw->q_max(attr);
	}
}

void quadtree::q_total(string attr)
{
	if (attr == "p")
	{
		//keep incrementing val
		val = this->root->p + val;
	}
	else if (attr == "s")
	{
		val = this->root->sal + val;
	}
	else if (attr == "r")
	{
		val = this->root->r + val;
	}
	//keep recursing until all the nodes are checked

	if (this->ne != NULL)
	{
		this->ne->q_total(attr);
	}
	if (this->nw != NULL)
	{
		this->nw->q_total(attr);
	}
	if (this->se != NULL)
	{
		this->se->q_total(attr);
	}
	if (this->sw != NULL)
	{
		this->sw->q_total(attr);
	}
}

void quadtree::print()
{
	//inorder tree walk
	if (this->ne != NULL)
	{
		this->ne->print();
	}
	if (this->nw != NULL)
	{
		this->nw->print();
	}

	cout << this->root->name << " ";

	if (this->sw != NULL)
	{
		this->sw->print();
	}
	if (this->se != NULL)
	{
		this->se->print();
	}
}

void quadtree::clear()
{
	//clearing all the nodes
	if (this->ne != NULL)
	{
		this->ne->clear();
	}
	if (this->nw != NULL)
	{
		this->nw->clear();
	}
	if (this->sw != NULL)
	{
		this->sw->clear();
	}
	if (this->se != NULL)
	{
		this->se->clear();
	}
	this->root = NULL;
	this->ne = NULL;
	this->nw = NULL;
	this->se = NULL;
	this->sw = NULL;
	sizee = 0;
}


int main()
{
	//declaring variables
	string input;
	string word;
	string cityname;
	double x = 0;
	double y = 0;
	int p = 0;
	int r = 0;
	int sal = 0;
	string d;
	string attr;
	val = 0;
	sizee = 0;
	quadtree Qtree;
	node* current = new node;

	while (getline(cin, input))
	{
		//get a whole line
		stringstream eachline(input);

		//get the function 

		getline(eachline, word, ' ');


		if (word == "i")
		{

			//get the second line
			getline(eachline, word, ';');

			//convert the word to the integer
			cityname = word;

			getline(eachline, word, ';');

			//convert the word to the integer
			x = stod(word);

			getline(eachline, word, ';');

			//convert the word to the integer
			y = stod(word);

			getline(eachline, word, ';');

			//convert the word to the integer
			p = stoi(word);

			getline(eachline, word, ';');

			//convert the word to the integer
			r = stoi(word);

			getline(eachline, word, ' ');

			//convert the word to the integer
			sal = stoi(word);

			bool result;
			string res;
			res = Qtree.search(x, y);
			if (res == "not found")
			{
				 Qtree.insert(cityname, x, y, p, r, sal);
				 cout << "success" << endl;
			}
			else
			{
				cout << "failure" << endl;
			}

		}
		else if (word == "s")
		{

			getline(eachline, word, ';');
			x = stod(word);

			getline(eachline, word, ' ');
			y = stod(word);

			string result;
			result = Qtree.search(x, y);

			if (result == "not found")
			{
				cout << result << endl;
			}
			else
			{
				cout << "found "<<result << endl;

			}

		}

		else if (word == "q_max")
		{
			getline(eachline, word, ';');
			x = stod(word);

			getline(eachline, word, ';');
			y = stod(word);

			getline(eachline, word, ';');
			d = word;

			getline(eachline, word, ' ');
			attr = word;
			val = -1;

			int result1 = Qtree.q_search(x, y, d, attr, "max");

			if (result1 == -1)
			{
				cout << "failure" << endl;

			}
			else
			{
				cout << "max " << val<<endl;
			}
		}

		else if (word == "q_min")
		{
			getline(eachline, word, ';');
			x = stod(word);

			getline(eachline, word, ';');
			y = stod(word);

			getline(eachline, word, ';');
			d = word;

			getline(eachline, word, ' ');
			attr = word;
			val = -1;
			int result1 = Qtree.q_search(x, y, d, attr, "min");

			if (result1 == -1)
			{
				cout << "failure" << endl;

			}
			else
			{
				cout << "min " << val << endl;
			}
		}

		else if (word == "q_total")
		{

			getline(eachline, word, ';');
			x = stod(word);

			getline(eachline, word, ';');
			y = stod(word);

			getline(eachline, word, ';');
			d = word;

			getline(eachline, word, ' ');
			attr = word;

			val = 0;
			int result1 = Qtree.q_search(x, y, d, attr, "total");

			if (result1 == -1)
			{
				cout << "failure" << endl;

			}
			else
			{
				cout << "total " << val << endl;
			}

		}

		else if (word == "print")
		{
			if (Qtree.root == NULL)
			{
				cout << " " << endl;
			}
			else
			{
				Qtree.print();
				cout << endl;
			}
		}
		else if (word == "clear")
		{
			Qtree.clear();
			cout << "success" << endl;

		}

		else if (word == "size")
		{
			cout << "tree size " << sizee << endl;
		}

	}
	return 0;
}
