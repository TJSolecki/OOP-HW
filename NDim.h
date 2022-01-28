#ifndef NDIM_H
#define NDIM_H

template<typename T>
class NDim{
public:
  NDim() : numDemi(0) {};
  NDim(int numDemi) : numDemi(numDemi) {};
  NDim(int size, T newArr[]){
    numDemi = size;
    for(int i = 0; i < numDemi; i++) point[i] = newArr[i];
}

  int size(){return numDemi;}
  T get(int index) { return index < numDemi ? point[index] : 0; }
  void operator =(NDim rhs);
private:
  T point[10];
  int numDemi;
};

// For this function to work the type needs to be overloaded to use the = operator
template<typename T>
void NDim<T>::operator =(NDim<T> rhs){
  numDemi = rhs.numDemi;
  for(int n = 0; n < numDemi; n++){
    point[n] = rhs.point[n];
  }
}

#endif
