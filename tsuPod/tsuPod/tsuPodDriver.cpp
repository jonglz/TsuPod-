/****************************************************
 File Name: TsuPod
 
 Author: Jonathan Gonzalez
 Date: Feb 20, 2015
 Problem Number: 3
 CS 2308 Spring 2015
 Instructor: Priebe
 
 Creates TsuPod
 *****************************************************/

#include <iostream>

#include "tsuPod.h"

using namespace std;

int main()
{
   initTsuPod(); // initializes TsuPod
   
   showSongList(); // Displays Empty List
   cout << endl;
   
   // Testing that all songs have been added successfully
   cout << "***** Adding songs to TsuPod ...*****" << endl;
   cout << endl; 
   int retCode = addSong("Runaway1", "Bon Jovi1", 1);
   retCode = addSong("Runaway2", "Bon Jovi2", 2);
   retCode = addSong("Runaway3", "Bon Jovi3", 4);
   retCode = addSong("Runaway4", "Bon Jovi4", 1);
   retCode = addSong("Runaway5", "Bon Jovi5", 5);
   retCode = addSong("Runaway6", "Bon Jovi6", 6);
   retCode = addSong("Runaway7", "Bon Jovi7", 1);
   retCode = addSong("Runaway8", "Bon Jovi8", 2);

   showSongList();
   cout << endl;
   cout << "Return code 0 is returned to show that all songs were added successfully" << endl;
   cout << "Return Code: " << retCode << endl;
   
   // Testing Too many songs
   cout << "\n\n" ;
   cout << "***** Testing for too many songs...*****" << endl;
   cout << "\nAdding another song" << endl;
   
   retCode = addSong("Blessings", "Big Sean", 5);
   cout << "Return code -2 is returned to notify that error has occured" << endl;
   cout << "Return Code: " << retCode << endl;
   
   
   // Testing remove song from playlist
   cout << "\n\n" ;

   cout << "***** Removing Song! *****" << endl << endl;
   showSongList();
   cout << endl;
   cout << "\nIf return code 0 is returned, song was removed successfully" << endl;
   cout << "If return code -1 is returned, song was not removed" << endl;
   
   cout << endl;
   retCode = removeSong("Blessings");
   cout << "Return Code: " << retCode << endl;
  
   cout << endl;
   retCode = removeSong("Runaway8");
   cout << "Return Code: " << retCode << endl << endl;
   

   showSongList();
   cout << endl;
   
   // Testing that no song is bigger than 25MB
   cout << "\n\n" ;
   cout << "***** Testing for songs exceeding 25 MB*****" << endl << endl;\
   cout << "Title: Blessings , Artist: Big Sean, Size: 34MB" << endl << endl;
   
   retCode = addSong("Blessings", "Big Sean", 34);
   
   cout << " Returns -1 if not enough memory to add the song " << endl;
   cout << "Return Code: " << retCode << endl;
   
   
   // Testing that memory capacity has been reached
   cout << "\n\n" ;
  
   cout << " ****** Testing Memory Capacity *******" << endl << endl;
   cout << "Title: Blessings , Artist: Big Sean, Size: 10MB" << endl << endl;

   cout << " Return code -1 is returned, when there's not sufficient memory " << endl;
   retCode = addSong("Blessings", "Big Sean", 10);
   
   cout << "Return Code: " << retCode;

   // Testing adding songs without title or artist name
   
   cout << "\n\n" ;
   cout << "**** Testing adding songs without title and/or artist name ****" << endl << endl;
   cout << "Title: , Artist: Big Sean, Size: 1MB" << endl << endl;
   retCode = addSong("", "", 1);
   
   cout << "Return code -2 is returned to notify that error has occured" << endl;
   cout << "Return Code: " << retCode << endl;

   
   // Clearing Memory
   cout << "\n\n" ;

   cout << " ****** CLEARING MEMORY *****";
   clearMemory();
   cout << endl << endl;
   
   cout << "Cleared Memory...." << endl;
   showSongList();
   cout << endl;
   
   
   // Testing shuffling function
   
   cout << "\n\n";
   cout << "****** Shuffling Playlist ******" << endl;
   
   retCode = addSong("Runaway1", "Bon Jovi1", 1);
   retCode = addSong("Runaway2", "Bon Jovi2", 2);
   retCode = addSong("Runaway3", "Bon Jovi3", 4);
   retCode = addSong("Runaway4", "Bon Jovi4", 1);
   retCode = addSong("Runaway5", "Bon Jovi5", 5);
   retCode = addSong("Runaway6", "Bon Jovi6", 6);
   retCode = addSong("Runaway7", "Bon Jovi7", 1);
   retCode = addSong("Runaway8", "Bon Jovi8", 2);
   cout << endl;

   showSongList();
   cout << endl;

   shuffle();
   cout << endl;


   cout << " ----Shuffled Playlist----" << endl;
   showSongList();
   cout << endl;
   
}


















