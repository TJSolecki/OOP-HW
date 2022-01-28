// Sample code to illustrate suggestion for HW1 P1.
// Krehbiel, 1/4/21

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// global constants
const string FILENAME = "output.txt"; // a name for a text file
const string TEXT = "Lorem ipsum"; // a string to be written to the file

// Pre:  o is an output stream (eg cout or an initialized ofstream)
// Post: o contains a line of text specified by global const TEXT
//       followed by a line containing the int n
void helper(int n, ostream& o);

// Open a file; use helper to write to it; close before terminating
int main() {

  // Declare and initialize a variable favenum local to main.
  // Type is int; initial value is 73.
  int favNum = 73;

  // Declare and initialize another variable outputfile local to main.
  // Type is ofstream; provides a way to write to a file called FILENAME.
  ofstream outputfile(FILENAME); // an ofstream is an ostream for file writing

  // Pass both local vars as arguments to a helper function.
  helper(favNum, outputfile);

  // Close the file before the program terminates.
  outputfile.close();

  // Uncomment the line below to use the same function to write to the console!
  //helper(42, cout); // cout is a particular ostream for writing to the console

  return 0;
}

// Write TEXT and an int to an open file; important to pass the ostream by ref
void helper(int n, ostream& o) {
  o << TEXT << endl; // treat o the way you would treat cout
  o << n << endl;
}
