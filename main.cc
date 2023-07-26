#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "functions.h"
#include "block.h"
#include "board.h"
#include "levels.h"
#include "textdisplay.h"
#include "commandInterpreter.h"

using namespace std;

//String of current commands
vector<string> validCommands = {
  "left",
  "right",
  "down",
  "clockwise",
  "counterclockwise",
  "drop",
  "levelup",
  "leveldown",
  "norandom",
  "random",
  "sequence",
  "restart",
  "hint"
};


int main ( int argc, char* argv[]) {

//---------------- process command line arguemnts ------------------

//Default Game Parameters 
  bool text = false; 
  int seed = 0;
  string scriptfile1 = "";
  string scriptfile2 = ""; 
  int startLevel = 0;

  //process Game Paramters
  processGameParameters(argc, argv, text, seed, scriptfile1, scriptfile2, startLevel);
  prettyPrintGameParameters(text, seed, scriptfile1, scriptfile2, startLevel);
  
  int cols = 11;
  int rows = 18;
  vector<vector<char>> matrix1(rows, vector<char>(cols));
  vector<vector<char>> matrix2(rows, vector<char>(cols));

  Board gameBoard1{matrix1, seed, scriptfile1, startLevel };
  Board gameBoard2{matrix2, seed, scriptfile2, startLevel };

  TextDisplay * ob = new TextDisplay(&gameBoard1, &gameBoard2);
  T * iblock1 = new T;
  J * iblock2 = new J;
  gameBoard1.block() = iblock1;
  gameBoard2.block() = iblock2;
  gameBoard1.attach(ob);
  gameBoard2.attach(ob);
  gameBoard1.render();


  TrieNode *commands = new TrieNode; //create new command tree with given vector of commands
  for(int i = 0; i < validCommands.size(); ++i){
    commands->insert(validCommands[i]); //add each command to tree
  }

  //---------------- process player commands ------------------
  //NEED TO DO ELSEWHERE
  string input;
  
  //render empty board

  cout<<"begin inputing commands"<<endl;
  while( getline (cin, input) ){
    //convert input to stream for mutiple commands 
    stringstream ss{input};
    vector<string> commandsVector;
    string temp;
    while( ss >> temp){
      commandsVector.push_back(temp);
    }

      for(int i = 0; i < commandsVector.size(); ++i){
        string command = commandsVector[i];
        auto result = seperateStringFromInt(command);
        //int multi = result.first;
        string fullCommand = commands->search(result.second);

      //should also output player
      cout<<"full command: "<<fullCommand<<endl; //this is feedback for the command

        //update score 
        //render board from the commands
        //ie  clear lines, display score 

        //special actions 
        //if speical actions happen, render board again  

    }

  //deallocate commands
  delete commands; 
  }
}
