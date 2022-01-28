// Implementation starter file for CSCI 60 Homework 2; due Sunday 1/17/21
// List any collaborators and write your name here
// Name: Thomas Solecki
// Description: This file contains the fuction and constructor definitions for the function and constructor declarations in the header file for the histogram class.

#include "histogram.h"

/* TODO: implement the functions declared in histogram.h here */
Histogram::Histogram()
{
  for(int i = 0; i < MAX+1; i++) // initializes the counts array to contain all 0s
  {
    counts[i] = 0;
  }
}

Histogram::Histogram(string filename)
{
  for(int i = 0; i < MAX+1; i++) // initializes the counts array to contain all 0s
  {
    counts[i] = 0;
  }
  ifstream input;
  input.open(filename);
  int temp;
  while(input >> temp) // reads in the values from the file given by the constructor call and stores the number of occurrences of each number less than 100 in the counts array
  {
    if(temp <= 100 && temp >= 0)
    {
      counts[temp]++;
    }
  }
}

size_t Histogram::size() const
{
  size_t size = 0;
  for(int i = 0; i < MAX+1; i++) // finds the total number of values in the counts array
  {
    size += counts[i];
  }
  return size;
}

size_t Histogram::min() const
{
  size_t min = 0;
  bool minFound = false;
  for(int i = 0; i < MAX+1; i++) // looks through entire counts array to find the smallest value
  {
    if(counts[i] > 0 && minFound == false) // checks current index's value to find out if it is smaller than the current smallest value
    {
      min = i; // if smaller it becomes the new min
      minFound = true;
    }
  }
  return min;
}

size_t Histogram::max() const
{
  size_t maxOfHisto = 0;
  for(int i = 1; i < MAX+1; i++) // looks through entire counts array to find the largest value
  {
    if(counts[i] > 0) // checks current index's value to find out if it is larger than the current largest value
    {
      maxOfHisto = i; // if larger it becomes the new max
    }
  }
  return maxOfHisto;
}

size_t Histogram::mode() const
{
  size_t maxOfHisto = counts[0];
  size_t mode = 0;
  for(int i = 1; i < MAX+1; i++) // looks through the entire array to find the largest value and it's index which is then stored in mode and returned at the end of the function
  {
    if(counts[i] > maxOfHisto)
    {
      maxOfHisto = counts[i];
      mode = i;
    }
  }
  return mode;
}

size_t Histogram::median() const
{
  size_t sortedCounts[size()]; // making a partially filled array to store the values from the input file in order from least to greatest
  int size = 0;
  for(int i = 0; i < MAX+1; i++) // looks through counts array and adds the values to sortedCounts accordingly
  {
    for(int j = 0; j < counts[i]; j++)
    {
      sortedCounts[size] = i;
      size++;
    }
  }
  int medianIndex = size/2; // gets the middle index of the array to find the median's index
  if(size % 2 > 0) // checks if size is an odd number and sets the index of the median accordingly
  {
    medianIndex = (size/2) + 1;
  }
  return sortedCounts[medianIndex - 1]; // since the indexs start from 0 and not 1 there is a -1 after the medianIndex get the right index
}

double Histogram::mean() const
{
  if(size() == 0) // checks if mean is called by an empty Histogram and then outputs 0 to avoid errors
  {
    return 0;
  }
  double total = 0;
  for(int i = 0; i < MAX + 1; i++) // looks through array and adds the value at every index to the total variable
  {
    total += counts[i] * i;
  }
  return total/size(); // devides the total by the number of indexs which is size
}

double Histogram::variance() const
{
  if(size() == 0) // checks if variance is called by an empty Histogram and then outputs 0 to avoid errors
  {
    return 0;
  }
  double meanOfCounts = mean();
  double totalSqrDiff = 0;
  for(int i = 0; i < MAX + 1; i++) // looks through the entire array to add up all of the difference between the value at every index and the mean
  {
    for(int j = 0; j < counts[i]; j++) // checks how many instances of a number there are and adds to the totalSqrDiff accordingly
    {
      totalSqrDiff += (i - meanOfCounts)*(i - meanOfCounts);
    }
  }
  return totalSqrDiff/size(); // devides the total squared difference of the numbers by the size to get the variance
}

void Histogram::operator +=(const Histogram& rhs)
{
  for(int i = 0; i < MAX + 1; i++)
  {
    counts[i] += rhs.counts[i]; // adds the number of occurrences of every number from the rhs Histogram to the Histogram calling the += function
  }
}

size_t Histogram::operator [](size_t val) const
{
  return counts[val]; // returns the number of times the number "val" has occured
}

ostream& operator <<(ostream& out, const Histogram& h)
{
  for(int i = h.min(); i <= h.max(); i++) // sets up the histogram to only print the numbers between the min and the max of the histogram object passed in as an argument
  {
    out << i << ": ";
    for(int j = 0; j < h[i]; j++) // checks how many *s the number needs and prints accordingly
    {
      out << "*";
    }
    if(i != h.max()) // prevents an extra \n from being printed at the end of the histogram
    {
      out << endl;
    }
  }
  return out;
}
