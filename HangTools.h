 //=================================
// include guard

#ifndef HANGTOOLS_H
#define HANGTOOLS_H

//=================================
// forward declared dependencies

      //none

//=================================
// included dependencies

#include <vector>
#include <string>

#include "Constants.h"
#include "Game.h"
#include "GameAttempt.h"

//=================================
// Hangtools

using namespace std;


class HangTools {
   
   private:
   
   public:
   
   /********Constructors**********/
   
   HangTools(void);
   
   /*******Get/set Methods*********/
   
   
   /********Class functions*******/
   
   static Game selectAGame();
   
   static bool equalsIgnoreCase(string s1, string s2);

   /******Member functions********/
   
      //none   

};

#endif