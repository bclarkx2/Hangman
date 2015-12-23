//=================================
// include guard

#ifndef CHARINLIST_H
#define CHARINLIST_H

//=================================
// forward declared dependencies


//=================================
// included dependencies

#include <vector>
#include <string>

//=================================
// the actual class

using namespace std;

 /**
 * An object to keep track of each individual ASCII character. Stores
 * the actual character, as well as a bool indicating whether or not
 * it is present in the CharList
 */
class CharInList {
   
   private:
   char myChar;
   bool isPresent;
   
   public:
   
   /********Constructors**********/
   
   CharInList(char charIn, bool isIn);
   
   /*******Get/set Methods*********/
   
   char getMyChar();
   
   bool getIsPresent();
   
   void setMyChar(char charIn);
   
   void setIsPresent(bool isIn);

   
   /******Member functions********/
   
   /**
    * Two charInLists are equal if they are the same letter and both are present or not present
    * c the charInList to be compared with
    * return bool indicating whether they are equal
    */
   bool equals(CharInList c);
      
};

  
#endif
