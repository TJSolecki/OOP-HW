#include <iostream>
using namespace std;

int testo(int *a, int *b) const
{
  a = new int(10);
  b = new int(20);
  *a = 30;
  *b = 40;
  cout << a << ", b = " << b << endl;
  return *a + *b;
}

int main()
{
  int *aPtr = new int(4);
  int  *bPtr = new int(5);
  testo(aPtr, bPtr);
  return 0;
}
