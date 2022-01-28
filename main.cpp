// Starter file for CSCI 60 Homework 5; due Tuesday 2/9/21
// List any collaborators and write your name here
// Name: Thomas Solecki
// Description: This program does three main things. First, it overloads the >> operator for the vector class. Second, it defines a new class called
// HetPair which has 2 constructors, 2 getter functions, and 2 operators overloaded. Third, it provides test code for both of these features.

#include <iostream>
#include "rational.h"
#include <vector>
using namespace std;

// Part 1: overload << for vector
template <typename T>
ostream& operator <<(ostream& out, vector<T> arr)
{
  // look through entire vector
  for(int i = 0; i < arr.size(); i++)
  {
    out << arr[i] << ", "; // output the value at each index of the vector followed by a comma and space
  }
  return out; // return the ostream
}
// Part 2: design and implement the HetPair class
template<typename T, typename U>
class HetPair
{
public:
  HetPair() : x(T()), y(U()) {}
  HetPair(T x, U y) : x(x), y(y) {}
  T getX() const { return x; }
  U getY() const { return y; }
private:
  T x;
  U y;
};

template<typename T, typename U>
HetPair<T,U> operator +(HetPair<T,U> lhs, HetPair<T,U> rhs)
{
  // Initialize a new Hetpair object to return at the end of the function as the result
  // set the new HetPair object's x and y values to the sums of the lhs's and the rhs's x and y values
  HetPair<T,U> result(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
  // return the answer
  return result;
}

template<typename T, typename U>
ostream& operator <<(ostream& out, HetPair<T,U> obj)
{
  out << "(" << obj.getX() << ", " << obj.getY() << ")";
  return out;
}
// Part 3: write test code
int main()
{
  // Part 3 A
  vector<int> intVec;
  intVec.push_back(2);
  intVec.push_back(4);
  intVec.push_back(4);
  intVec.push_back(-1);
  cout << intVec << endl;

  vector<Rational> ratVec;
  Rational rat1 (3,11);
  Rational rat2 (-1,2);
  Rational rat3(2,1);
  ratVec.push_back(rat1);
  ratVec.push_back(rat2);
  ratVec.push_back(rat3);
  cout << ratVec << endl;
  // Part 3 B
  HetPair<int, double> point1(1, 0.6);
  HetPair<int, double> point2(4, 0.8);
  HetPair<int, double> result = point1 + point2;
  cout << result << endl;
  // Part 3 C
  vector<HetPair<Rational, double>> list;
  int numer, denom;
  cout << "Enter numerator and denominator (0 denom to quit): ";
  cin >> numer >> denom;
  while (denom != 0)
  {
    Rational newRat(numer, denom);
    HetPair<Rational, double> newPair(newRat, newRat.getVal());\
    list.push_back(newPair);
    cout << "Enter numerator and denominator (0 denom to quit): ";
    cin >> numer >> denom;
  }
  cout << list << endl;
  return 0;
}
