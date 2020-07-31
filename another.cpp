/* BATTLESHIP COMMAND LINE EDITION

*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#define HIT "[X]"
#define WATER "[~]"
#define SHIP "[S]"
#define MISS "[M]"
//string HIT="[X]" ,WATER="[~]",SHIP="[S]", MISS="[M]";
using namespace std;
int playerTurn=1;
const int length = 11, width = 11;
string ship_list[] = {"carrier","battleship","cruiser","submarine","destroyer" };
int ship_length[]={5,4,3,3,2};
bool isPlacedP1[]= {false,false,false,false,false};
bool isPlacedP2[]={false,false,false,false,false};
bool isSunkP1[]={false,false,false,false,false};
bool isSunkP2[]={false,false,false,false,false};
 auto placed= playerTurn == 1 ? isPlacedP1 : isPlacedP2;
 auto sunk= playerTurn == 1 ? isSunkP1 : isSunkP2;
string grid1[width][length];
string grid2[width][length];
string radar1[width][length];
string radar2[width][length];
int shipName, direction, x, y;
string input;

bool inRange(int low, int high, int x) { 
  return (low <= x && x <= high); 

}

int find(string ship){
for(int item=0; item < sizeof(ship_list); item++){
  if(ship_list[item]==ship){
    return item;

  }

}
}

void placeShip(string ship, int direction, int x, int y) {
  
   auto grid = playerTurn == 1 ? grid1 : grid2;
    if (direction == 1) {
        for(int i=0; i<ship_length[find(ship)]; i++ ){
            grid[x+i][y]=SHIP;
           
            

        }
        placed[find(ship)]=true;

    }
    if (direction == 2) {
        for(int i=0; i<ship_length[find(ship)]; i++ ){
            grid[x][y+i]=SHIP;
        } 
 
        placed[find(ship)]=true;
    }
}

  void initGrid() {
    // Function used to initialize the grid by setting all entries of the array
    // equal to water.
    for (int l = 0; l < length; l++) {
      for (int w = 0; w < width; w++) {
        grid1[l][w] = WATER;
        grid2[l][w] = WATER;
      }
    }
  }

  void shipList() {
    for (int z = 0; z < sizeof(ship_list) / sizeof(ship_list[0]); z++) {
      if(placed[z]==false){
      cout << ship_list[z] << endl;
    }
  }
  }

  bool isEmpty(){

    if(playerTurn==1){
    for(int i=0; i>sizeof(placed); i++){
      if(isPlacedP1[i]==true){
          return false;
        }
      else {
        cout << "bruh ";
      }
    
    }
    return true;
    }
    else {
         for(int i=0; i>sizeof(placed); i++){
      if(isPlacedP1[i]==true){
          return false;
        }
    else {
        cout << "bruh ";
      }
    }
    return true;
    }
  }

  bool gameStarted() {
    // Checks if all ships are placed before starting the game.
    for(int i=0; i>sizeof(ship_list); i++){
      if(isPlacedP1[i]==true || isPlacedP2[i]==true){
          return true;
        }

    
  }
     return false;
  }

  void changeTurn(){


  }



  void done() {


  }


  

  void printGrid() {
    // Prints the grid.
    if(!isEmpty()){
      cout <<" All ships have been placed. Press 'enter' to continue. \n";
      playerTurn=2;
    }



    if(gameStarted()){
    for (int l = 0; l < length; l++) {
      if (l % 11) {
        cout << "\n";
      }
      for (int w = 0; w < width; w++) {
        if (playerTurn == 1) {
          cout << radar1[l][w];
        } else {
          cout << radar2[l][w];
        }
      }
    }
    cout << "\n";
  }
  
else{   
    for (int l = 0; l < length; l++) {
      if (l % 11) {
        cout << "\n";
      }
      for (int w = 0; w < width; w++) {
        if (playerTurn == 1) {
          cout << grid1[l][w];
        } else {
          cout << grid2[l][w];
        }
      }
    }
    cout << "\n";
}
 }

 

  bool inputOkay(string input) {
    int spaceCount = 0;
    bool shipOK;

    if(!gameStarted()){
    for (int i = 0; i < input.length(); i++) {
      if (input[i] == ' ') {
        spaceCount++;
      }
    }
    if (spaceCount == 3) {
      // The input is valid. We will now convert the string into an array.
      stringstream ssin(input);
      string real_input[4];
      for (int words = 0; words < 4; words++) {
        if (ssin.good()) {
          ssin >> real_input[words];
          cout << real_input[words] << " ";
        }
      }
      cout << endl;
      // Checking for valid ship
      for (int counter = 0;
           counter < (sizeof(ship_list) / sizeof(ship_list[0])); counter++) {
        if (real_input[0] == ship_list[counter]) {
          shipOK = true;
          break;
        }
      }
      if (real_input[1] != "1" && real_input[1] != "2") {
        return false;
      }
      int xpos, ypos;
      xpos = std::stoi(real_input[2]);
      ypos = std::stoi(real_input[3]);
      if (!inRange(0, 10, xpos) || !inRange(0, 10, ypos)) {
        return false;
      }
      if (!shipOK) {
        return false;
      } else {
        placeShip(real_input[0], stoi(real_input[1]), xpos, ypos);
      }
      return true;
    }
    }
    else {
      bool cordsOK;
      for (int i = 0; i < input.length(); i++) {
      if (input[i] == ' ') {
        spaceCount++;
      }
    }
    if (spaceCount == 1) {
      // The input is valid. We will now convert the string into an array.
      stringstream ssin(input);
      int real_input[2];
      for (int words = 0; words < sizeof(real_input); words++) {
        if (ssin.good()) {
          ssin >> real_input[words];
          cout << real_input[words] << " ";
        }
      }
      cout << endl;
      // Checking for valid ship
      for (int counter = 0;
           counter < (sizeof(ship_list) / sizeof(ship_list[0])); counter++) {
        if (inRange(0,10,real_input[0]) && inRange(0,10,real_input[1])) {
          cordsOK = true;
          return true;
        }
      }
    }
    }
    return false;
  }
  bool win(){
     for(int i=0; i>sizeof(placed); i++){
      if(isSunkP1[i]==true || isPlacedP2[i]==true){
          return false;
        }
  }
 return true;
  }
  int main() {
    initGrid();
    cout << "WELCOME TO BATTLESHIP!\n";
    while (!gameStarted()) {
      printGrid();
      cout << "--------------------------------------------- \n";
      cout << " Player " << playerTurn << ". Please place your ships now.\n";
      cout << "Press '1' Vertical or '2' for Horizontal.\n ";
      cout << "SYNTAX: ship position x y \n";
      cout << "| Ships available |\n";
      shipList();
      cout << "--------------------------------------------\n";
      getline(cin, input);
      std::cout << "\e[2J\e[H";
      if (!inputOkay(input)) {
        cout << "ARRRRR!!! Someting is wrong with your input \n";
      } 
      else {
        cout << "QUERY OK!\n";
      }
    }
      while(!win()){
        cout << "--------------------------------------------- \n";
        cout <<"    PLAYER" << playerTurn <<endl;
        cout << "--------------------------------------------- \n";
         printGrid();
        cout << "--------------------------------------------- \n";
        cout << "  SYNTAX: x y  \n";
        cout << "--------------------------------------------- \n";
        getline(cin,input);
       std::cout << "\e[2J\e[H"; 
         if (!inputOkay(input)) {
        cout << "ARRRRR!!! Someting is wrong with your input \n";
      } else {
        cout << "QUERY OK!\n";
      }  
      }
    return 0;
  }
