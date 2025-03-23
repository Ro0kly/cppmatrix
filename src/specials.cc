#include "matrix.h"

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw S21MatrixException(
        S21MatrixException::S21ExceptionType::FailedToConstructor,
        "Matrix Constructor");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.rows();
  cols_ = other.cols();
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this == &other) {
    return *this;
  }
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  rows_ = other.rows();
  cols_ = other.cols();
  matrix_ = new double *[rows_];
  if (rows_ != 0 && cols_ != 0 && matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_];
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] = other.data()[i][j];
      }
    }
  }
  return *this;
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows();
  cols_ = other.cols();
  matrix_ = other.assigned_data();
  other.set_rows(0);
  other.set_cols(0);
  other.set_data_null();
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  if (this == &other) {
    return *this;
  }
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  rows_ = other.rows();
  cols_ = other.cols();
  matrix_ = other.assigned_data();

  other.set_rows(0);
  other.set_cols(0);
  other.set_data_null();
  return *this;
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}
