
#include "CharInList.h"

using namespace std;


/********Constructors**********/

CharInList::CharInList(char charIn, bool isIn) {
   myChar = charIn;
   isPresent = isIn;
}

/**********Get/Set Methods**********/

char CharInList::getMyChar(){
   return myChar;
}

bool CharInList::getIsPresent(){
   return isPresent;  
}

void CharInList::setMyChar(char charIn){
   myChar = charIn;
}

void CharInList::setIsPresent(bool isIn) {
   isPresent = isIn;
}

/********Member Functions**********/

 /**
  * Two charInLists are equal if they are the same letter and both are present or not present
  * c the charInList to be compared with
  * return bool indicating whether they are equal
  */
bool CharInList::equals(CharInList c) {
   if(getIsPresent() == c.getIsPresent() && getMyChar() == c.getMyChar()) {
      return true;
   }
   else {
      return false;
   }
}
