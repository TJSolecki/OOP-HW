#include <iostream>
using namespace std;

bool bsearch(int *arr, const size_t& start, const size_t& end, const int& val)
{
  int mid = (start + end) / 2;
  if(start == end) return false;
  if(val < arr[mid]) return bsearch(arr, start, mid, val);
  if(val > arr[mid]) return bsearch(arr, mid + 1, end, val);
  return true;
}

int main()
{
  int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
  int arr2[] = {1,2,3,4,5,6,7,8,9,10};
  cout << bsearch(arr, 0, 0, 3) << endl;
  cout << bsearch(arr, 0, 10, 9) << endl;
  return 0;
}
