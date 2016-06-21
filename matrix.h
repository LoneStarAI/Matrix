/* 
author: De Wang
desc: matrix library
*/
#ifndef MATRIX_H 
#define MATRIX_H 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class matrix {
private:
  typedef vector<T> Vec;
  typedef vector<vector<T> > Mat; // space before > > in case that the compiler takes it as ">>"
  size_t rows;
  size_t cols;
  Mat M;

public:
  // Constructor
  matrix(size_t _rows, size_t _cols, const T& elements);
  matrix(const matrix<T>& cp);
  matrix(string csv); // initialize from a csv file
  ~matrix();
  const T& operator()(const size_t& row, const size_t& col) const;
  matrix<T>& operator=(const matrix<T>& cp) {
  vector<T> sumOfAllCols();
  vector<T> sumOfAllRows();
  size_t get_rows() const {
    return rows;
  }
  size_t get_cols() const;
};

#endif /*MATRIX_H*/
