#include "HangTools.h"


      /**********Constructors********/

HangTools::HangTools(void) {

}
   
   /*******Get/set Methods*********/
   
      //none
   
   /********Class functions*******/
   
Game HangTools::selectAGame() {
   
   std::vector<std::string> game;
   game.push_back("Billy");
   game.push_back("Joe");
   game.push_back("Bob");


   return game;
}

bool HangTools::equalsIgnoreCase(string s1, string s2) {
   
   bool success = true;
   
   if(s1.size() != s2.size()) {
      success = false;
   }
   for(int i = 0; i < s1.size() && success; i++) {
      if(tolower(s1[i]) != tolower(s2[i])) {
         success = false;
      }
   }
   
   return success;
}

   /******Member functions********/
   
      //none   
