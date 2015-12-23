//=================================
// include guard

#ifndef CHARLIST_H
#define CHARLIST_H

//=================================
// forward declared dependencies


//=================================
// included dependencies

#include <vector>
#include <string> 

#include "Constants.h"
#include "CharInList.h"

//=================================
// the actual class

using namespace std;

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
   
   vector<CharInList> list;
   
   public:
   
   /********Constructors**********/
   
   CharList(void);
         
   
   /*******Get/set Methods*********/
   
   vector<CharInList> getList();
       
   void setList(vector<CharInList> newList);
   
   
   
   /********Class functions*******/
   
   //none
   
   /******Member functions********/
   
   bool equals(CharList c);
   
   bool isDefined();

   void initialize();

   void initialize(vector<string> phrase);

   void update(vector<string> phrase);

   bool contains(char c);

   void add(char c);

};

  
#endif