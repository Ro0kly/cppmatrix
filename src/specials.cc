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
  std::cout << "Constructor: " << rows << ", " << cols << "\n";
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  std::cout << "Copy Constructor: other " << other.rows() << other.cols()
            << "\n";
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
  std::cout << "Copy assignment operator: other " << other.rows()
            << other.cols() << "\n";
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  rows_ = other.rows();
  cols_ = other.cols();
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.data()[i][j];
    }
  }
  return *this;
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  std::cout << "Move Constructor" << other.rows() << other.cols() << "\n";
  rows_ = other.rows();
  cols_ = other.cols();
  matrix_ = other.assigned_data();
  other.setrows_(0);
  other.setcols_(0);
  other.set_data_null();
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  std::cout << "Move assignment operator" << other.rows() << other.cols()
            << "\n";
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = other.rows();
  cols_ = other.cols();
  matrix_ = other.assigned_data();

  other.setrows_(0);
  other.setcols_(0);
  other.set_data_null();
  return *this;
}

S21Matrix::~S21Matrix() {
  std::cout << "Desctructor" << rows_ << cols_ << "\n";
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}
