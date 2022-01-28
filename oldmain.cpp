// Test program starter file for CSCI 60 Homework 2; due Sunday 1/17/21
// Give a program description, list any collaborators, and write your name here
// Name: Thomas Solecki
// Description: This is a driver program intended to test the histogram class. To do this it calls each function defined in the header file and calls both constructors.

#include <iostream>
#include "histogram.h"

using namespace std;

int main() {
  /* TODO: test your Histogram implementation here */
  Histogram test;
  // testing results of member functions with 0 arg constructor
  cout << "size = " << test.size() << endl;
  cout << "min = " << test.min() << endl;
  cout << "max = " << test.max() << endl;
  cout << "mode = " << test.mode() << endl;
  cout << "median = " << test.median() << endl;
  cout << "mean = " << test.mean() << endl;
  cout << "variance = " << test.variance() << endl;
  cout << "The number 100 occurs " << test[100] << " time(s)" << endl;
  cout << test << endl; // tests zero arg constructor by printing its histogram
  string filename;
  cout << "enter a filename\n";
  cin >> filename;
  Histogram testo(filename);
  // testing the 1 arg constructor
  cout << "size = " << testo.size() << endl;
  cout << "min = " << testo.min() << endl;
  cout << "max = " << testo.max() << endl;
  cout << "mode = " << testo.mode() << endl;
  cout << "median = " << testo.median() << endl;
  cout << "mean = " << testo.mean() << endl;
  cout << "variance = " << testo.variance() << endl;
  cout << "The number 100 occurs " << testo[100] << " time(s)" << endl;
  cout << testo << endl; // prints the histogram
  Histogram testo2(filename);
  testo += testo2;
  // tests the += operator
  cout << "size = " << testo.size() << endl;
  cout << "min = " << testo.min() << endl;
  cout << "max = " << testo.max() << endl;
  cout << "mode = " << testo.mode() << endl;
  cout << "median = " << testo.median() << endl;
  cout << "mean = " << testo.mean() << endl;
  cout << "variance = " << testo.variance() << endl;
  cout << "The number 100 occurs " << testo[100] << " time(s)" << endl;
  cout << testo; // prints the histogram
  return 0;
}
