#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <iostream>
#include <vector>
#include "matrix.h"

template<typename T>
matrix<T>::matrix(size_t _rows, size_t _cols, const T& elements) {
  this->M.resize(_rows);
  for (size_t i = 0; i < _rows; i++) {
    this->M[i].resize(_cols, elements);
  }
  this->rows = _rows;
  this->cols = _cols;
}

template<typename T>
matrix<T>::matrix(const matrix<T>& cp) {
  this->M = cp.M;
  this->rows = cp.rows;
  this->cols = cp.cols;
}

template<typename T>
matrix<T>::~matrix() {
}

template<typename T>
size_t matrix<T>::get_rows() const {
  return this->rows;
}

template<typename T>
size_t matrix<T>::get_cols() const {
  return this->cols;
}

template<typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& cp) {
  this->M = cp.M;
  this->rows = cp.rows;
  this->cols = cp.cols;
  return *this;
}

template<typename T>
const T& matrix<T>::operator()(const size_t& _row, const size_t& _col) const{
  return this->M[_row][_col];
}

template<typename T>
vector<T> matrix<T>::sumOfAllCols() {
  vector<T> res(rows, 0.0);
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      res[i] += this->M[i][j];
      //res[i] += (*this)(i,j);
    }
  }
  return res;
}

template<typename T>
void matrix<T>::print() const {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      cout<<this->M[i][j]<<' ';
    }
    cout<<endl;
  } 
}

int main() {
  matrix<double> m(2, 3, 1.0);
  m.print();
  vector<double> res = m.sumOfAllCols();
  for (vector<double>::iterator it = res.begin(); it != res.end(); it++) {
    cout<< *it << ' ';
  }

  matrix<double> m1(0, 0, 0.0);  // corner case
  m1.print();
  vector<double> res1 = m1.sumOfAllCols();
  for (vector<double>::iterator it = res1.begin(); it != res1.end(); it++) {
    cout<< *it << ' ';
  }

  matrix<double> cp(m);
  matrix<double> cp1 = m;
  return 0;
}

#endif  /*MATRIX_CPP*/
