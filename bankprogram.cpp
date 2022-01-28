// Goals: Practice class design (6.2,7.1) & introduce operator overloading (8.1)
//        1. Warmup: Give inline definitions for getBalance, deposit, withdraw
//        2. Write driver program that asks user for an initial deposit amount,
//           declares bank account object, makes deposit, and prints acct info.
//        3. Define a constructor to specify name, ssn, accountNum
//        4. Define a default constructor using constructor delegation
//        5. Overload the += operator
// Sara Krehbiel, 1/8/21 (F Week 1, file 2/2)

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
  BankAccount(string name, int social, int actNum, double bal) : name(name), ssn(social), accountNum(actNum), balance(bal) {}
  BankAccount(string name, int social, int actNum) : name(name), ssn(social), accountNum(actNum) {}
  BankAccount() {}
  double getBalance() { return balance; }
  void deposit(double amt) { balance += amt; }
  void withdraw(double amt) { balance -= amt; }
  void printStatement(); // cout acct info (declared here, defined below)

  void operator +=(BankAccount& rhs)
  {
    balance += rhs.balance;
    rhs.balance = 0;
  }
private:
  string name = "NONE";
  int ssn = -1;
  int accountNum = -1;
  double balance = 0.0;
};

double setupAndGetAmount(); // declaration for a nonmember function

// driver program for BankAccount
int main() {

  BankAccount act1("Thomas", 123, 1, 100.0);
  BankAccount act2("Meg", 465, 2, 100.0);
  act1 += act2;
  act1.printStatement();
  act2.printStatement();

  return 0;
}

// format console numbers nicely and get a starting value from the user
double setupAndGetAmount() {
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "Enter a starting deposit amount: ";
  double amt;
  cin >> amt;
  cout << "Rounded: " << amt << "\n";
  return amt;
}

// defines BankAccount's print function, which outputs data to console
void BankAccount::printStatement() {
  cout << "STATEMENT FOR ACCOUNT " << accountNum << endl;
  cout << "Account holder: " << name << "\nSSN: " << ssn << endl;
  cout << "Balance: $" << balance << endl;
}
