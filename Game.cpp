#include "Game.h"


      /********Constructors******/

 /**
  * Initializes random game with no limits on words or letters
  */
Game::Game(void) {
   // maxWords = 0;
   // maxLetters = 0;
   phrase = vector<string>();
   charsInPhrase = CharList();
}
   
   //Initializes game with given limit on words or letters
   // Game::Game(int maxWordsIn, int maxLettersIn) {
      // maxWords = maxWordsIn;
      // maxLetters = maxLettersIn;
      // phrase = vector<string>();
      // charsInPhrase = CharList();
      //Create random game with defined limits. If 0, no limit for that category.
   // }
   
 /**
  * Creates a hangman game from the defined vector<string>
  */
Game::Game(vector<string> phraseIn) {
   phrase = phraseIn;
   charsInPhrase = CharList();
   charsInPhrase.initialize(phraseIn);
   //maxWords = phraseIn.size();
}
   
   /*
   //Creates a hangman game from a given input string
   Game::Game(string stringIn) {
   
   } 
   */

/*******Get/set Methods*********/
   
vector<string> Game::getPhrase() {
   return phrase;  
}
   
CharList Game::getCharsInPhrase() {
   return charsInPhrase;
}
   
   // int Game::getMaxWords() {
      // return maxWords;
   // }
//    
   // int Game::getMaxLetters() {
      // return maxLetters;
   // }
   
void Game::setPhrase(vector<string> phraseIn) {
   phrase = phraseIn;
}
   
   // void Game::setMaxWords(int newMaxWords) {
      // maxWords = newMaxWords;
   // }
//    
   // void Game::setMaxLetters(int newMaxLetters) {
      // maxLetters = newMaxLetters;
   // }

/********Class functions*******/
   
//none
   
/******Member functions********/
   
bool Game::contains(char c) {
   
   return getCharsInPhrase().contains(c);
   
}