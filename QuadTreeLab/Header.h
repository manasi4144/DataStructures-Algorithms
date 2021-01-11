#pragma once

// Author: Manasi Tirukachi

#include <iostream>
using namespace std;

#ifndef HEADER_H
#define HEADER_H
struct node
{
	//bool init;
	string name = "none";
	double x = 0;
	double y = 0;
	int p = 0;
	int r = 0;
	int sal = 0;
};

class quadtree
{
public:
	//creating the root of the tree? or do this in the initializer?

	node* root;
	quadtree* ne;
	quadtree* nw;
	quadtree* sw;
	quadtree* se;

	quadtree();
	~quadtree();

	void insert(string cityname, double x, double y, int p, int r, int sal);
	string search(double x, double y);

	int q_search(double x, double y, string d, string attr, string type);
	void q_max(string attr);
	void q_min(string attr);
	void q_total(string attr);

	void print();
	void clear();

};
#endif
