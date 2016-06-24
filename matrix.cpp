#include <iostream>
#include <vector>
#include "matrix.h"

template<typename T>
matrix<T>::matrix(size_t _rows, size_t _cols, const T& elements) {
  M.resize(_rows);
  for (size_t i = 0; i < _rows; i++) {
    M[i].resize(_cols, elements);
  }
  rows = _rows;
  cols = _cols;
}

template<typename T>
matrix<T>::~matrix() {
  cout<<"object destructed"<<endl;
}

template<typename T>
size_t matrix<T>::get_rows() const {
  return rows;
}

template<typename T>
size_t matrix<T>::get_cols() const {
  return cols;
}

template<typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& cp) {
  if (this == &cp)
    return *this;
  
  size_t n_rows = cp.get_rows();
  size_t n_cols = cp.get_cols();

  M.resize(n_rows);
  for (size_t i = 0; i < n_rows; i++) {
    M[i].resize(cp.get_cols());
  }

  for (size_t i = 0; i < n_rows; i++) {
    for (size_t j = 0; j < n_cols; j++) {
      //M[i][j] = cp(i, j);
      M[i][j] = cp[i][j];
    }
  }

  rows = n_rows;
  cols = n_cols;
  return *this;
}

int main() {
  cout<<"hello world"<<endl;
  matrix<double> m(2, 3, 0.0);
  return 0;
}
