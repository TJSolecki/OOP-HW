
#include "lbiguint.h"
#include <cstdlib>
#include <string>
#include <iostream>

node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}

lbiguint::~lbiguint(){
  node *curr = head, *prev = nullptr;
  while(curr != nullptr){
    prev = curr;
    curr = curr->link();
    delete prev;
  }
  head = nullptr;
  tail = nullptr;
}

lbiguint::lbiguint(){
    head = tail = new node();
  }

lbiguint::lbiguint (const std::string & s) {
  if (s.size() == 0)
    return;
  head = tail = new node(std::stoi(s.substr(s.size()-1, 1)), nullptr);
  for (int i = s.size()-2; i >=0; i--){
    head = new node(std::stoi(s.substr(i, 1)), head);
  }
}


std::size_t lbiguint::size() const {
  std::size_t count = 0;
  node *curr = head;
  for (; curr != nullptr; curr = curr->link()) count++;
  return count;
}

int lbiguint::operator [](std::size_t pos) const{
  if(pos > size() - 1 || pos < 0) return 0; // checks to see if you referenced out of bounds
  node *curr = head;
  for(int i = 0; i < pos; i++){
    curr = curr->link();
  }
  return curr->data();
}


std::ostream& operator <<(std::ostream& out, const lbiguint& obj)
{
  for(int i = 0; i < obj.size(); i++) std::cout << obj[i];
  std::cout << std::endl;
  return out;
}

void lbiguint::operator =(const lbiguint & rhs)
{
  node *curr = head, *prev = nullptr;
  while(curr != nullptr)
  {
    prev = curr;
    curr = curr->link();
    delete prev;
  }
  head = nullptr;
  tail = nullptr;
  if(rhs.size() != 0)
  {
    head = tail = new node(rhs[rhs.size()-1], nullptr);
    for(int n = rhs.size()-2; n >= 0; n--)
    {
      head = new node(rhs[n], head);
    }
  }
}

void lbiguint::operator +=(const lbiguint & rhs)
{
  int carry = 0;
  int next = 0;
  int thisSize = (*this).size();
  int rhsSize = rhs.size();
  int bigSize = thisSize > rhsSize ? thisSize : rhsSize;
  node *headT = nullptr, *tailT = nullptr;
  for(int j = 0; j < bigSize + 1; j++)
  {
    node *thisCurr = head, *rhsCurr = rhs.head;
    if(j >= thisSize) thisCurr = new node(0, nullptr);
    for(int i = 0; i < thisSize - j - 1; i++)
    {
      thisCurr = thisCurr->link();
    }
    if(j >= rhsSize) rhsCurr = new node(0, nullptr);
    for(int i = 0; i < rhsSize - j - 1; i++)
    {
      rhsCurr = rhsCurr->link();
    }
    next = carry + thisCurr->data() + rhsCurr->data();
    if(j == 0) headT = tailT = new node(next%10, nullptr);
    else headT = new node(next%10, headT);
    carry = next/10;
    if(j > thisSize) delete thisCurr;
    if(j > rhsSize) delete rhsCurr;
  }
  node *curr = head, *prev = nullptr;
  while(curr != nullptr)
  {
    prev = curr;
    curr = curr->link();
    delete prev;
  }
  if(headT->data() == 0 && headT->link() != nullptr)
  {
    head = headT->link();
    tail = tailT;
    delete headT;
  }
  else
  {
    head = headT;
    tail = tailT;
  }
}

lbiguint operator +(lbiguint lhs, lbiguint rhs){
  std::string total = "";
  std::cout << "ding" << std::endl;
  int lhsSize = lhs.size(), rhsSize = rhs.size();
  int next = 0;
  int carry = 0;
  int i = 0;

  for(; i < (lhsSize > rhsSize? rhsSize : lhsSize); i++){
    next = lhs[lhsSize - 1 - i] + rhs[rhsSize - 1 - i] + carry;
    carry = next/10;
    total = std::to_string(next%10)+total;
  }
  for(; i < (lhsSize < rhsSize? rhsSize:lhsSize); i++){
    next = (lhsSize < rhsSize?rhs[rhsSize - 1 - i]:lhs[lhsSize - 1 - i])+carry;
    carry = next/10;
    total = std::to_string(next%10) + total;
  }
  lbiguint rVal(total);
  std::cout << "ding" << std::endl;
  return rVal;
}


int node::data() const
{
    return data_;
}

node * node::link()
{
    return link_;
}


//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function doesn't change anything - On a const node*, you can only call const functions
{
    return link_;
}

void node::set_data(const int & newdata)
{
    data_ = newdata;
}

void node::set_link(node * newlink)
{
    link_ = newlink;
}

bool operator > (const lbiguint &a, const lbiguint &b){
  int aSize = a.size(), bSize = b.size();
  if(aSize == bSize){
    for(int n = 0; n < aSize; n++){
      if(a[n] > b[n]){return true;}
      if(a[n] < b[n]){return false;}
    }
    return false;
  }
  return aSize > bSize;
}
bool operator < (const lbiguint &a, const lbiguint &b){
  int aSize = a.size(), bSize = b.size();
  if(aSize == bSize){
    for(int n = 0; n < aSize; n++){
      if(a[n] < b[n]){return true;}
      if(a[n] > b[n]){return false;}
    }
    return false;
  }
  return aSize < bSize;
}
bool operator <= (const lbiguint &a, const lbiguint &b){
  int aSize = a.size(), bSize = b.size();
  if(aSize == bSize){
    for(int n = 0; n < aSize; n++){
      if(a[n] < b[n]){return true;}
      if(a[n] > b[n]){return false;}
    }
    return true;
  }
  return aSize < bSize;
}
bool operator >= (const lbiguint &a, const lbiguint &b){
  int aSize = a.size(), bSize = b.size();
  if(aSize == bSize){
    for(int n = 0; n < aSize; n++){
      if(a[n] > b[n]){return true;}
      if(a[n] < b[n]){return false;}
    }
    return true;
  }
  return aSize > bSize;
}
bool operator == (const lbiguint &a, const lbiguint &b){
  if(a.size() != b.size()) return false;
  for(int c = 0; c < a.size(); c++){
    if(a[c]!=b[c]){
      return false;
    }
  }
  return true;
}
bool operator != (const lbiguint &a, const lbiguint &b){
  if(a.size() != b.size()) return true;
  for(int c = 0; c < a.size(); c++){
    if(a[c]!=b[c]){
      return true;
    }
  }
  return false;
}
