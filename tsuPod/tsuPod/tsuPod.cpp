
/*************************
 Jonathan Gonzalez
 CS 2308
 ************************/

#include <iostream>
#include <ctime>
#include "tsuPod.h"


const int NUM_SONGS = 8;
const int MEMORY_SIZE = 25;

double memory = 0;
int songCount = 0;


struct TsuPod // Creates TsuPd structure
{
   string title;
   string artist;
   int size;
};

TsuPod Song[NUM_SONGS]; // Creates to store each Struct Song

void initTsuPod() // Clears all slots in array and sets them to "" or 0.
{
   for (int i = 0; i < NUM_SONGS; i++)
   {
      Song[i].title = "";
      Song[i].artist = "";
      Song[i].size = 0;
   }
   memory = 0;
   songCount = 0;
}
/****************************************************
 Function addSong passes song title, artist and size of
 song to add to struct array or find errors in song information.
 ***************************************************/

int addSong (string newTitle, string newArtist, int size)
{
   if(songCount >= NUM_SONGS) // Checks for song count
   {
      cout << "Not enough slots for song" << endl << endl;
      return -2;
   }
   
   
   if (size > 25)// Clears memeory slot if song size greater than 25MB
   {
      cout << "Size of file can not exceed 25MB";
      cout << endl;
      return -1;
   }
   
   if(memory + size > MEMORY_SIZE)    // Checks memory capacity
   {
      cout << "Memory full! Can't add another song!" << endl;  //error message for memory execiding 25MB
      cout << "Memory available: " << MEMORY_SIZE - memory << "MB." << endl; // Displays memory available
      cout << "Memory song requires: " << size << endl << endl;
      return -1;
   }
   
   string empty = "";
   
   if ( newTitle == empty || newArtist == empty  ) // Checks for empty string on song title or artist
   {
      cout << "Title or Artist is blank in Slot " << songCount + 1 << endl;   //display error message if name or artist is blank
      return -2;
   }
   
   if ( memory + size <= MEMORY_SIZE ) // Sets song information in Struct Array
   {
      Song[songCount].title = newTitle;
      Song[songCount].artist = newArtist;
      Song[songCount].size = size;
      
      memory += size;
      songCount++;
      return 0;
   }
   
   return 0;
}

/****************************************************
 Function prints each song located in struct arrayl
 ***************************************************/

void showSongList ()
{
   for(int i =0, x = 1; i < 8; i++, x++)// loops through slots.
   {
      
      if( Song[i].title == "" )
         cout << "Slot #" << x << " Empty" << endl; // output if slot is empty
      
      else
      {
         cout << "Slot #" << x << " " << Song[i].title <<", "; //outputs song information
         cout << Song[i].artist << ", " << Song[i].size <<" MB" << endl;
      }
   }
}

/****************************************************
 Function removes songs instructed by the title passed 
 as a parameter.
 ***************************************************/

int removeSong (string title)
{
   for (int i = 0; i < NUM_SONGS; i++) // loops through array
   {
      if (Song[i].title == title)
      {
         cout << "Removing " << title << " From: " << Song[i].artist << endl;
         memory -= Song[i].size;
         
         cout << "Memory available after removing song: " << (MEMORY_SIZE - memory) << "MB " << endl;
         
         Song[i].title = ""; // removes song
         Song[i].artist = "";
         Song[i].size = 0;
         
         songCount -= 1; 
         return 0;
         
      }
   }
   cout << " Song title not found. Did not remove " << endl; // prints if song not found.
   return -1;
}

/****************************************************
 Function shuffles each song
 ***************************************************/

void shuffle ()
{
   TsuPod Temp;
   int currentTime =  (unsigned)time(0);
   
   srand(currentTime);
   
   for (int i = 0; i < (NUM_SONGS * 2); i++)
   {
      int index1 = (rand() % NUM_SONGS);
      int index2 = (rand() % NUM_SONGS);
      
      Temp = Song[index1];
      Song[index1] = Song[index2];
      Song[index2] = Temp;
   }
}

/****************************************************
 Function clears memory and resets struct array
 ***************************************************/

void clearMemory()
{
   initTsuPod();
}
