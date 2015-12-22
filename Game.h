#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int ASCIIstart(33);
const int ASCIIend(126);


/**
 * An object to keep track of each individual ASCII character. Stores
 * the actual character, as well as a bool indicating whether or not
 * it is present in the CharList
 */
class charInList {
   
   private:
   char myChar;
   bool isPresent;
   
   public:
   charInList(char charIn, bool isIn) {
      myChar = charIn;
      isPresent = isIn;
   }
   
   /*******Get/set Methods*********/
   
   char getMyChar() {
      return myChar;
   }
   
   bool getIsPresent() {
      return isPresent;  
   }
   
   void setMyChar(char charIn) {
      myChar = charIn;
   }
   
   void setIsPresent(bool isIn) {
      isPresent = isIn;
   }

   
   /******Member functions********/
   
   /**
    * Two charInLists are equal if they are the same letter and both are present or not present
    * c the charInList to be compared with
    * return bool indicating whether they are equal
    */
   bool equals(charInList c) {
      if(getIsPresent() == c.getIsPresent() && getMyChar() == c.getMyChar()) {
         return true;
      }
      else {
         return false;
      }
   }
};


/**
 * CharList is a list of charInList objects. The number of charInList objects
 * corresponds to the number of characters in the charset being used. Taken together
 * the CharList details whether or not every character in the charset is in the list.
 * It provides for easy access to this information because the location of the 
 * charInList object is accessible by merely subtracting ASCIIstart from the int value
 * of the character.
 */
class CharList {
   private:
   vector<charInList> list;
   
   public:
   
   /*******Constructors*********/
   
   CharList(void) {
   
   }
   
   
   /******Get/Set Methods*********/
   
   vector<charInList> getList() {
      return list;
   }
   
   void setList(vector<charInList> newList) {
      list = newList;
   }
   
   /*********Member functions********/
   
   /**
    * Compares two lists of characters. Goes to each character and compares the char/bool tuple.
    * Returns true if they match for every character.
    */
   bool equals(CharList c) {
      
      for(int i = 0; i < c.getList().size(); i++) {
      
         if(!getList()[i].equals(c.getList()[i])) {
            return false;
         }
      }
      return true;
   }
   
   /**
    * A CharList is defined only if its list field stores a vector of charInList objects
    */
   bool isDefined() {
      return !getList().empty();
   }
   
   /**
    * Makes the CharList blank. Every character is set to not present.
    */
   void initialize() {
   
      vector<charInList> newList = vector<charInList>();             //Brand new charInList vector
     
      for(int i = ASCIIstart; i <= ASCIIend; i++) {                   //Add a charInList for every ASCII character
         charInList cin = charInList(static_cast<char>(i), false);
         newList.push_back(cin);
      }
   
      setList(newList);
   }
   
   /**
    * Sets the CharList to reflect a given phrase. Wipes out previous information
    */
   void initialize(vector<string> phrase) {
      
      //Set blank
      initialize();
         
      update(phrase);
   
   }
   
   /**
    * Adds characters from the phrase to the CharList. Does not wipe out previous information
    */
   void update(vector<string> phrase) {
      
      vector<charInList> cList = getList();
      
      //Update the vector for the new phrase
      for(int i = 0; i < phrase.size(); i++){                                       //Cycle through all words in phrase
         string s = phrase[i];                                                      //Current string in phrase
         for(int j = 0; j < s.size(); j++) {                                        //Access each character in the string
            char currentChar = s[j];                                                //Char value under consideration
            int currentIntValueOfChar = static_cast<int>(currentChar);              //Int value of that char
            int currentIndexOnCharList = currentIntValueOfChar - ASCIIstart;        //Index in the charList
            cList[currentIndexOnCharList].setIsPresent(true);                   //Since we are looking at a manifestation of that char, it is obviously present in the phrase
         }
      }
      
      setList(cList);
      
   }

   /** 
    * Identifies if a given character is marked as present in the CharList
    * c the character to be checked
    * returns a bool indicating whether the character is in fact present
    */
   bool contains(char c) {
      
      int n = static_cast<int>(c) - ASCIIstart;
      return getList()[static_cast<int>(n)].getIsPresent();
      
   }
   
   /**
    * Takes a character and marks it as present in the CharList
    * c the character to the be marked present
    */
   void add(char c) {
      
      int n = static_cast<int>(c);
      
      if(n <= ASCIIend && n >= ASCIIstart) {
      
         vector<charInList> cList = getList();
      
         int m = n - ASCIIstart;
         cList[static_cast<int>(m)].setIsPresent(true);
      
         setList(cList);
      }
   }

};

class Game {

   //Attributes
private:
   vector<string> phrase;       //The phrase the solver is trying to guess
   // int maxWords;                //Largest number of words allowed in the phrase
   // int maxLetters;              //Largest number of letters allowed in each word
   CharList charsInPhrase;      //CharList containing the truth values for all the characters in this game's phrase

public:

   //Constructors
   
   //Initializes random game with no limits on words or letters
   Game(void) {
      // maxWords = 0;
      // maxLetters = 0;
      phrase = vector<string>();
      charsInPhrase = CharList();
   }
   
   //Initializes game with given limit on words or letters
   // Game(int maxWordsIn, int maxLettersIn) {
      // maxWords = maxWordsIn;
      // maxLetters = maxLettersIn;
      // phrase = vector<string>();
      // charsInPhrase = CharList();
      //Create random game with defined limits. If 0, no limit for that category.
   // }
   
   //Creates a hangman game from the defined vector<string>
   Game(vector<string> phraseIn) {
      phrase = phraseIn;
      charsInPhrase = CharList();
      charsInPhrase.initialize(phraseIn);
      //maxWords = phraseIn.size();
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
   
   CharList getCharsInPhrase() {
      return charsInPhrase;
   }
   
   // int getMaxWords() {
      // return maxWords;
   // }
//    
   // int getMaxLetters() {
      // return maxLetters;
   // }
   
   void setPhrase(vector<string> phraseIn) {
      phrase = phraseIn;
   }
   
   // void setMaxWords(int newMaxWords) {
      // maxWords = newMaxWords;
   // }
//    
   // void setMaxLetters(int newMaxLetters) {
      // maxLetters = newMaxLetters;
   // }
   
   
   
   /********Member functions*******/
   
   bool contains(char c) {
      
      return getCharsInPhrase().contains(c);
      
   }
};

class GameAttempt {
   
   //Attributes 
   private:
   
   Game game;                    //Game that this attempted to solve
   CharList guesses;             //CharList detailing for every character whether or not it has been guessed in this attempt
   int numPhraseGuesses;         //number of guesses required
   int numLetterGuesses;         //number of letters guessed
   int runningTime;              //Running time taken to solve this game
   bool finished;              //Whether the game has been solved
   
   public:
   
   /***********Constructors****************/
   
   /**
    * Void argument contructor.
    */
   // GameAttempt(void) {
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
   GameAttempt(Game gameIn) {
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
   // GameAttempt(Game gameIn, int numPhraseGuessesIn, int numLetterGuessesIn, int runningTimeIn) {
      // game = gameIn;
      // numPhraseGuesses = numPhraseGuessesIn;
      // numLetterGuesses = numLetterGuessesIn;
      // runningTime = runningTimeIn;
   // }
   
   
   /***********Get/Set functions***********/
   
   Game getGame() {
      return game;
   }
   
   CharList getGuesses() {
      return guesses;
   }
   
   int getNumPhraseGuesses() {
      return numPhraseGuesses;
   }
   
   int getNumLetterGuesses() {
      return numLetterGuesses;
   }
   
   int getRunningTime() {
      return runningTime;
   }
   
   bool isFinished() {
      return finished;
   }  
   
   
   void setGame(Game gameIn) {
   
      game = gameIn;
   }
   
   void setGuesses(vector<charInList> newList) {
      guesses.setList(newList);
   }
   
   void setNumPhraseGuesses(int numPhraseGuessesIn) {
      numPhraseGuesses = numPhraseGuessesIn;
   }
   
   void setNumLetterGuesses(int numLetterGuessesIn) {
      numLetterGuesses = numLetterGuessesIn;
   }
   
   void setRunningTime(int runningTimeIn) {
      runningTime = runningTimeIn;
   }
   
   void setIsFinished(bool finishedIn) {
      finished = finishedIn;
   }
   
   /*********Member Functions***********/
   
   /**
    * This method determines whether a char is a member of the Game associated with this
    * GameAttempt. This is a core Hangman game functionality.
    * guess a char representing the player's guess
    * returns a bool indicating whether or not the guess was correct
    */
   bool guessLetter(char guess) {
      
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
   bool guessPhrase(vector<string> guess) {
      
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
   bool haveGuessed(char c) {
      
      return getGuesses().contains(c);
      
   }
   
};

#endif