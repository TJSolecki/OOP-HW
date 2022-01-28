// Sample test file for CSCI 60 Homework 8; due Sunday 2/28/21
// Sara Krehbiel

#include <iostream>
#include "node.h"

using namespace std;

int main() {
  cout << "F1 test:\n";
  for (int i=0; i<10; i++) {
    cout << "a_" << i << "=" << f1(i) << endl;
  }

  cout << "\nQ2 test:\n";
  int a1[7] = {1,2,3,4,5,6,7};
  f2(a1,0,6);
  for (int i=0; i<7; cout << a1[i++] << " ") {}
  cout << endl;
  int a2[4] = {4, 7, 3, 12};
  f2(a2,0,3);
  for (int i=0; i<4; cout << a2[i++] << " ") {}
  cout << endl;

  cout << "\nUsing << overloaded for linked lists:\n";
  node *head=nullptr, *tail=nullptr;
  head = tail = new node(3,head); // construct last element on heap
  //cout << "tail = " << &*head << endl;
  head = new node(4,head); // construct penultimate element linking to last
  //cout << "head (4) = " << &*head << endl;
  head = new node(5,head);
  //cout << "head (5) = " << &*head << endl;
  head = new node(6,head); // construct first element linking to penultimate
  cout << "Initial list: " << &*head << endl;

  cout << "\nQ3 test:\n";
  f4(head,tail);
  cout << "After reversing: " << head << endl;

  cout << "\nQ3 test:\n";
  f3(head);
  cout << "After clearing: " << head << endl;

  return 0;
}
