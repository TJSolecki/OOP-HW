// Driver program that uses the Bag class to keep track of a several integers,
// possibly with repetition. Demonstrates how to add to a bag and query size.
//
// Note: You must compile implementation file to run this, e.g.,
//   $ g++ main.cpp bag.cpp -std=c++11
//
// Sara Krehbiel, 1/13/21 (W Week 2, file 1/3)

#include <iostream>
#include "bag.h"

using namespace std;

void announceCapacity(); // print capacity of any Bag, w/o an actual object
void constructionInsertionSizeTests(); // construct bag obj, run initial tests
void displayContentsTwoWays(Bag& b); // print contents of existing bag obj

int main() {
  announceCapacity();
  constructionInsertionSizeTests();
}

// cout a message about how many elements a bag can hold
void announceCapacity() {
  // access static variables w/ scope resolution vs dot operator (no object!)
  cout << "Any Bag has capacity " << Bag::CAPACITY << endl; // NEED: static var
}

// construct a bag, report size before and after inserting some elements
void constructionInsertionSizeTests() {
  Bag b; // NEED: 0-arg constructor to set up empty Bag object
  cout << "Initial bag size: " << b.size() << endl; // NEED: size function
  b.insert(5); // NEED: insert function
  b.insert(6);
  b.insert(5);
  b.insert(5);
  b.erase_one(5);
  cout << b << endl;
  b.erase(5);
  cout << b << endl;
  cout << "Current bag size: " << b.size() << endl;

  displayContentsTwoWays(b);
}

// print contents of a bag object to console
void displayContentsTwoWays(Bag& b) {
  // print all contents entry-by-entry using array-like indexing of the bag
  for(size_t i=0; i<b.size(); i++){ // note return type of size
    //cout << b[i] << " "; // TODO: overload []
  }
  cout<<endl;

  // print all contents at once inserting the bag into cout
  //b.print(); // a normal member function
  //cout << b; // TODO: overload << instead of writing/calling b.print()
  cout << endl;
}
