// Implementation starter file for CSCI 60 Homework 3; due Sunday 1/24/21
// List any collaborators and write your name here
// Name: Thomas Solecki
// Description: The following program provides function definitions for the fucntions declarations that lack them in the lexicon header file.
// specifically this program defines functions related to modifications of lexicon objects, the creation of new lexicon objects, and boolean expressions for comparing lexicon objects.

#include "lexicon.h"

/* TODO: implement the other functions declared in lexicon.h here */

Lexicon::Lexicon(string filename)
{
  size_ = 0;
  ifstream input;
  input.open(filename);
  string temp;
  while(input >> temp && size_ < CAPACITY) // looks through file so long as the lexicon has not reached max size and there are still more words left
  {
    if(!contains(temp)) // checks if the lexicon already has the current word. If it doesn't then it is added and the size of the lexicon is increased by one
    {
      data_[size_] = temp;
      size_++;
    }
  }
  input.close();
}

bool Lexicon::contains(string word) const
{
  for(int i = 0; i < size_; i++) // looks through entire lexicon
  {
    if(data_[i].compare(word) == 0) // if the target word is equal to the current word the function returns true
    {
      return true;
    }
  }
  return false; // if the word was not found the fuction returns false
}

bool Lexicon::insert(string word)
{
  if(contains(word) || size_ == CAPACITY) // if the lexicon is full or the lexicon already has the target word the function returns false
  {
    return false;
  }
  data_[size_] = word; // adds the word to the end of the lexicon's data_ array
  size_++;
  return true;
}

bool Lexicon::remove(string word)
{
  bool found = false;
  for(int i = 0; i < size_; i++) // looks through entire lexicon
  {
    if(word.compare(data_[i]) == 0 && found == false) // if the word has not been found and the current word is the target word the for loop inside removes the current word
    {
      for(int j = i; j < size_; j++) // removes current word and shifts the rest of the words down one index
      {
        data_[j] = data_[j + 1];
      }
      size_--;
      found = true;
    }
  }
  return found;
}

Lexicon Lexicon::operator |(const Lexicon& rhs) const
{
  Lexicon result;
  for(int i = 0; i < size_; i++) // adds all of the lhs's lexicon to the lexicon result
  {
    result.insert(data_[i]);
  }
  for(int i = 0; i < rhs.size_; i++) // looks through rhs lexicon and adds all of the words not already in result
  {
    if(!result.contains(rhs.data_[i]) && result.size_ < CAPACITY) // checks to make sure the result does not have the current word and also checks to make sure that the size of result does not exceed capacity
    {
      result.insert(rhs.data_[i]);
    }
  }
  return result;
}

Lexicon Lexicon::operator &(const Lexicon& rhs) const
{
  Lexicon result;
  for(size_t i = 0; i < size_; i++) // goes through lhs lexicon and checks if each word is in rhs lexicon
  {
    if(rhs.contains(data_[i])) // if the current word is in rhs then it adds it to result
    {
      result.insert(data_[i]);
    }
  }
  return result;
}

Lexicon Lexicon::operator ^(const Lexicon& rhs) const
{
  Lexicon result;
  for(int i = 0; i < size_; i++) // goes through lhs's lexicon
  {
    if(!rhs.contains(data_[i])) // if the current word is not in rhs's lexicon it is added to the lexicon that is returned by the function
    {
      result.insert(data_[i]);
    }
  }
  for(int i = 0; i < rhs.size_; i++) // goes through rhs's lexicon
  {
    if(!contains(rhs.data_[i]) && result.size_ < CAPACITY) // if the current word is not in lhs's lexicon it is added to the lexicon that is returned by the function
    {
      result.insert(rhs.data_[i]);
    }
  }
  return result;
}

bool operator ==(const Lexicon& lhs, const Lexicon& rhs)
{
  if(lhs.size() != rhs.size()) // if the sizes of rhs and lhs are different then the function returns false
  {
    return false;
  }
  for(int i = 0; i < lhs.size(); i++) // looks through lhs
  {
    if(!rhs.contains(lhs[i])) // if the current word is not in rhs then the program returns false
    {
      return false;
    }
  }
  return true;
}

bool operator !=(const Lexicon& lhs, const Lexicon& rhs)
{
  return !(lhs == rhs); // checks if the contents of rhs and lhs are identical. If not it returns true. If they are it returns false.
}

bool operator <=(const Lexicon& lhs, const Lexicon& rhs)
{
  for(size_t i = 0; i < lhs.size(); i++) // looks through all of the lhs lexicon
  {
    if(!rhs.contains(lhs[i])) // checks if rhs has the current word in lhs. If not it returns false. If it does it continues the for loop and goes to the next word.
    {
      return false;
    }
  }
  return true; // returns true if rhs contins all of lhs's words
}

bool operator <(const Lexicon& lhs, const Lexicon& rhs)
{
  if(lhs == rhs) // if lhs and rhs are equal the function returns false
  {
    return false;
  }
  for(int i = 0; i < lhs.size(); i++) // looks through lhs
  {
    if(!rhs.contains(lhs[i])) // if the current word is not in rhs then the program returns false
    {
      return false;
    }
  }
  return true;
}

bool operator >=(const Lexicon& lhs, const Lexicon& rhs)
{
  for(size_t i = 0; i < rhs.size(); i++) // looks through rhs
  {
    if(!lhs.contains(rhs[i])) // if lhs doesn't contain an element in rhs then the function returns false
    {
      return false;
    }
  }
  return true;
}

bool operator >(const Lexicon& lhs, const Lexicon& rhs)
{
  if(lhs == rhs) // if lhs and rhs are equal the function returns false
  {
    return false;
  }
  for(size_t i = 0; i < rhs.size(); i++) // looks through rhs
  {
    if(!lhs.contains(rhs[i])) // if lhs does not contain the current word in rhs then the function returns false
    {
      return false;
    }
  }
  return true;
}

// Inserts contents of lex in out in order, separated by spaces
ostream& operator <<(ostream& out, const Lexicon & lex) {
  size_t n = lex.size();
  for (size_t i=0; i<n; i++) {
    out << lex[i] << " ";
  }
  return out;
}
