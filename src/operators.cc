#include "matrix.h"
#include <iostream>
#include <ostream>

double &S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_) {
    throw S21MatrixException(
        S21MatrixException::S21ExceptionType::InvalidMatrixIndexes,
        "Operator ()");
  }
  if (row < 0 || col < 0) {
    throw S21MatrixException(
        S21MatrixException::S21ExceptionType::RowOrColIsZeroOrLess,
        "Operator ()");
  }
  return matrix_[row][col];
}
const double &S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_) {
    throw S21MatrixException(
        S21MatrixException::S21ExceptionType::InvalidMatrixIndexes,
        "Operator ()");
  }
  if (row < 0 || col < 0) {
    throw S21MatrixException(
        S21MatrixException::S21ExceptionType::RowOrColIsZeroOrLess,
        "Operator ()");
  }
  return matrix_[row][col];
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  if (rows_ != other.rows() || cols_ != other.cols()) {
    throw S21MatrixException(
        S21MatrixException::S21ExceptionType::MatrixDimensionsAreNotEqual,
        "Operator +=");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.data()[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  if (rows_ != other.rows() || cols_ != other.cols()) {
    throw S21MatrixException(
        S21MatrixException::S21ExceptionType::MatrixDimensionsAreNotEqual,
        "Operator -=");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.data()[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix res(*this);
  res.MulNumber(num);
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
