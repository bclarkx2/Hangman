   #include "Game.h"
#include <string>
#include <iostream>
#include <cassert>

int main() {
   
   Game g0;
   
   assert(g0.getMaxWords() == 0);
   assert(g0.getMaxLetters() == 0);
      
   Game g1(1,2);
   
   assert(g1.getMaxWords() == 1);
   assert(g1.getMaxLetters() == 2);
   
   std::vector<std::string> vin;
   vin.push_back("Billy");
   vin.push_back("Joe");
   
   Game g2 (vin);
   
   assert(g2.getPhrase()[0] == "Billy");
   assert(g2.getPhrase()[1] == "Joe");
   assert(g2.getMaxWords() == 2);
   
   
   return 0;
}