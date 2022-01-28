// Node interface for CSCI 60 Homework 8; due Sunday 2/28/21
// Sara Krehbiel, modified code from Natalie Linnell and Nicholas Tran

#ifndef NODE_H
#define NODE_H
#include <iostream>

// class definition for a node representing one element in a linked list
class node {
public:
  typedef int value_type; // value_type is an alias for int in the node class

  // constructor
  node(const value_type & = value_type(), node * = nullptr);

  // accessors
  value_type data() const { return data_; }
  node * link() const { return link_; }

  // mutators
  void set_data(const value_type & newdata) { data_ = newdata; }
  void set_link(node * newlink) { link_ = newlink; }

private:
  value_type data_;
  node * link_;
};

// overloaded operator for testing
std::ostream& operator <<(std::ostream& out, const node * head);

// declarations for HW8 functions
int f1(int n);
void f2(int a[], int first, int last);
void f3(node * & head_ptr);
void f4(node*& head, node*& tail);

#endif // NODE_H
