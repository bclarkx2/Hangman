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
   int numPhraseGuesses;         //number of guesses required
   int numLetterGuesses;         //number of letters guessed
   int runningTime;              //Running time taken to solve this game
   bool finished;              //Whether the game has been solved

   
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
   
   int getRunningTime();
   
   bool isFinished();
   
   void setGame(Game gameIn);
   
   void setGuesses(vector<CharInList> newList);
   
   void setNumPhraseGuesses(int numPhraseGuessesIn);
   
   void setNumLetterGuesses(int numLetterGuessesIn);
   
   void setRunningTime(int runningTimeIn);
   
   void setIsFinished(bool finishedIn);

   
   /********Class functions*******/
   
      //none
   
   /******Member functions********/
   
   bool guessLetter(char guess);
   
   bool guessPhrase(vector<string> guess);
   
   bool haveGuessed(char c);

};

 #endif
