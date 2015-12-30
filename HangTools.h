 //=================================
// include guard

#ifndef HANGTOOLS_H
#define HANGTOOLS_H

//=================================
// forward declared dependencies

      //none

//=================================
// included dependencies

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

#include "Constants.h"
#include "Game.h"
#include "GameAttempt.h"

//=================================
// Hangtools

using namespace std;


const int DEFAULT_NUM_WORDS = 3;

class HangTools {
   
   private:
   
   static vector<string> allWords;
   
   public:
   
   /********Constructors**********/
   
   HangTools(void);
   
   /*******Get/set Methods*********/
   
   // static vector<string> getAllWords();
 
   // static void setAllWords(vector<string> allWordsIn);
   
   /********Class functions*******/
   
   static Game randomGame(int numWords);
   
   static bool equalsIgnoreCase(string s1, string s2);
   
   static int getRandomNumber(int min, int max);

   /******Member functions********/
   
      //none   

};

#endif