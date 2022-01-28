#include "biguint.h"
#include <string>
#include <iostream>
/*
Q2: First initialize all fields to 0 to ensure they are all NULL.
Then run another for loop, starting from the last digit in the
string, converting it to an integer using the stoi method,
and placing it in the first slot, decrementing the
digit taken and incrementing the position in the array.

Q5: The += operator has one significant quality: because it
adds two numbers together the total can never be greater than
18. This makes the process of overloading simple as it
allows for us to add numbers simply. The way it will run is
by adding each individual digit in the array together. If
the total happens to be greater 9, it will subtract 10 from
that digit and add one to the next computation. If not it will
not add one to the next computation.
*/

using namespace std;

biguint::biguint(){
  for(int a = 0; a < CAPACITY; a++){
    data_[a] = 0;
  }
}

biguint::biguint(const string &b){//WHY WAS IT string &
  for(int a = 0; a < CAPACITY; a++){
    data_[a] = 0;
  }
  for(short a = b.length()-1; a >=0; a--){
    data_[b.length()-a-1] =  (short)stoi(b.substr(a,1));
  }
}

unsigned short biguint::operator [](size_t pos) const{
  if(pos > 19){return 0;}
  else{return data_[pos];}
}

ostream& operator <<(ostream& out, const biguint& b){
  for(int a = 19; a >= 0; a--){
    out<<b[a];
  }
}
void biguint::operator += (const biguint & b){
  short temp = 0;
  for(int i = 0; i < CAPACITY; i++){
    data_[i]+=b[i] + temp;
    if(data_[i] > 10){
      data_[i] -=10;
      temp = 1;
    }
    else{
      temp = 0;
    }
  }
}
