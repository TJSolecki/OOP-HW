// Starter file for CSCI 60 Homework 7, Program 1; due Sunday 2/21/21
// Write your analysis, write your name, and list any collaborators here
// Name: Thomas Solecki
// Description: This program is used for testing the speed at which different algorithms parse and sort through a file.
// 1. I predict that the algorithm that will run the fastest will be algorithm 3. I say this because it uses a set rather than a vector and we learned in class that
// sets search logarithmically rather than linearly like vectors do. It will also be the fastest to code because sets automatically sort themselves so I won't have to do that myself.
// They also don't allow duplicates so I don't have to check for those as well.
// 4. I was correct in my assumption that the third algorithm would be the fastest but I was extremely surprised at just how slow the first algorithm was. It took 71 seconds to process
// whereas the first algorithm only took 0.3 seconds and the second took 0.4 seconds. I had anticipated it being the slowest but not that slow.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <chrono>

using namespace std;
using namespace std::chrono; // for timing

// constants that don't matter if you run by command line
const int ALG = 1; // should be 1,2,3
const string IN = "quickbrownfox.txt"; // test input
const string OUT = "output.txt"; // output goes wherever you want

// each of these fns should print to outfile the sorted distinct words in infile
void setThenSort(string infile, string outfile);
void sortThenSet(string infile, string outfile);
void allSet(string infile, string outfile);

// runs specified experiment on the specified filename and reports the time
void timedExperiment(int algorithm, string infile, string outfile) {
  auto start = high_resolution_clock::now(); // start time
  switch (algorithm) { // run one of the algorithms
    case 1: setThenSort(infile,outfile); break;
    case 2: sortThenSet(infile,outfile); break;
    case 3: allSet(infile,outfile); break;
    default: cout << "Invalid alg # specified\n"; return;
  }
  auto stop = high_resolution_clock::now(); // stop time
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count()/1000000.0 << " seconds for alg " << algorithm <<
    " to process " << infile << endl; // cout results
}

// run experiment either based on args or constants
int main(int argc, char** argv) {
  if (argc>3) timedExperiment(stoi(argv[1]),argv[2],argv[3]);
  else timedExperiment(ALG,IN,OUT);
  return 0;
}

void setThenSort(string infile, string outfile) {
  vector<string> words;
  string temp;
  ifstream input(infile);
  bool contains;
  while(input >> temp)
  {
    contains = false;

    for(size_t i = 0; i < words.size(); i++)
    {
      if(words[i] == temp)
      {
        contains = true;
      }
    }

    if(!contains)
    {
      words.push_back(temp);
    }
  }
  input.close();
  sort(words.begin(), words.end());
  ofstream output(outfile);
  for(size_t i = 0; i < words.size(); i++)
  {
    output << words[i] << endl;
  }
  output.close();
}

void sortThenSet(string infile, string outfile) {
  vector<string> words;
  string temp;
  ifstream input(infile);
  while(input >> temp)
  {
      words.push_back(temp);
  }
  input.close();
  sort(words.begin(), words.end());
  ofstream output(outfile);
  vector<string> usedWords;
  output << words[0] << endl;
  for(size_t i = 1; i < words.size(); i++)
  {
    if(words[i] != words[i-1])
    {
      output << words[i] << endl;
    }
  }
  output.close();
}

void allSet(string infile, string outfile) {
  set<string> words;
  ifstream input(infile);
  string temp;
  while(input >> temp)
  {
    words.insert(temp);
  }
  ofstream output(outfile);
  for(auto it = words.begin(); it != words.end(); it++)
  {
    output << *it << endl;
  }
}
