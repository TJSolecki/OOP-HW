// Interface for static array implementation of a container called Bag,
// which holds up to CAPACITY ints, possibly with repetition;
// supports size, count per value, [] lookup, insert, delete
//
// New concepts: size_t, static consts, private member var naming conventions
//
// Sara Krehbiel, modified code from Natalie Linnell and Nicholas Tran
// 1/13/21 (W Week 2, file 2/3)

#ifndef BAG_H
#define BAG_H

#include <cstdlib>
#include <algorithm>
#include <ostream>
//#include <iostream> // this is necessary only for print

// Note: Using namespace std in class defns results in namespace pollution;
//       we're doing this bad practice today only to minimize new syntax.
using namespace std;

class Bag {
public:
  // STATIC CONSTANTS
  static const size_t CAPACITY = 1000; // static = NOT a member variable
  /* When would you use only one of static/const?
  static size_t numberOfBagsProduced = 0; // keep track of total # objects
  // call from main like Bag::numberOfBagsProduced; increment inside constructor
  const string MONOGRAM; // an unchangeable string associated with a bag object
  // call from main like b.MONOGRAM; initialize inside constructor, never change
   */

  // CONSTRUCTORS
  Bag(); // create an (initially) empty bag
  Bag(int arr[], size_t size); // create bag with the (size) contents of arr

  // CONSTANT ACCESSOR MEMBER FUNCTIONS
  size_t size() const; // number of elements currently stored
  size_t count(int target) const; // number of copies of target
  int operator [](size_t pos) const; // item at given pos
  /*void print() const {
    for (size_t i=0; i<size_; i++) {
      cout << data_[i] << " ";
    }
    cout << endl;
  }*/

  // MUTATOR MEMBER FUNCTIONS
  void insert(int target); // if there's capacity, add a copy of target
  bool erase_one(int target); // remove a copy of target
  size_t erase(int target); // remove all k copies of target and return k
  void operator +=(const Bag & rhs); // if there's capacity, add rhs contents

private:
  int data_[CAPACITY];
  size_t size_; // note: in defining a data structure, private vars often use _

  // INVARIANTS: data_[0],...,data_[size_-1] always contain the elements
};

Bag operator +(const Bag & lhs, const Bag & rhs); // combine contents of 2 bags

ostream& operator <<(ostream& out, const Bag& b); // output contents to ostream

#endif
