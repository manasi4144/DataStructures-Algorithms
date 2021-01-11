#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string> 
#include <sstream>

using namespace std;

#include "song.h"
//constuctor declaration

Playlist::Playlist()
{
	//not much happening here :)
}

Playlist::~Playlist()
{
	//clearing the entire list
	list.clear();
}

int Playlist::insert(const string song, const string artist)
{
	//check if the song already exists
	bool found = false;

	for (auto & elem: list)
	{
		if (elem == song)
		{
			found = true;
		}

		if (found)
		{
			if(elem == artist)
			{
			    break;
			}
		}
	}

	if (found)
	{
		return 0;
	}

	//if doesn't exist
	else
	{
		//insert artist below the song
		list.push_back(song);
		list.push_back(artist);
		return 1;
	}

	return 1;
	//returns 1 for success and 0 for failure
}

int Playlist::play(const int n)
{
	int pos = 2*n;

	int size = list.size();

	//if position given is greater than the size of the vector
	if (pos > size)
	{
		return 0;
	}

	return 1;

	//return 1 for success and 0 for failure
}

int Playlist::erase(const int n)
{

	int pos = (2*n);
	int pos1 = (2*n+2);

	int size = list.size();

	//check if the position give is greater than the size of the vector
	if (pos > size)
	{
		return 0;
	}

	//delete song and artist
	this->list.erase(list.begin()+pos, list.begin()+pos1);
	return 1;

	//return 1 for success and 0 for failure
}
