#include "matrix.h"

void S21Matrix::Print() const {
  for (int i = 0; i < rows(); ++i) {
    for (int j = 0; j < cols(); ++j) {
      std::cout << _p[i][j] << " ";
    }
    std::cout << "\n";
  }
}

void S21Matrix::FillWith(double value) {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      _p[i][j] = value;
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  bool flag = true;
  if (_rows != other.rows() || _cols != other.cols()) {
    flag = false;
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      if (_p[i][j] != other.data()[i][j]) {
        flag = false;
        break;
      }
    }
  }
  return flag;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (_rows != other.rows() || _cols != other.cols()) {
    throw S21MatrixError("SumMatrix: matrix dimensions are not equal");
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      _p[i][j] += other.data()[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (_rows != other.rows() || _cols != other.cols()) {
    throw S21MatrixError("SubMatrix: matrix dimensions are not equal");
  }
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      _p[i][j] -= other.data()[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      _p[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (_cols != other.rows()) {
    throw S21MatrixError("MulMatrix: matrix cols and other rows are not equal");
  }
  S21Matrix res(_rows, other.cols());
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < other.cols(); ++j) {
      for (int k = 0; k < _cols; ++k) {
        res(i, j) += _p[i][k] * other.data()[k][j];
      }
    }
  }
  (*this) = res;
}
