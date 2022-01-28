// Starter file for CSCI 60 Homework 7, Program 2; due Sunday 2/21/21
// List any collaborators and write your name here
// Name: Thomas Solecki
// Description: This program is used to search a database of bank accounts provided by the user in a txt file. The user has to search the name of the person on file and provide a valid
// password in order to see the account's ssn and balance.

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

const string END = "-"; // input to signal that the user is done

struct BankAccount
{
  string name;
  string password;
  int ssn;
  double bal;
};

int main(int argc, char** argv) {
  if (argc<2) {
    cout << "Specify an input file\n";
    exit(1);
  }
  string infile = argv[1]; // the name of the file to read from
  ifstream input(infile);
  map<string,BankAccount> accounts;
  string name, password;
  int ssn;
  double bal;
  while(input >> name && input >> password && input >> ssn && input >> bal)
  {
    accounts.insert(pair<string, BankAccount>(name, {name, password, ssn, bal}));
  }
  input.close();
  cout << "Name: ";
  cin >> name;
  while(name != "-")
  {
    auto it = accounts.find(name);
    if(it == accounts.end())
    {
      cout << "No record for " << name << " in the database\n";
    }
    else
    {
      cout << "PW: ";
      cin >> password;
      if(password == accounts[name].password)
      {
        cout << "SSN: " << accounts[name].ssn << endl;
        cout << "Balance: " << accounts[name].bal << endl;
      }
      else
      {
        cout << "Incorrect password\n";
      }
    }
    cout << "Name: ";
    cin >> name;
  }
  cout << "Goodbye!";

  return 0;
}
