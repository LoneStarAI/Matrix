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
  size_t get_rows() const;
  size_t get_cols() const;
  matrix<T>& operator=(const matrix<T>& cp); 
  const T& operator()(const size_t& _row, const size_t& _col) const;
  void print() const;

  vector<T> sumOfAllCols();
  vector<T> sumOfAllRows();
};

#endif /*MATRIX_H*/
