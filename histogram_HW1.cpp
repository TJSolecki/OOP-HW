// Starter file for CSCI 60 Homework 1, Program 1; due Sunday 1/10/21
// Give a program description, list any collaborators, and write your name here
// Name: Thomas Solecki
// Description: This program accepts three parameters when called. The first tells the program how many times the dice was rolled in the when the
// rolldice program was called. The second tells the program the file that the rolldice program wrote to. And finally the third tells the program
// which file to write a histogram to based on the data of the dice rolls provided. The program's final product is this histogram which shows the
// frequency of rolls that's sums are between 2 and 12 and shows this frequency through use of asterisks, one for each time a particular sum was rolled.
#include <iostream>
#include <fstream>
using namespace std;

//Helper function that outputs the proper number of stars for each number on the histogram
void writeLineOfStars(int rolls[], int val, ostream& out);

int main(int argc, char *argv[]) {
  // check that user provided enough args and store them in local variables
  if (argc<4) {
    cout << "This program requires at least 3 arguments\n";
    return 1;
  }
  int nRolls = stoi(argv[1]);
  string datafile = argv[2], histfile = argv[3]; // 2 filenames from args list

  int rollRecord[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // an array made to store the number of instances of each roll's sum
  int temp;
  ifstream input;
  input.open(datafile);

  for(int i = 0; i < nRolls; i++)  // reads in the data from the data file created by the rolldice program and stores it into an array
  {
    input >> temp;
    rollRecord[temp - 2]++;
  }
  input.close();

  ofstream output;
  output.open(histfile);
  for(int i = 2; i < 13; i++)  // outputs the data in the array into an output file in a histogram format
  {
    if(i < 10)  // this if statement adds a space before all numbers under 10 so that the stars are alligned properly on the histogram
    {
      output << " ";
    }
    output << i << ": ";
    writeLineOfStars(rollRecord, i, output);
    if(i != 12) // this if statement is in place to prevent an extra new line from being created at the end of the file
    {
      output << "\n";
    }
  }
  output.close();

  return 0;
}

void writeLineOfStars(int rolls[], int val, ostream& out)
{
  for(int j = 0; j < rolls[val - 2]; j++)
  {
    out << "*";
  }
}
