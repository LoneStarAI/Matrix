/* 
author: De Wang
desc: mini matrix lib
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
  typedef vector<vector<T> > Mat;
  size_t rows;
  size_t cols;
  Mat M;
  vector<string> fields;

public:
  // Constructors & destructors
  matrix(size_t _rows, size_t _cols, const T& elements);
  matrix(const matrix<T>& cp);
  matrix(const string csv, const T& fill=0.0); // initialize from a csv file
  ~matrix();
  
  // getter
  size_t get_rows() const;
  size_t get_cols() const;

  // operator overload
  matrix<T>& operator=(const matrix<T>& cp); 
  T& operator()(const size_t& _row, const size_t& _col);

  // utility methods 
  void print();
  bool rangeCheck(const size_t& _row, const size_t& _col) const;

  // math functions
  vector<T> sumOfAllCols();
  vector<T> sumOfAllRows();
};

#endif /*MATRIX_H*/
