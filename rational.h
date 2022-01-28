// File for CSCI 60 Homework 5; due Tuesday 2/9/21
// Full interface for Rational class

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using std::string;
using std::to_string;
using std::ostream;

class Rational {
public:
  Rational(int num, int denom) : n(num), d(denom) {}
  Rational() : Rational(0,1) {}
  double getVal() const;
  string toString() const;
private:
  int n;
  int d;
};

ostream& operator <<(ostream& o, const Rational& r);

#endif
