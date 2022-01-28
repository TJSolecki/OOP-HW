#include <iostream>
#include "NDim.h"
using namespace std;

// this fucntion only works when the type for T1 is overloaded to use the == operator and the type for T2 can store numerical values such as size_t and int.
// a[] and find must also be the same type
template<typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find)
{
  int count = 0;
  for(size_t i = 0; i < size; i++)
  {
    if(find == a[i])
    {
      count++;
    }
  }
  return count;
}

// this fucntion only works when the type for T1 is overloaded to use the <= operator as well as the >= operator and the type for T2 can store numerical values such as size_t and int.
// a[], low, and high must all be the same type
template<typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high)
{
  int count = 0;
  for(size_t i = 0; i < size; i++)
  {
    if(low <= a[i] && high >= a[i])
    {
      count++;
    }
  }
  return count;
}

int main()
{
  // Part A
  int intArr[] = {6,2,3,2,6,2};
  string stringArr[] = {"this" ,"is", "a", "test", "test"};
  string find1 = "test", find2 = "this";
  cout << "intArr contains " << count_exact(intArr, 6, 2) << " 2s.\n";
  cout << "stringArr contains " << count_exact(stringArr, 5, find1) << " \"test\"s\n";
  cout << "there are " << count_range(intArr, 6, 2, 4) << " numbers in intArr between 2 and 4 (inclusive)\n";
  cout << "there are " << count_range(stringArr, 5, find1, find2) << " strings in stringArr between \"test\" and \"this\"\n";

  // Part B
  int arr[4] = {1,2,3,4};
  NDim<int> sizeGal(4, arr);
  for(int i = 0; i < sizeGal.size(); i++){
    cout << sizeGal.get(i) << " ";
  }
  cout << endl;
  NDim<int> sizeBoi(5);
  sizeBoi = sizeGal;
  for(int i = 0; i < sizeBoi.size(); i++){
    cout << sizeBoi.get(i) << " ";
  }




  return 0;

}
