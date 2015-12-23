#include "GameAttempt.h"

/***********Constructors****************/

/**
 * Void argument contructor.
 */
// GameAttempt::GameAttempt(void) {
   // game = Game();
   // guesses = CharList();
   // guesses.initialize();            //Set all characters to not having been guessed
   // numPhraseGuesses = 0;
   // numLetterGuesses = 0;
   // runningTime = 0;
// }

/**
 * Established GameAttempt for a pre-existing Game.
 * gameIn the Game object to be solved for 
 */
GameAttempt::GameAttempt(Game gameIn) {
   game = gameIn;
   guesses = CharList();
   guesses.initialize();            //Set all characters to not having been guessed
   numPhraseGuesses = 0;
   numLetterGuesses = 0;
   finished = false;
   runningTime = 0;
}

/**
 * "Full" constructor - designed to create a GameAttempt object for a solved Game
 * gameIn the Game that has been solved
 * numPhraseGuessesIn the number of phrase guesses that were made
 * numLetterGuessesIn the number of letter guesses that were made
 * runningTime the running time in seconds
 */
// GameAttempt::GameAttempt(Game gameIn, int numPhraseGuessesIn, int numLetterGuessesIn, int runningTimeIn) {
   // game = gameIn;
   // numPhraseGuesses = numPhraseGuessesIn;
   // numLetterGuesses = numLetterGuessesIn;
   // runningTime = runningTimeIn;
// }



/*******Get/set Methods*********/

Game GameAttempt::getGame() {
   return game;
}

CharList GameAttempt::getGuesses() {
   return guesses;
}

int GameAttempt::getNumPhraseGuesses() {
   return numPhraseGuesses;
}

int GameAttempt::getNumLetterGuesses() {
   return numLetterGuesses;
}

int GameAttempt::getRunningTime() {
   return runningTime;
}

bool GameAttempt::isFinished() {
   return finished;
}  


void GameAttempt::setGame(Game gameIn) {

   game = gameIn;
}

void GameAttempt::setGuesses(vector<CharInList> newList) {
   guesses.setList(newList);
}

void GameAttempt::setNumPhraseGuesses(int numPhraseGuessesIn) {
   numPhraseGuesses = numPhraseGuessesIn;
}

void GameAttempt::setNumLetterGuesses(int numLetterGuessesIn) {
   numLetterGuesses = numLetterGuessesIn;
}

void GameAttempt::setRunningTime(int runningTimeIn) {
   runningTime = runningTimeIn;
}

void GameAttempt::setIsFinished(bool finishedIn) {
   finished = finishedIn;
}


/********Class functions*******/

   //none

/******Member functions********/

/**
 * This method determines whether a char is a member of the Game associated with this
 * GameAttempt. This is a core Hangman game functionality.
 * guess a char representing the player's guess
 * returns a bool indicating whether or not the guess was correct
 */
bool GameAttempt::guessLetter(char guess) {
   
   bool guessSuccess = false;
   
   if(!haveGuessed(guess)) {                                   //If this letter has not already been guessed
      setNumLetterGuesses(getNumLetterGuesses()+1);            //Increment number of letter guesses
      guesses.add(guess);                                      //Add letter to list of guessed chars
      if(getGame().getCharsInPhrase().contains(guess)) {       //If this char is a correct guess
         guessSuccess = true;                                  // Mark this guess as correct
      }
   }
   
   return guessSuccess;                                        //Return success of the guess
}

/**
 * Determines whether a guessed phrase is correct. This is a fundamental gameplay
 * component of Hangman.
 * guess a string vector containing the guess
 * returns a bool indicating whether the guess was correct.
 */
bool GameAttempt::guessPhrase(vector<string> guess) {
   
   bool guessSuccess(true);
   vector<string> phrase = getGame().getPhrase();
   setNumPhraseGuesses(getNumPhraseGuesses() + 1);
   
   if(guess.size() == phrase.size()) {
      for(int i = 0; i < guess.size() && guessSuccess; i++) {
         if(guess[i].compare(phrase[i]) != 0) {
            guessSuccess = false;
         }
      }
   }
   else {
      guessSuccess = false;
   }
   
   setIsFinished(isFinished() || guessSuccess);
   
   return guessSuccess;
}

/**
 * Determines whether a given char has already been guessed.
 * c the char to be checked for
 * returns a bool indicating true if the char has already been guessed.
 */
bool GameAttempt::haveGuessed(char c) {
   
   return getGuesses().contains(c);
   
}
