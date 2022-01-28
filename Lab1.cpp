#include <iostream> //Rohm Stark, Thomas Solecki
using namespace std;

struct Time{//military time, no am/pm
int hour;
int minute;
};
Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}

struct Carpool{
  string names[5];
  int numPeople;
  Time arrive;
};

Carpool combineCarpool(Carpool carpoolA, Carpool carpoolB){
  /*The plan for this function is to have an if statement that determines
  whether or not the number of passangers exceeeds 5 and if it does it
  will return a carpool with 0 people and if the sum is 5 or less it returns
  a combined Carpool object.
  */
  Carpool newCarpool; // The new carpool that will be return as the new combined group
  if(carpoolA.numPeople + carpoolB.numPeople > 5) //if the total is over 5
  {
    newCarpool.numPeople = 0;
    return newCarpool; //null carpool returned
  }
  else
  {
    newCarpool.numPeople = carpoolA.numPeople + carpoolB.numPeople; //totals up people
    for(int a = 0; a < 5; a++){ // adds the names of the first group
      newCarpool.names[a] = carpoolA.names[a];
    }
    for(int a = 0; a < 5 - carpoolA.numPeople; a++){ //adds the names of the second group
      newCarpool.names[a+carpoolA.numPeople] = carpoolB.names[a];
    }
    newCarpool.arrive = earlier(carpoolA.arrive, carpoolB.arrive); //sets the time of the newCarpool to the earlier time
    return newCarpool;//returns it
  }
}
int main()
{
  Carpool one = {{"joe", "bob"}, 2, {1, 30}};
  Carpool two = {{"jenny", "kenny"}, 2, {2, 45}};
  Carpool result = combineCarpool(one, two);
  cout << result.numPeople << " " << result.arrive.hour << ":" << result.arrive.minute << endl;
  for(int a = 0; a < 5; a++){
    cout<<result.names[a]<<" ";
  }
  return 0;
}
