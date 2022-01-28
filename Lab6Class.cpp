template<typename T>
class nDim{
public:
  nDim() : numDemi(0) {}
  nDim(size_t numDemi) : numDemi(numDemi) {}
  nDim(size_t size, T newArr[]);
  size_t size(){return numDemi;}
  T get(size_t index) { return index < numDemi ? point[index] : 0; }
  operator =(nDim rhs);
private:
  T point[10];
  size_t numDemi;
};

nDim::nDim(size_t size, T newArr[]){
  numDemi = size;
  for(size_t i = 0; i < numDemi; i++){
    point[i] = newArr[i];
  }
}

nDim::operator =(nDim rhs){
  numDemi = rhs.numDemi;
  for(size_t n = 0; n < numDemi; n++){
    point[n] = rhs.point[n];
  }
  for(numDemi)
}
