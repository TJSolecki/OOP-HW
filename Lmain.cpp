#include <iostream>
#include "lbiguint.h"
using namespace std;


int main(){

  string a = "1", b = "13", c = "9999";
  lbiguint nVal(c);
  lbiguint loser(a);
  lbiguint losa(b);
  cout<<loser;
  cout<<loser.size()<<endl<<endl;

  nVal += loser;
  cout<<nVal;

  lbiguint newVal = losa + nVal;
  cout<<newVal;

  return 0;
}
