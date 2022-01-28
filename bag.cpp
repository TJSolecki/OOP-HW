// Partial static array implementation of Bag.
// Sara Krehbiel, 1/13/21 (W Week 2, file 3/3)

#include "bag.h"

// initialize size_=0 to construct an empty bag
Bag::Bag() {
  size_ = 0;
}

// return the number of contents in the bag
size_t Bag::size() const {
  return size_;
}

// add an element to the bag
void Bag::insert(int target) { // suppose data_={5,6,?,?,...}, size_=2, target=9
  data_[size_] = target;       // update  data_={5,6,9,?,...}
  size_++;                     // and     size_=3
}

// overload subscript operator [] to return a position-indexed entry in the bag
int Bag::operator [](size_t pos) const {
  return data_[pos]; // use [] for arrays in defining how it works for a bag
}

size_t Bag::erase(int target)
{
  int k = 0;
  for(int i = 0; i < size_; i++)
  {
    if(data_[i] == target)
    {
      k++;
      erase_one(data_[i]);
      i--;
    }
  }
  return k;
}

bool Bag::erase_one(int target)
{
  bool found = false;
  for(int i = 0; i < Bag::size_ ; i++)
  {
    if(data_[i] == target && found == false)
    {
      for(int j = i; j < size_; j++)
      {
        data_[j] = data_[j+1];
      }
      size_--;
      i--;
      found = true;
    }
  }
  return found;
}

// overload insertion operator << to insert bag contents into an ostream
ostream& operator <<(ostream& out, const Bag& b) {
  for (size_t i=0; i<b.size(); i++) {
    out << b[i]; // use << for numbers/strings in defining it for a whole bag
    out << " ";
  }
  return out;
}
