#include "matrix.h"
#include <iostream>
#include <ostream>

double &S21Matrix::operator()(int row, int col) {
  if (row >= _rows || col >= _cols) {
    throw S21MatrixError("Indexes of matrix are out of range");
  }
  return _p[row][col];
}
const double &S21Matrix::operator()(int row, int col) const {
  return _p[row][col];
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  std::cout << "Operator +: Go into" << std::endl;
  S21Matrix res(*this);
  res.SumMatrix(other);
  std::cout << "Operator +: Ready to return" << std::endl;
  return res;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  if (_rows != other.rows() || _cols != other.cols()) {
    throw S21MatrixError("SumMatrix: matrix dimensions are not equal");
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      _p[i][j] += other.data()[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  std::cout << "Operator -: Go into" << std::endl;
  S21Matrix res(*this);
  res.SubMatrix(other);
  std::cout << "Operator -: Ready to return" << std::endl;
  return res;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  if (_rows != other.rows() || _cols != other.cols()) {
    throw S21MatrixError("SubMatrix: matrix dimensions are not equal");
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      _p[i][j] -= other.data()[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator*(const double num) const {
  std::cout << "Operator *: Go into" << std::endl;
  S21Matrix res(*this);
  res.MulNumber(num);
  std::cout << "Operator *: Ready to return" << std::endl;
  return res;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      _p[i][j] *= num;
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  (*this).MulMatrix(other);
  return *this;
}
