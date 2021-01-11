//Author:Manasi Tirukachi

//Class interface/header file for playlist

#include<iostream>
using namespace std;
#ifndef SONG_H
#define SONG_H
#include <vector>

//create the class for this

class Playlist {
public:

	vector <string> list;

	Playlist ();
	~Playlist();

	//inserting a playlist into the list
	int insert(const string song, const string artist);

	//playing song from the list

	int play(const int n);

	//erasing  the song from the list

	int erase(const int n);


};

#endif
