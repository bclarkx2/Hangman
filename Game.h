//=================================
// include guard

#ifndef GAME_H
#define GAME_H

//=================================
// forward declared dependencies


//=================================
// included dependencies

#include <string>
#include <vector>

#include "Constants.h"
#include "CharList.h"

//=================================
// the actual class

using namespace std;


class Game {
   
   private:
   vector<string> phrase;       //The phrase the solver is trying to guess
   // int maxWords;                //Largest number of words allowed in the phrase
   // int maxLetters;              //Largest number of letters allowed in each word
   CharList charsInPhrase;      //CharList containing the truth values for all the characters in this game's phrase
   
   
   public:
   
   /********Constructors**********/
   
   Game(void);
         
   
   // Game(int maxWordsIn, int maxLettersIn);
   
   Game(vector<string> phraseIn);
   
   // Game(string stringIn);

   
   /*******Get/set Methods*********/
   
   vector<string> getPhrase();
   
   CharList getCharsInPhrase();
   
   // int getMaxWords();
   //    
   // int getMaxLetters();
   
   void setPhrase(vector<string> phraseIn);
   
   // void setMaxWords(int newMaxWords);
      //    
   // void setMaxLetters(int newMaxLetters);

   
   /********Class functions*******/
   
   //none
   
   /******Member functions********/
   
   bool contains(char c);

};
 
#endif