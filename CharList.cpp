
#include "CharList.h"


CharList::CharList(void) {

}


/*******Get/set Methods*********/

vector<CharInList> CharList::getList() {
   return list;
}

void CharList::setList(vector<CharInList> newList) {
   list = newList;
}



/********Class functions*******/

//none

/******Member functions********/

/**
 * Compares two lists of characters. Goes to each character and compares the char/bool tuple.
 * Returns true if they match for every character.
 */
bool CharList::equals(CharList c) {
   
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
bool CharList::isDefined() {
   return !getList().empty();
}

/**
 * Makes the CharList blank. Every character is set to not present.
 */
void CharList::initialize() {

   vector<CharInList> newList = vector<CharInList>();             //Brand new charInList vector
  
   for(int i = ASCIIstart; i <= ASCIIend; i++) {                   //Add a charInList for every ASCII character
      CharInList cin = CharInList(static_cast<char>(i), false);
      newList.push_back(cin);
   }

   setList(newList);
}

/**
 * Sets the CharList to reflect a given phrase. Wipes out previous information
 */
void CharList::initialize(vector<string> phrase) {
   
   //Set blank
   initialize();
      
   update(phrase);

}
  
/**
 * Adds characters from the phrase to the CharList. Does not wipe out previous information
 */
void CharList::update(vector<string> phrase) {
   
   vector<CharInList> cList = getList();
   
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
bool CharList::contains(char c) {
   
   int n = static_cast<int>(c) - ASCIIstart;
   return getList()[static_cast<int>(n)].getIsPresent();
   
}
  
  /**
* Takes a character and marks it as present in the CharList
* c the character to the be marked present
*/
void CharList::add(char c) {
   
   int n = static_cast<int>(c);
   
   if(n <= ASCIIend && n >= ASCIIstart) {
   
      vector<CharInList> cList = getList();
   
      int m = n - ASCIIstart;
      cList[static_cast<int>(m)].setIsPresent(true);
   
      setList(cList);
   }
}