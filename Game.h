#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
using namespace std;

class Game {

//Attributes
private:
   vector<string> phrase;       //The phrase the solver is trying to guess
   int maxWords;                //Largest number of words allowed in the phrase
   int maxLetters;              //Largest number of letters allowed in each word

public:

   //Constructors
   
   //Initializes random game with no limits on words or letters
   Game(void) {
      maxWords = 0;
      maxLetters = 0;
      phrase = vector<string>();
      Game(0,0);
   }
   
   //Initializes game with given limit on words or letters
   Game(int maxWordsIn, int maxLettersIn) {
      maxWords = maxWordsIn;
      maxLetters = maxLettersIn;
      phrase = vector<string>();
      //Create random game with defined limits. If 0, no limit for that category.
   }
   
   //Creates a hangman game from the defined vector<string>
   Game(vector<string> phraseIn) {
      phrase = phraseIn;
      maxWords = phraseIn.size();
   }
   
   /*
   //Creates a hangman game from a given input string
   Game(string stringIn) {
   
   } 
   */
    
    
    //Get/set methods
      
   
   
   vector<string> getPhrase() {
      return phrase;  
   }
   
   int getMaxWords() {
      return maxWords;
   }
   
   int getMaxLetters() {
      return maxLetters;
   }
   
   void setPhrase(vector<string> phraseIn) {
      phrase = phraseIn;
   }
   
   void setMaxWords(int newMaxWords) {
      maxWords = newMaxWords;
   }
   
   void setMaxLetters(int newMaxLetters) {
      maxLetters = newMaxLetters;
   }
   
};

class GameAttempt {
   
   //Attributes 
   private:
   
   Game game;                    //Game that this attempted to solve
   int numGuesses;               //number of guesses required
   int runningTime;              //Running time taken to solve this game
//   bool isFinished;              //Whether the game has been solved
   
   public:
   
   /***********Constructors****************/
   GameAttempt(void) {
      Game();
      numGuesses = 0;
      runningTime = 0;
   }
   
   GameAttempt(Game gameIn) {
      game = gameIn;
      numGuesses = 0;
      runningTime = 0;
   }
   
   GameAttempt(Game gameIn, int numGuessesIn, int runningTimeIn) {
      game = gameIn;
      numGuesses = numGuessesIn;
      runningTime = runningTimeIn;
   }
   
   /*****Methods******/
   
   Game getGame() {
      return game;
   }
   
   int getNumGuesses() {
      return numGuesses;
   }
   
   int getRunningTime() {
      return runningTime;
   }
   
   void setGame(Game gameIn) {
      game = gameIn;
   }
   
   void setNumGuesses(int numGuessesIn) {
      numGuesses = numGuessesIn;
   }
   
   void setRunningTime(int runningTimeIn) {
      runningTime = runningTimeIn;
   }
   
};

#endif