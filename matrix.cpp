#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <fstream>
#include <sstream>
#include <stdexcept>
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
matrix<T>::matrix(const string csv, const T& fill) {
  // initialize the matrix from a CSV file
  cout << "initializing from csv file: " << csv << endl;
  ifstream in(csv);
  vector<T> row;
  string line, val;
  T data;

  // parse each element into matrix
  while (!in.eof()) {
    getline(in, line);
    istringstream iss(line);
    while (!iss.eof() && line.length() > 0) {
      getline(iss, val, ',');
      try {
        if (val.length() > 0 && val != " ") {
          data = (T)stof(val);
        } else {
          data = fill;
        }
      } catch (exception e) {
        cout << e.what() << ": Invalid input, only numerical values"
        " are allowed." << endl;
        throw e;
      }
      row.push_back(data);
    }

    if (row.size() > 0) {
      this->M.push_back(row);
      row.clear();
    }
  }
  
  // set rows and cols
  this->rows = M.size();
  if (M.size() > 0) {
    this->cols = M[0].size();
  } else {
    this->cols = 0;
  }
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
T& matrix<T>::operator()(const size_t& _row, const size_t& _col){
  rangeCheck(_row, _col);
  return this->M[_row][_col];
  // will do range check implicitly by using at
  //return (this->M).at(_row).at(_col);  
}

template<typename T>
vector<T> matrix<T>::sumOfAllCols() {  // calculate sum of columns
  vector<T> res(rows, 0.0);
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      res[i] += (*this)(i,j);
    }
  }
  return res;
}

template<typename T>
vector<T> matrix<T>::sumOfAllRows() {  // calculate sum of rows
  vector<T> res(cols, 0.0);
  for (size_t i = 0; i < cols; i++) {
    for (size_t j = 0; j < rows; j++) {
      res[i] += (*this)(j, i);
    }
  }
  return res;
}

template<typename T>
bool matrix<T>::rangeCheck(const size_t& _row, const size_t& _col) const {
  if (_row < 0 || _row >= rows) {
    cout << "row index must be in [0, " << rows << "]" << endl;
    throw out_of_range("Index OUT_OF_RANGE!");
  }
  if (_col < 0 || _col >= cols) {
    cout << "coloum index must be in [0, " << cols << "]" << endl;
    throw out_of_range("Index OUT_OF_RANGE!");
  }
  return true;
}

template<typename T>
void matrix<T>::print() {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      cout << (*this)(i, j) << "    ";
    }
    cout << endl;
  } 
}

int main() {
  matrix<double> m(3, 2, 0.0);
  size_t rows = m.get_rows();
  size_t cols = m.get_cols();

  matrix<double> cp(m);
  matrix<double> cp1 = m;

  // initialize matrix
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      m(i, j) = i * cols + j + 1.0;
    }
  }
  
  // initilize from a csv file
  matrix<double> m_csv("input.csv");
  cout << "matrix: " << endl;
  m_csv.print();

  // sum of cols
  vector<double> res = m_csv.sumOfAllCols();
  cout << "sum of cols: ";
  for (vector<double>::iterator it = res.begin();
       it != res.end(); it++) {
    cout << *it << ' ';
  }
  cout << endl;

  //sum of rows
  cout << "sum of rows: ";
  vector<double> res_rows = m_csv.sumOfAllRows();
  for (vector<double>::iterator it = res_rows.begin(); 
       it != res_rows.end(); it++) {
    cout << *it << ' ';
  }

  // corner case: 0 rows, 0 cols
  matrix<double> m1(0, 0, 0.0);  
  m1.print();
  vector<double> res1 = m1.sumOfAllCols();
  for (vector<double>::iterator it = res1.begin();
       it != res1.end(); it++) {
    cout << *it << ' ';
  }

  return 0;
}

#endif  /*MATRIX_CPP*/
