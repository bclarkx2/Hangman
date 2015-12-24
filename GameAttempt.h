/****************************GameAttempt.cpp*****************************/

//=================================
// include guard

#ifndef GAMEATTEMPT_H 
#define GAMEATTEMPT_H

//=================================
// forward declared dependencies

      //none

//=================================
// included dependencies

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "Constants.h"
#include "CharList.h"
#include "Game.h"
#include "HangTools.h"

//=================================
// GameAttempt

using namespace std;


class GameAttempt {
   
   private:
   
   Game game;                    //Game that this attempted to solve
   CharList guesses;             //CharList detailing for every character whether or not it has been guessed in this attempt
   vector<char> alreadyGuessed;  //Simple, sorted vector of the chars already guessed
   int numPhraseGuesses;         //number of guesses required
   int numLetterGuesses;         //number of letters guessed
   int numWrongLetterGuesses;    //number of incorrect letters guessed
   int runningTime;              //Running time taken to solve this game
   bool finished;                //Whether the game has been solved

   
   public:
   
   /***********Constructors****************/
   
   // GameAttempt(void);
   
   GameAttempt(Game gameIn);
   

   // GameAttempt(Game gameIn, int numPhraseGuessesIn, int numLetterGuessesIn, int runningTimeIn);

   
   
   /*******Get/set Methods*********/
   
   Game getGame();
   
   CharList getGuesses();
   
   int getNumPhraseGuesses();
   
   int getNumLetterGuesses();
   
   int getNumWrongLetterGuesses();
   
   int getRunningTime();
   
   vector<char> getAlreadyGuessed();
   
   bool isFinished();
   
   void setGame(Game gameIn);
   
   void setGuesses(vector<CharInList> newList);
   
   void setNumPhraseGuesses(int numPhraseGuessesIn);
   
   void setNumLetterGuesses(int numLetterGuessesIn);
   
   void setNumWrongLetterGuesses(int numWrongLetterGuessesIn);
   
   void setRunningTime(int runningTimeIn);
   
   void setIsFinished(bool finishedIn);
   
   void setAlreadyGuessed(vector<char> alreadyGuessedIn);

   
   /********Class functions*******/
   
      //none
   
   /******Member functions********/
   
   bool guessLetter(char guess);
   
   bool guessPhrase(vector<string> guess);
   
   bool haveGuessed(char c);
   
   string status();

};

 #endif
