//Author: Manasi Tirukachi

#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string> 
#include <sstream>

using namespace std;

#include "song.h"

//MAIN FUNCTION

int main()
{

  //declaring variables
  string input;
  string word;
  string song;
  string artist;
  int n = 0;

  Playlist plist; 

  while (getline(cin, input))
  {
  	//get single line
  	stringstream eachline(input);

  	getline(eachline, word, ' ');

  	//INSERT FUNCTION
  	if (word == "i")
  	{
  		getline(eachline, word, ';');
  		song = word;

  		getline(eachline, word, ';');
  		artist = word;

  		int result = 0;

  		result = plist.insert(song, artist);

  		if (result == 0)
  		{
  			//failure case
  			cout<<"can not insert "<<song<<";"<<artist<<endl;
  		}
  		else
  		{
  			//success case
  			cout<<"success"<<endl;
  		}
  	}

  	//PLAY FUNCTION
  	else if (word == "p")
  	{
  		getline(eachline, word, ' ');
  		n = stoi(word);

  		int result = 0;

  		result = plist.play(n-1);

  		if (result == 0)
  		{
  			//failure case
  			cout<<"could not play "<<n<<endl;
  		}
  		else
  		{
  			//success case
  			int position = 2*(n-1);

  			cout<<"played "<<n<<" "<<plist.list[position]<<";"<<plist.list[position+1]<<endl;
  		}

  	}
//ERASE FUNCTION
  	else if (word == "e")
  	{
  		getline(eachline, word, ' ');
  		n = stoi(word);

  		int result = 0;

  		result = plist.erase(n-1);

  		if (result == 0)
  		{
  			//failure case
  			cout<<"could not erase "<<n<<endl;
  		}
  		else
  		{
  			//success case
  			cout<<"success"<<endl;
  		}

  	}

  }

  return 0;

}


