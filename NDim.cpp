#include "NDim.h"

template<typename T>
NDim<T> NDim<T>::operator =(NDim<T> rhs){
  numDemi = rhs.numDemi;
  for(int n = 0; n < numDemi; n++){
    point[n] = rhs.point[n];
  }
  return rhs;
}
