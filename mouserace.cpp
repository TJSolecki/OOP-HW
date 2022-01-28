// Starter file for CSCI 60 Homework 1, Program 2; due Sunday 1/10/21
// Give a program description, list any collaborators, and write your name here
// Name: Thomas Solecki
// Description: The following program simulates a race on a coordinate plane between two racers. The first is a predetermined racer named Alegron
// who starts at the positon (0,0) on the coordinate plane and the second is created by the user who gives the racer a name and starting position.
// The user also determines the target position that both racers are trying to reach. The user also inputs directions for both of the racers to take
// using the letters U (for up) , D (for down), L (for left), and R (for right) to direct each racer. After these directions are given the program
// has each racer take the apropriate moves on the coordinate plane and finds each of the racer's end positions. Finally, the program checks to see who
// made it to the target location and in how many moves and determines a winner which it prints out to the user through the console.
#include <iostream>
using namespace std;

class MazeRacer {
public:
  void moveOne(char c); //function to move the racer's position. Accepts capital U, D, L, and R as inputs
  int getNumMoves(){ return numMoves; } // getter method for numMoves variable
  int getX(){ return xPos; }  // getter method for x position of racer
  int getY(){ return yPos; }  // getter method for y position of racer
  MazeRacer() // empty constructor defualts to the name Algernon with the starting position (0,0)
  {
    name = "Algernon";
    xPos = 0;
    yPos = 0;
    numMoves = 0;
  }
  MazeRacer(string n, int x, int y) // constructor for making the second racer. Allows user to give the racer a name and starting position
  {
    name = n;
    xPos = x;
    yPos = y;
    numMoves = 0;
  }
private:
  //All of the private member variables the class needs for each racer
  string name;
  int xPos;
  int yPos;
  int numMoves;
};

int main() {
  string racer; //holds name of second racer
  int startX, startY, targetX, targetY;
  string algMoves, playerMoves;
  bool algAtTarget, playerAtTarget;
  MazeRacer Algernon;  // instantiating racer with empty constructor to create a racer named Algernon with positon (0,0)

  cout << "The first maze competitor is Algernon, who will start at (0,0).\n";
  cout << "Enter a name for the second maze competitor: ";
  cin >> racer;
  cout << "Enter starting coordinates for " << racer << ": ";
  cin >> startX >> startY;
  cout << "Enter the target coordinates: ";
  cin >> targetX >> targetY;
  cout << "Enter a sequence of moves for Algernon: ";
  cin >> algMoves;
  cout << "Enter a sequence of moves for " << racer << ": ";
  cin >> playerMoves;

  MazeRacer Player(racer, startX, startY); //creates instance of MazeRacer with the name and position provided by the user

  //The following code calculates the positon of the racer Algernon after taking the inputed moves
  for(int i = 0; i < algMoves.length(); i++)
  {
    Algernon.moveOne(algMoves[i]);
  }
  //Output for if Algernon reached the target
  if(Algernon.getX() == targetX && Algernon.getY() == targetY)
  {
    cout << "Algernon was at target (" << targetX << "," << targetY << ") after " << Algernon.getNumMoves() << " moves.\n";
    algAtTarget = true;
  }
  //Output for if Algernon did not reach the target
  else
  {
    cout << "Algernon was at (" << Algernon.getX() << "," << Algernon.getY() << ") after " << Algernon.getNumMoves() << " moves.\n";
    algAtTarget = false;
  }

  //The following code calculates the positon of the second maze racer after taking the inputed moves
  for(int i = 0; i < playerMoves.length(); i++)
  {
    Player.moveOne(playerMoves[i]);
  }
  //Output for if the second maze racer reached the target
  if(Player.getX() == targetX && Player.getY() == targetY)
  {
    cout << racer << " was at target (" << targetX << "," << targetY << ") after " << Player.getNumMoves() << " moves.\n";
    playerAtTarget = true;
  }
  //Output for if the second maze racer did not reach the target
  else
  {
    cout << racer << " was at (" << Player.getX() << "," << Player.getY() << ") after " << Player.getNumMoves() << " moves.\n";
    playerAtTarget = false;
  }

  //The following if statements determine who the winner is and output the result
  if(playerAtTarget && algAtTarget) //checks if both reached the target
  {
    if(Player.getNumMoves() == Algernon.getNumMoves()) //checks for tie
    {
      cout << "Tie!";
    }
    else if(Player.getNumMoves() < Algernon.getNumMoves()) //checks to see who took less moves to determine the winner
    {
      cout << racer << " wins!";
    }
    else
    {
      cout << "Algernon wins!";
    }
  }
  else if(playerAtTarget && !algAtTarget) //checks for the case where the second racer reached the target but Algernon didn't
  {
    cout << racer << " wins!";
  }
  else if(!playerAtTarget && algAtTarget) //checks for the case where Algernon reached the target but the second racer did not
  {
    cout << "Algernon wins!";
  }
  else if(!playerAtTarget && !algAtTarget) //checks for the last possible case which is that neither racer reached the target
  {
    cout << "Tie!";
  }

  return 0;
}

void MazeRacer::moveOne(char c) //function to move the racer's position. Accepts capital U, D, L, and R as inputs
{
  switch(c)
  {
    case 'U':
      yPos++;
      numMoves++;
      break;

    case 'D':
      yPos--;
      numMoves++;
      break;

    case 'L':
      xPos--;
      numMoves++;
      break;

    case 'R':
      xPos++;
      numMoves++;
      break;
  }
}
