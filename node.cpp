// Implementation file for CSCI 60 Homework 8; due Sunday 2/28/21
// Write your name and list collaborators here
// Name: Thomas Solecki
// Description: This program defines 4 sperate functions. The first returns the nth value in a sequence. The second reverses the order of elements in an array.
// The third deletes all of the data in a linked list. The fourth reverses a linked list.

#include "node.h"

// 2-arg node constructor
node::node(const value_type& data, node * link) : data_(data), link_(link) {}

// overloaded << for debugging

std::ostream& operator <<(std::ostream& out, const node * head) {
  if (head==nullptr) return out; // base case: empty list
  out << head->data() << " "; // non-recursively output the data of the head
  return (out << head->link()); // recursively output everything else
}


// HW8 function implementations

// pre: n is an int >= 2
// post: retuns a_n for the n entered where a_n = a_n-2 + n-1
int f1(int n)
{
  if(n == 0 || n == 1) return 1; // checks for the base case
  return f1(n-2) + (n - 1);
}

// pre: a[] is an array of ints, first is an int containing an index in the array that is before "last", last is an int containing an index in the array that is after "start"
// post: the array that was passed in has had its order of ints reversed within the defined boundries of first and last
void f2(int a[], int first, int last)
{
  if(first > last) return; // checks to see if the array's order has fully been reversed
  // swaps the values of the end of the list with the start
  int temp = a[first];
  a[first] = a[last];
  a[last] = temp;
  // calls the fucntion again and swaps the next two inner values in the array
  f2(a, first + 1, last - 1 );

}

// pre: head_ptr is a pointer to a node object that is the "head" of a linked list
// post: the entire linked list that the pointer passed in is attched to is deleted
void f3(node *& head_ptr)
{
  if(head_ptr == nullptr) return; // checks to see if the fucntion has reached the end of the linked list and terminates the fucntion if yes
  node * temp = head_ptr->link(); // stores a pointer to the next item in the linked list so that it is not lost when the current node is deleted
  delete head_ptr;
  head_ptr = nullptr;
  f3(temp); // calls the function again to delete the next item in the list or terminate if the list has ended
}

// pre: a pointer to a node that represents the "head" of a linked list is passed into head and a pointer to a node that represents the "tail" of the same linked list is passed into tail
// post: the linked list whose head and tail were passed in has been reversed
void f4(node *& head, node *& tail)
{
  if(head == tail) return; // checks if the list only has one or no elements and then terminates the function as lists less than 2 items long cannot be reversed
  int count = 0;
  node *curr = head;
  while(curr != nullptr) // this while loop is used to count the number of items in the linked list
  {
    count++;
    curr = curr->link();
  }
  node *temp = nullptr, *next = nullptr;
  while(count > 1) // this loop changes the links in nodes in the linked list to point to the item before them instead of the one after them
  {
    next = head;
    for(int i = count; i > 2; i--)
    {
      next = next->link();
    }
    next->link()->set_link(next);
    count--;
  }
  // here the head and tail pointers are switched as the list has been reversed so the head is now the tail and vice versa
  temp = head;
  head = tail;
  tail = temp;
  tail->set_link(nullptr); // the tail is updated to have a nullptr
}
