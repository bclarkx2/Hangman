/**
 * Hangman Driver
 *
 * This file contains all command line interface and user interaction features for this
 * Hangman application. All the individual functions can be accessed directly from things 
 * in the HangTools header file. 
 *
 * Here, by contrast, you just run from the command line with whatever mode you want to
 * use.
 *
 * Note: put a better description here...
 *
 */

#include <iostream>
#include <ctime>
#include <sstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <iterator>

#include "Constants.h"
#include "HangTools.h"

using namespace std;


enum ParseError {

   LETTER_GUESS_TOO_LARGE,
   INVALID_PHRASE_GUESS,
   INVALID_COMMAND_TYPE, 
   NOTHING_ENTERED,
   UNIDENTIFIED,
   NOT_LONG_ENOUGH
   
};

enum Command {
   
   COMMAND_INVALID = -1,
   COMMAND_HUMANSOLVE

};
// 
// const option::Descriptor usage[] =
//    {
//      {COMMAND_INVALID   , 0,"" , ""    ,option::Arg::None, "USAGE: example [options]\n\n" "Options:" },
//      {HELP              , 0,"" , "help",option::Arg::None, "  --help  \tPrint usage and exit." },
//      {PLUS              , 0,"p", "plus",option::Arg::None, "  --plus, -p  \tIncrement count." },
//      {UNKNOWN           , 0,"" ,  ""   ,option::Arg::None, "\nExamples:\n"
//                                              "  example --unknown -- --this_is_no_option\n"
//                                              "  example -unk --plus -ppp file1 file2\n" },
//      {0,0,0,0,0,0}
//    };


/*****Static methods******/

static int ASCIIindex(char c) {
   return static_cast<int>(c)-ASCIIstart;
}


 /**
  * Command parser: read the command line options and inputs and tells the main method what mode to execute
  * @argc the number of characters in the command line input
  * @argv the character array holding the command line input
  * @return a Command value corresponding to the user-selected mode
  */
static Command parseCommandLine(int argc, char* argv[]) {

   Command returnCommand;

   returnCommand = COMMAND_HUMANSOLVE;

   // if(string(argv[1] == "human") {
      // returnCommand = COMMAND_HUMANSOLVE;
   // }
   // else {
      // returnCommand = COMMAND_INVALID;
   // }
   

   return returnCommand;
}

static string getFirstWord(string stringIn) {
   
   string returnWord = string();
   
   //Initial problems
   if(stringIn.size() == 0) {                      //Input is not really a string
      throw NOTHING_ENTERED;
   }
   
   //Split input into words
   string buf;                                     // Buffer string
   stringstream ss(stringIn);                      // Insert into string

   vector<string> tokens;                          // Word vector

   while (ss >> buf)
      tokens.push_back(buf);
   
   
   //Find problems with tokens
      
   
   //Select first word as firstWord
   
   returnWord = tokens[0];
   
   return returnWord;
}

static vector<string> getRemainder(string stringIn) {
   
   vector<string> returnVector = vector<string>();
   
   //Initial problems
   if(stringIn.size() == 0) {                      //Input is not really a string
      throw NOTHING_ENTERED;
   }
   
   //Split input into words
   string buf;                                     // Buffer string
   stringstream ss(stringIn);                      // Insert into string

   vector<string> tokens;                          // Word vector

   while (ss >> buf)
      tokens.push_back(buf);
   
   
   //Find problems with tokens
   if(tokens.size() == 1) {
      throw(NOT_LONG_ENOUGH);
   }
      
      //Remove first word
   tokens.erase(tokens.begin());
   
   return tokens;
   
}



static GameAttempt humanSolve(Game game) {
   
   //Tools to use
   const long double startTime = time(0);
   GameAttempt attempt = GameAttempt(game);
   
   string command = string();
   string firstWord = string();
   vector<string> remainder = vector<string>();
   
   string resultMessage = string();
   
   
   //Instructions
   cout << "Human solve selected." << endl;
   cout << "Enter guess ___ and then your guess for the phrase. Enter letter _ then the ASCII character you wish to guess." << endl;
   cout << "At each step, the system will give you a readout of your current progress." << endl;
   cout << "Enter \"quit\" to exit" << endl;
   cout << "Good luck." << endl;
   
   
   //Main while loop
   do {
         
      //Display game status
      cout << attempt.status() << endl;
      
      
      //Logic
      try{
            
            //Parse user input
         getline(cin, command);
      
         firstWord = getFirstWord(command);                          //Will throw exception if nothing entered
         remainder = getRemainder(command);                          //Will throw exception if only one token is entered            
         
         //Logic
         if(HangTools::equalsIgnoreCase(firstWord, "letter")){       //Trying to guess a letter
         
         
            //Identify problems
            if(remainder.size() > 1) {                               //Remainder is more than one word
               throw LETTER_GUESS_TOO_LARGE;
            }
            else if(remainder.size() == 1) {                         //Remainder is one word...
               if(remainder[0].size() > 1) {                         //...but the word is more than a letter
                  throw LETTER_GUESS_TOO_LARGE;
               } 
            }
            else {
               throw UNIDENTIFIED;
            }
            
            //Execute guess
            char c = remainder[0][0];
            if(attempt.guessLetter(c)) {                             //If the guess was successful, set a success message
               resultMessage = "Correct guess!";
            }
            else {                                                   //Otherwise, set the message to failure
               resultMessage = "Incorrect guess.";
            }
            
         }
         else if(HangTools::equalsIgnoreCase(firstWord, "guess")){        //Trying to guess a phrase
         
         //Identify problems
         
            //none
            
         
         //Execute guess
            if(attempt.guessPhrase(remainder)) {                     //If the guess was successful, set a success message and end the game
               resultMessage = "Success! You got it!";
               command = "quit";
            /*
             CODE TO DEAL WITH HAVING WON
             */
            
            }
            else {
               resultMessage = "Incorrect phrase guess";
            }
         }
         else{                                                       //Confused
            throw INVALID_COMMAND_TYPE;
         }
            
      }
         catch(ParseError e) {
         
         
            switch(e) {
            
               case NOTHING_ENTERED:
                  {
                     resultMessage = "Nothing entered";
                  } 
                  break;
            
               case NOT_LONG_ENOUGH:
                  {
                     resultMessage = "Command did not contain enough information";
                  } 
                  break;
                  
               case INVALID_COMMAND_TYPE:
                  {
                     resultMessage = "Command was neither \"guess\" nor \"letter\". Please try again";
                  }
                  break;
                
               case LETTER_GUESS_TOO_LARGE:
                  {
                     resultMessage = "Failure. You can only guess a single letter. Please try again";
                  }
                  break;
               
               case UNIDENTIFIED:
                  {
                     resultMessage = "There has been a disturbance in the Force. Please try again with a less stupid command.";
                  }
                  break;
               default:
                  {
                     resultMessage = "Mistakes were made. Probably by you. Sorry not sorry.";
                  }
            }
         }
         
      cout << dec << resultMessage << endl;                 //Display result of previous operation. May be error.
      
   }
   while(!HangTools::equalsIgnoreCase(command, "quit"));
   
   
   //We will return the attempt documenting the solution attempt
   return attempt;
}



/**
 * Main method of the driver
 */
int main(int argc, char* argv[]) {
  
   argc-=(argc>0); argv+=(argc>0);
  
   Command command;
   command = parseCommandLine(argc, argv);
   
   
   //Based on result of parseCommandLine, we will choose a mode to execute
   switch(command) {
      
      case COMMAND_HUMANSOLVE: 
         { 
            humanSolve(HangTools::randomGame(HangTools::getRandomNumber(0,10)));
         }
         break;
         
      case COMMAND_INVALID: 
         {;}
         break;
      
         
      default: 
         {cout << "Confusion!" << endl;
         }
         break;
   }
        
   return 0;
}

static void testGetFirstWord(string command) {
   
   cout << "With input " << command << " we get first word result: ";
   
   try {
      cout << getFirstWord(command) << endl;
   }
      catch(ParseError e) {
      
         string errorMessage = string();
         
         switch(e) {
         
            case NOTHING_ENTERED:
               {
                  errorMessage = "Nothing entered";
               } 
               break;
            
            case NOT_LONG_ENOUGH:
               {
                  errorMessage = "Command did not contain enough information";
               } 
               break;
         }
            
         cout << errorMessage << endl;
      }
}

static void testGetRemainder(string command) {
   
   cout << "With input " << command << " we get remainder result: ";
   
   try {
      vector<string> remainder = getRemainder(command);
      for(int i = 0; i < remainder.size(); i++) {
         cout << remainder[i] << " ";
      }
   }
      catch(ParseError e) {
      
         string errorMessage = string();
         
         switch(e) {
         
            case NOTHING_ENTERED:
               {
                  errorMessage = "Nothing entered";
               } 
               break;
            
            case NOT_LONG_ENOUGH:
               {
                  errorMessage = "Command did not contain enough information";
               } 
               break;
         }
            
         cout << errorMessage;
      }
   
   cout << endl;
}

static void testHumanSolve(string command) {
   
   //Tools to use
   const long double startTime = time(0);
   GameAttempt attempt = GameAttempt(HangTools::randomGame(3));
   
   string firstWord = string();
   vector<string> remainder = vector<string>();
   
   string resultMessage = string();

   
   
   //Main while loop
         
      //Display game status
      //cout << attempt.status();
      
      
      //Logic
   try{
            
            //Parse user input
      
      firstWord = getFirstWord(command);                          //Will throw exception if nothing entered
      remainder = getRemainder(command);                          //Will throw exception if only one token is entered            
      
      // cout << "Commaand: " << command << endl;
      // cout << "First word: " << firstWord << endl;
      // cout << "Remainder: " << endl;
   //    
      // for(int i = 0; i < remainder.size(); i++) {
         // cout << remainder[i] << " ";
      // }
      // cout << endl << endl;
         
         //Logic
      if(HangTools::equalsIgnoreCase(firstWord, "letter")){       //Trying to guess a letter
         
         
            //Identify problems
         if(remainder.size() > 1) {                               //Remainder is more than one word
            throw LETTER_GUESS_TOO_LARGE;
         }
         else if(remainder.size() == 1) {                         //Remainder is one word...
            if(remainder[0].size() > 1) {                         //...but the word is more than a letter
               throw LETTER_GUESS_TOO_LARGE;
            } 
         }
         else {
            throw UNIDENTIFIED;
         }
            
            //Execute guess
         char c = remainder[0][0];
         if(attempt.guessLetter(c)) {                             //If the guess was successful, set a success message
            resultMessage = "Correct guess!";
         }
         else {                                                   //Otherwise, set the message to failure
            resultMessage = "Incorrect guess.";
         }
            
      }
      else if(HangTools::equalsIgnoreCase(firstWord, "guess")){        //Trying to guess a phrase
      
         //Identify problems
         
            //none
            
         
         //Execute guess
         if(attempt.guessPhrase(remainder)) {                     //If the guess was successful, set a success message and end the game
            resultMessage = "Success! You got it!";
            
            /*
             CODE TO DEAL WITH HAVING WON
             */
            
         }
         else {
            resultMessage = "Incorrect phrase guess";
         }
      }
      else{                                                       //Confused
         throw INVALID_COMMAND_TYPE;
      }
            
   }
      catch(ParseError e) {
         
         
         switch(e) {
            
            case NOTHING_ENTERED:
               {
                  resultMessage = "Nothing entered";
               } 
               break;
            
            case NOT_LONG_ENOUGH:
               {
                  resultMessage = "Command did not contain enough information";
               } 
               break;
                  
            case INVALID_COMMAND_TYPE:
               {
                  resultMessage = "Command was neither \"guess\" nor \"letter\". Please try again";
               }
               break;
                
            case LETTER_GUESS_TOO_LARGE:
               {
                  resultMessage = "Failure. You can only guess a single letter. Please try again";
               }
               break;
               
            case UNIDENTIFIED:
               {
                  resultMessage = "There has been a disturbance in the Force. Please try again with a less stupid command.";
               }
               break;
            
            default:
               {
                  resultMessage = "Mistakes were made. Probably by you. Sorry not sorry.";
               }
         }
      }
         
   cout << command << ": " << resultMessage << endl;
}

/*
int main() {

   cout << boolalpha;

   //Testing equalsIgnoreCase
   
   // cout << boolalpha;
   // cout << "hello, HELLO " <<  HangTools::equalsIgnoreCase("hello", "HELLO") << endl;
   // cout << "he!llo, HE!LLO " <<  HangTools::equalsIgnoreCase("he!llo", "HE!LLO") << endl;
   // cout << "!@#, !@# " <<  HangTools::equalsIgnoreCase("!@#", "!@#") << endl;
   // cout << "hello, HELLo " <<  HangTools::equalsIgnoreCase("hello", "HELLo") << endl;
   // cout << "hello, HIthere " <<  HangTools::equalsIgnoreCase("hello", "HIthere") << endl;
       
   //Testing getFirstWord
      
   // testGetFirstWord("");
   // testGetFirstWord("j");
   // testGetFirstWord("letter");
   // testGetFirstWord("guess");
   // testGetFirstWord("random");
   // testGetFirstWord("a f");
   // testGetFirstWord("letter random");
   // testGetFirstWord("letter a b");
   // testGetFirstWord("letter a");
   // testGetFirstWord("guess a random phrase");
      
   //Testing getRemainder
      
   // testGetRemainder("");
   // testGetRemainder("j");
   // testGetRemainder("letter");
   // testGetRemainder("guess");
   // testGetRemainder("random");
   // testGetRemainder("a f");
   // testGetRemainder("letter random");
   // testGetRemainder("letter a b");
   // testGetRemainder("letter a");
   // testGetRemainder("guess a random phrase");
      
   //Testing humanSolve
      
      
      //Guessing letters
   // testHumanSolve("");
   // testHumanSolve("a");
   // testHumanSolve("random");
   // testHumanSolve("letter");
   // testHumanSolve("letter a");
   // testHumanSolve("letter random");
   // testHumanSolve("letter a random phrase");  
   // testHumanSolve("letter b");
   
      //Guessing phrases
   // testHumanSolve("");
   // testHumanSolve("a");
   // testHumanSolve("random");
   // testHumanSolve("guess");
   // testHumanSolve("guess a");
   // testHumanSolve("guess random");
   // testHumanSolve("guess a random phrase");
   // testHumanSolve("guess Billy Joe Bob");

   //Testing getRandomNumber
   
   // cout << "(0,0): " << HangTools::getRandomNumber(0,0) << endl;
   // cout << "(0,1): " << HangTools::getRandomNumber(0,1) << endl;
   // cout << "(0,100): " << HangTools::getRandomNumber(0,100) << endl;
   // cout << "(1,1): " << HangTools::getRandomNumber(1,1) << endl;
   // cout << "(1,100): " << HangTools::getRandomNumber(1,100) << endl;
   // cout << "(2,334): " << HangTools::getRandomNumber(2,334) << endl;
//    
   // cout << "(-1,30): " << HangTools::getRandomNumber(-1,30) << endl;
   // cout << "(-10,34): " << HangTools::getRandomNumber(-10,34) << endl;
   // cout << "(-349,-329): " << HangTools::getRandomNumber(-349,-329) << endl;
//    
   // cout << "(9,4): " << HangTools::getRandomNumber(9,4) << endl;
   
   //Testing randomGame
   
   //Input 0
   Game g1 = HangTools::randomGame(0);
   vector<string> p1 = g1.getPhrase();
   
   cout << "Input = 0. Phrase generated: \"";
   for(int i = 0; i < p1.size(); i++) {
      cout << p1[i] << " ";
   }
   cout << "\"" << endl;
   
   
   //Input 1
   Game g2 = HangTools::randomGame(1);
   vector<string> p2 = g2.getPhrase();
   
   cout << "Input = 1. Phrase generated: \"";
   for(int i = 0; i < p2.size(); i++) {
      cout << p2[i] << " ";
   }
   cout << "\"" << endl;
   
   //Input 2
   Game g3 = HangTools::randomGame(2);
   vector<string> p3 = g3.getPhrase();
   
   cout << "Input = 2. Phrase generated: \"";
   for(int i = 0; i < p3.size(); i++) {
      cout << p3[i] << " ";
   }
   cout << "\"" << endl;
   
   
   //Input 10
   Game g4 = HangTools::randomGame(10);
   vector<string> p4 = g4.getPhrase();
   
   cout << "Input = 10. Phrase generated: \"";
   for(int i = 0; i < p4.size(); i++) {
      cout << p4[i] << " ";
   }
   cout << "\"" << endl;
   
   return 0;
}
*/
