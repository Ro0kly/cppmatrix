#include "matrix.h"
#include <iostream>
#include <ostream>

double &S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_) {
    throw S21MatrixError("Indexes of matrix are out of range");
  }
  return matrix_[row][col];
}
const double &S21Matrix::operator()(int row, int col) const {
  return matrix_[row][col];
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
  if (rows_ != other.rows() || cols_ != other.cols()) {
    throw S21MatrixError("SumMatrix: matrix dimensions are not equal");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.data()[i][j];
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
  if (rows_ != other.rows() || cols_ != other.cols()) {
    throw S21MatrixError("SubMatrix: matrix dimensions are not equal");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.data()[i][j];
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
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
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
