#include <iostream>
#include "automobile.h"

class Pickup : public Automobile{
public:
  Pickup() : Automobile(), secondStall(-1), haulingCap(0), extendedCab(false) {}
  Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, double ihaulingCap, bool iextendedCab) : Automobile(imake, imodel, iyear, iprice, istall){
    secondStall = istall + 1;
    haulingCap = ihaulingCap;
    extendedCab = iextendedCab;
  }
  int getSecondStall() const { return secondStall; }
  double getHaulingCap() const { return haulingCap; }
  bool isExtendedCab() const { return extendedCab; }
  bool park(bool lot[], int size);
private:
  int secondStall;
  double haulingCap;
  bool extendedCab;
};

bool Pickup::park(bool lot[], int size){
  int spot=size;
  for(int i=0; i<size-1; i++){
    if(!lot[i] && !lot[i + 1])
    spot = i;
  }
  if(spot>=size)
  return false;
  else{
    lot[spot] = true;
    lot[spot + 1] = true;
    set_stall(spot);
    secondStall = spot + 1;
    return true;
  }
}

class Van : public Automobile{
public:
  Van() : Automobile(), numSeats(0), secondStall(-1) {}
  Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int numSeats) : Automobile(imake, imodel, iyear, iprice, istall), numSeats(numSeats){
    secondStall = numSeats>7 ? istall + 1 : -1;
  }
  int getSecondStall() const { return secondStall; }
  bool park(bool lot[], int size);
  int getNumSeats(){return numSeats;}
private:
  int numSeats;
  int secondStall;
};

bool Van::park(bool lot[], int size){
  bool answer;
  if(secondStall > -1){
    int spot=size;
    for(int i=0; i<size-1; i++){
      if(!lot[i] && !lot[i + 1])
      spot = i;
    }
    if(spot>=size)
    answer = false;
    else{
      lot[spot] = true;
      lot[spot + 1] = true;
      set_stall(spot);
      secondStall = spot + 1;
      answer = true;
    }
  }
  else{
    answer = Automobile::park(lot, size);
  }
  return answer;
}

int main(){
  // Part 1
  bool lot[10] = {true, true, false, true, false, false, true, true, false, false};
  Automobile car1;
  car1.park(lot, 10);
  std::cout << car1.stall()<<std::endl;

  // Part 2

  bool lot2[10] = {true, true, false, false, false, false, true, true, false, true};
  Pickup car2;
  car2.park(lot2, 10);
  std::cout << car2.stall() << ", " << car2.getSecondStall() << std::endl;
  std::cout << "haulingCap = " << car2.getHaulingCap() << ", extendedCab = " << car2.isExtendedCab()<<std::endl;
  Pickup coolCar("Fiat", "the cool one", 2077, 10000000, 0, 20.1, true);
  std::cout << "haulingCap = " << coolCar.getHaulingCap() << ", extendedCab = " << coolCar.isExtendedCab()<<std::endl;
  std::cout << coolCar.park(lot2, 10) << std::endl;
  std::cout << coolCar.stall() << ", " << coolCar.getSecondStall() << std::endl;
  std::cout << coolCar.park(lot2, 10) << std::endl;

  // Part 3

  bool lot3[10] = {true, true, false, false, false, false, true, true, false, true};
  Van carA;
  Van carB("Lambo", "m100", 2023, 0.01, 0, 8);
  for(int i = 0; i < 10; i++){
    std::cout<<lot3[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
  carA.park(lot3, 10);
  for(int i = 0; i < 10; i++){
    std::cout<<lot3[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
  carB.park(lot3, 10);
  for(int i = 0; i < 10; i++){
    std::cout<<lot3[i]<<" ";
  }
  return 0;
}
