#include <iostream>
#include <vector>
#include "matrix.h"

template<typename T>
matrix<T>::matrix(size_t _rows, size_t _cols, const T& elements) {
  M.resize(_rows);
  for (size_t i = 0; i < _rows; i++) {
    M[i].resize(_cols, elements);
  }
  this->rows = _rows;
  this->cols = _cols;
}

template<typename T>
matrix<T>::~matrix() {
  cout<<"object destructed"<<endl;
}

template<typename T>
size_t matrix<T>::get_rows() const {
  return this->rows;
}

template<typename T>
size_t matrix<T>::get_cols() const {
  return this->cols;
}

int main() {
  cout<<"hello world"<<endl;
  matrix<double> m(2, 3, 0.0);
  return 0;
}
