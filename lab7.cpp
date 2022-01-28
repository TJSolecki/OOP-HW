#include <iostream> //Rohm Stark & Thomas Solecki
#include <vector>
using namespace std;

// Part A Question 1
// 1.The salary at time 0 is 50k
// 2. Sn-1 * 1.1 + 5
int salary(int n){
  if(n == 0) return 50;
  return salary(n-1) * 1.1 + 5;
}

// Part A Question 2
// 1. if a[1] >= a[0]
// 2. you could use an "and" statement and call a[n-1] >= a[n-2] along with the function (if n is the number of elements)

bool isSorted(int a[], int n){
  if(n == 2) return (a[1] >= a[0]);
  return ((a[n-1] >= a[n-2]) && isSorted(a, n-1));
}


struct Folder{
    string name;
    string files[100];
    int nfiles;
    Folder* folders;
    int nfolders;

};

  void print(Folder f){
    static int n = 0;
      cout<<f.name<<endl;
      for(int i = 0; i<f.nfiles; i++){
        for(int j = 0; j < n + 1; j++){
          cout << "  ";
        }
          cout<<f.files[i]<<endl;
      }
      n++;
      for(int j = 0; j< f.nfolders; j++){
          cout << endl;
          for(int i = 0; i < n; i++){
            cout << "  ";
          }
          print(f.folders[j]);
      }
      n--;
  }

int water(int n)
{
  if(n == 0) return 10;
  return water(n-1) / 2 + 1;
}

int main(){
  cout << salary(2) << "k\n";
  int a[] = {1,2,3,4};
  cout << isSorted(a, 4) << endl;
  a[2] = 5;
  cout << isSorted(a, 4) << endl;

  Folder fs0[0]={};
  Folder f9 = {"NewFolder", {"test.txt"}, 1, fs0, 0};
  Folder fs1[1] = {f9};

  Folder f1 = {"Folder1", {"hw1.txt", "hw2.txt", "hw3.txt"}, 3, fs0, 0};
  Folder f2 = {"Folder2", {"dummy.txt", "nascar.txt"}, 2, fs1, 1};
  Folder fs[2] = {f1, f2};
  Folder f3 = {"Folder3", {"test1.txt", "test2.txt", "test3.txt", "test4.txt"},4, fs,2};
  print(f3);

  cout << water(1) << " gallons" << endl;

  return 0;
}
