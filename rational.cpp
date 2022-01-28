// File for CSCI 60 Homework 5; due Tuesday 2/9/21
// Full implementation for Rational class

#include "rational.h"

double Rational::getVal() const {
  return 1.0*n/d;
}

string Rational::toString() const {
  return to_string(n)+"/"+to_string(d);
}

ostream& operator <<(ostream& o, const Rational& r) {
  o << r.toString();
  return o;
}
