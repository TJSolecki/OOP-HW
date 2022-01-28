// Interface file for CSCI 60 Homework 4; due Tuesday 2/2/21

#ifndef PARITY_H
#define PARITY_H

#include <iostream>
#include <climits>

class Parity {
public:
  // constructors and functions to override for dynamic memory management
  Parity() : nEven_(0), nOdd_(0), evens_(nullptr), odds_(nullptr) { };
  Parity(const Parity& other);
  ~Parity();
  Parity& operator=(const Parity& rhs);

  // mutator
  void insert(int val);

  // accessors
  int min() const;
  int max() const;
  bool odd() const;
  void printAll() const;

private:
  size_t nEven_;
  size_t nOdd_;
  int *evens_;
  int *odds_;
  static const size_t CAP = 5;
  // INVARIANTS: evens_ points to a dynamic array of the nEven_ even ints;
  //             odds_ points to a dynamic array of the nOdd_ odd ints.
  //             Both should reflect the order values have been provided to
  //             insert calls to this object and/or objects that were previously
  //             copy-constructed / assigned into this object.
  //             The capacity of each should be the smallest multiple of CAP
  //             that is at least the array size.
};

#endif
