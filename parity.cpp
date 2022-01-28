// Implementation starter file for CSCI 60 Homework 4; due Tuesday 2/2/21
// List any collaborators and write your name here
// Name: Thomas Solecki
// Description: This program defines the functions and constructors declared in the parity header file that were not declared.
// Specificly these defintions include a copy constructor, a destructor, a assignment overload, an insert functions, functions
// to find both the min and max, a function to determine whether or not a parity is odd or not, and a functions to print out both arrays of a parity.

#include "parity.h" // Don't add any additional libraries/namespaces!

Parity::Parity(const Parity& other) // this is a copy constructor which initailizes a parity with all of the same values as another parity
{
  // setting the number member variables to the other object
  nOdd_ = other.nOdd_;
  nEven_ = other.nEven_;
  // finding the size of the other object's arrays
  int oddSize = nOdd_ % CAP == 0 ? nOdd_ : nOdd_ + (CAP - (nOdd_ % CAP));
  int evenSize = nEven_ % CAP == 0 ? nEven_ : nEven_ + (CAP - (nEven_ % CAP));
  // setting the new object's arrays to be created with the same size as the other object's
  odds_ = new int[oddSize];
  evens_ = new int[evenSize];
  // copying over the values of each of the arrays into the new object
  for(size_t i = 0; i < nOdd_; i++)
  {
    odds_[i] = other.odds_[i];
  }
  for(size_t i = 0; i < nEven_; i++)
  {
    evens_[i] = other.evens_[i];
  }
}

Parity::~Parity() // this destructor deletes all of the dynamic memory being used in a parity and returns it to its defualt values
{
  // deleting the objects arrays
  delete [] odds_;
  delete [] evens_;

  //setting the objects member variables to their default values
  odds_ = nullptr;
  evens_ = nullptr;
  nOdd_ = 0;
  nEven_ = 0;
}

Parity& Parity::operator =(const Parity& rhs) // overloads the = operator to allow someone to make a deep copy of one parity into another
{
  // set the number of elements in each of the arrays to the numbers from the rhs object
  nOdd_ = rhs.nOdd_;
  nEven_ = rhs.nEven_;
  // determining how large the rhs's arrays were and storing those values in variables to be used when initializing the new arrays
  int oddSize = nOdd_ % CAP == 0 ? nOdd_ : nOdd_ + (CAP - (nOdd_ % CAP));
  int evenSize = nEven_ % CAP == 0 ? nEven_ : nEven_ + (CAP - (nEven_ % CAP));
  // delete the old arrays that the lhs object had
  delete [] odds_;
  delete [] evens_;
  // make new arrays for the lhs object with the correct sizes
  odds_ = new int[oddSize];
  evens_ = new int[evenSize];
  // copy over the values from the rhs into the lhs object
  for(size_t i = 0; i < nOdd_; i++)
  {
    odds_[i] = rhs.odds_[i];
  }
  for(size_t i = 0; i < nEven_; i++)
  {
    evens_[i] = rhs.evens_[i];
  }
  //return the lhs object
  return *this;
}

void Parity::insert(int val) // inserts a defined value into the parity and puts it into an even or an odd array as needed
{
  if(val % 2 == 0)
  {
    // if even
    if(nEven_ % 5 == 0) // checks if array needs to be expanded
    {
      // Make a new array of previous size + CAP
      int* newArr = new int[nEven_ + CAP];
      // copy all prevoious values of evens_ into the new array
      for(size_t i = 0; i < nEven_; i++)
      {
        newArr[i] = evens_[i];
      }
      // delete old array
      delete [] evens_;
      // give evens_ the pointer to our new array
      evens_ = newArr;
    }
    evens_[nEven_] = val;
    nEven_++;
  }
  else
  {
    // if odd
    if(nOdd_ % 5 == 0) // checks if the array needs to be expanded
    {
      // Make a new array of previous size + CAP
      int* newArr = new int[nOdd_ + CAP];
      // copy all prevoious values of odds_ into the new array
      for(size_t i = 0; i < nOdd_; i++)
      {
        newArr[i] = odds_[i];
      }
      // delete old array
      delete [] odds_;
      // give odds_ the pointer to our new array
      odds_ = newArr;
  }
  odds_[nOdd_] = val;
  nOdd_++;
  }
}

int Parity::min() const // finds the smallest value stored in the Parity
{
  // initializing min varible to be the largest possible int value
  int min = INT_MAX;
  // look through even array and find its smallest value
  for(size_t i = 0; i < nEven_; i++)
  {
    if(evens_[i] < min)
    {
      min = evens_[i];
    }
  }
  // look through the odd array to find the smallest value
  for(size_t i = 0; i < nOdd_; i++)
  {
    if(odds_[i] < min)
    {
      min = odds_[i];
    }
  }
  return min;
}

int Parity::max() const // finds the largest value stored in the Parity
{
  // initializing max value to be the smallest possible int value
  int max = INT_MIN;
  //looks through the even array to find the largest value
  for(size_t i = 0; i < nEven_; i++)
  {
    if(evens_[i] > max)
    {
      max = evens_[i];
    }
  }
  // looks through the odd array to find the largest value
  for(size_t i = 0; i < nOdd_; i++)
  {
    if(odds_[i] > max)
    {
      max = odds_[i];
    }
  }
  return max;
}

bool Parity::odd() const // finds out whether the total value of all the ints stored in a parity are odd or not
{
  // if there is an odd number of odd numbers than the total has to be odd so the function returns true
  // if there are an even number of odd numbers or 0 then the total has to be even so the function returns false
  return nOdd_ % 2;
}

// couts two lines of text representing the even and odd values, respectively
void Parity::printAll() const {
  std::cout << "Evens: ";
  for (size_t i=0; i<nEven_; i++) std::cout << evens_[i] << ", ";
  std::cout << "\nOdds:  ";
  for (size_t i=0; i<nOdd_; i++) std::cout << odds_[i] << ", ";
  std::cout << std::endl;
}
