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
   numWrongLetterGuesses = 0;
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

int GameAttempt::getNumWrongLetterGuesses() {
   return numWrongLetterGuesses;
}

int GameAttempt::getRunningTime() {
   return runningTime;
}

vector<char> GameAttempt::getAlreadyGuessed() {
   return alreadyGuessed;
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

void GameAttempt::setNumWrongLetterGuesses(int numWrongLetterGuessesIn) {
   numWrongLetterGuesses = numWrongLetterGuessesIn;
}

void GameAttempt::setRunningTime(int runningTimeIn) {
   runningTime = runningTimeIn;
}

void GameAttempt::setIsFinished(bool finishedIn) {
   finished = finishedIn;
}

void GameAttempt::setAlreadyGuessed(vector<char> alreadyGuessedIn) {
   alreadyGuessed = alreadyGuessedIn;
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
   
   if(!haveGuessed(guess)) {                                      //If this letter has not already been guessed
      setNumLetterGuesses(getNumLetterGuesses()+1);               //Increment number of letter guesses
      guesses.add(guess);                                         //Add letter to list of guessed chars
      if(getGame().getCharsInPhrase().contains(toupper(guess)) || //If this char is a correct guess
         getGame().getCharsInPhrase().contains(tolower(guess))){  
         guessSuccess = true;                                     // Mark this guess as correct
      }
      else {                                                      //New guess, but an incorrect one
         vector<char> newAlreadyGuessed = getAlreadyGuessed();
         newAlreadyGuessed.push_back(guess);
         sort(newAlreadyGuessed.begin(), newAlreadyGuessed.end());
         setAlreadyGuessed(newAlreadyGuessed);
         setNumWrongLetterGuesses(getNumWrongLetterGuesses() + 1);
      }
   }
   else {                                                         //Letter has been guessed. 
      if(getGame().getCharsInPhrase().contains(toupper(guess)) || //If this char is a correct guess
         getGame().getCharsInPhrase().contains(tolower(guess))){  
         guessSuccess = true;                                     // Mark this guess as correct
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
         if(!HangTools::equalsIgnoreCase(phrase[i], guess[i])) {
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
   
   return getGuesses().contains(toupper(c)) || getGuesses().contains(tolower(c));
   
}

/**
 * At any moment, this method will return a string (formatted to print to console)
 * giving the current status of the attempt. The following information is included:
 *    -The phrase to be guessed, displayed as blanks. The letters that you have
 *     already guessed will show up as the letters.
 *    -Number of letter guesses made
 *    -Number of phrase guesses made
 *    -Failed guesses already made
 */
string GameAttempt::status() {
   
   //Various parts, formatted as strings
   string message = string();
   string phraseString = string();
   string letterGuessesString = string();
   string phraseGuessesString = string();
   string alreadyGuessedString = string();
      
   //phaseString
   vector<string> phrase = getGame().getPhrase();
      
   for(int i = 0; i < phrase.size(); i++) {                          //For all words in the phrase
         
      string s = phrase[i];                                          //Save the current word
         
      for(int j = 0; j < s.size(); j++) {                            //For all characters in the current word
         
         if(haveGuessed(s[j])) {                                     //If the letter has been guessed :
            phraseString.push_back(s[j]);                               //    Append the letter to the phraseString
         }
         else {                                                      //If it hasn't been guessed, leave it as a blank
            phraseString.push_back('_');
         }
      }
      phraseString.push_back(' ');                                   //Add a space between words
   }
   phraseString.push_back('\t');
   
   //letterGuessesString
   
   ostringstream s1;
   s1 << "Number of wrong letter guesses: " << dec << getNumWrongLetterGuesses() << '\t';
   letterGuessesString = s1.str();
   
   //phraseGuessesString
   
   ostringstream s2;
   s2 << "Number of wrong phrase guesses: " << dec << getNumPhraseGuesses() << '\t';
   phraseGuessesString = s2.str();
   
   
   //alreadyGuessedString
   
   vector<char> guessList = getAlreadyGuessed();
   ostringstream s3;
   s3 << "Incorrect Letters Guessed: ";
   
   for(int i = 0; i < guessList.size(); i++) {                       //For each incorrect character guessed
      s3 << guessList[i] << ',' << ' ';                              //Add comma and space delimited char
   }
   s3 << '\t';
   
   alreadyGuessedString = s3.str();
   
   
   //Setting up string
   
   message = phraseString + letterGuessesString + phraseGuessesString + alreadyGuessedString;
   
   
   return message;
}
