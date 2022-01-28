// Ready-to-run program for CSCI 60 Homework 1, Question 1.
// User runs the program with two or three arguments; the first specifies
// how many pairs of dice to roll, the second specifies a name for a file to
// record all these values, and the user can optionally include a third
// argument that specifies a seed for the random generator to force the
// simulation to generate the same rolls each time.
//
// Krehbiel, 1/4/21

#include <iostream>
#include <fstream>
using namespace std;

// returns the value (between 2 and 12) of a toss of a pair of random dice
int getRoll() { return (rand()%6+1 + rand()%6+1); }

int main(int argc, char *argv[]) {
  if (argc<3) {
    cout << "Specify how many rolls to simulate and where to record them.\n";
    return 1;
  }

  int nRolls = stoi(argv[1]); // note: this expects the extra arg to be a string
  string filename = argv[2];
  if (argc>3) srand(stoi(argv[3])); // seed rand with user-specified value
  else srand(time(NULL)); // seed rand with true randomness (time)

  ofstream datafile(filename); // create or open
  for (int i=0; i<nRolls; i++) {
    datafile << getRoll() << endl; // simulate 1 roll and write it to the file
  }
  datafile.close(); // close the file
  return 0;
}
