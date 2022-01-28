//Thomas Solecki and Rohm Stark

#include <iostream>
using namespace std;

class ModInt{
public:
  ModInt() : mod(0), numVal(0) {};
  ModInt(int mo, int num): mod(mo), numVal(num){};
  int getNumVal();
  int getModVal();
  void operator +=(ModInt rhs);
private:
  int mod; // 9%8 20%8 = 29%8 =
  int numVal;
};
int ModInt::getModVal(){
  return mod;
}
int ModInt::getNumVal(){
  return numVal;
}

void ModInt::operator +=(ModInt rhs){
  if(mod == rhs.getModVal()){
    numVal += rhs.getNumVal();
    numVal %= mod;
  }
  else{
    mod = -1;
    numVal = -1;
  }
}

ModInt operator +(ModInt lhs, ModInt rhs){ // to make this function function, the same as the += function while being a non-member function we change it from a void to a ModInt return type
                                          // and instead of applying the changes to the object that called the fucntion we instead create a new object and return that
  int mod;
  int val;
  if(lhs.getModVal() == rhs.getModVal()){

    mod = lhs.getModVal();
    val = (lhs.getNumVal()+rhs.getNumVal()) % mod;
  }
  else{
    mod = -1;
    val = -1;
  }
  ModInt newMod(mod, val);
  return newMod;
}

bool operator ==(ModInt lhs, ModInt rhs){
  if(lhs.getNumVal() == rhs.getNumVal() && lhs.getModVal() == rhs.getModVal()){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  ModInt one(1999, 33);
  ModInt two;
  ModInt three(1999, 1977);
  bool athing = one==two, bthing = one == one;
  cout<< athing<<endl<<bthing<<endl;

  ModInt NaN = one + two;
  cout<<NaN.getModVal()<<endl;

  one+=three;
  cout<<one.getNumVal();


  return 0;
}
