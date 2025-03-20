#include "matrix.h"

S21Matrix::S21Matrix() {
  _rows = 3;
  _cols = 3;
  _p = new double *[_rows];
  for (int i = 0; i < _rows; ++i) {
    _p[i] = new double[_cols];
  }
}

S21Matrix::S21Matrix(int rows, int cols) {
  std::cout << "Constructor: " << rows << ", " << cols << "\n";
  _rows = rows;
  _cols = cols;
  _p = new double *[_rows];
  for (int i = 0; i < _rows; ++i) {
    _p[i] = new double[_cols];
  }
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  std::cout << "Copy Constructor: other " << other.rows() << other.cols()
            << "\n";
  _rows = other.rows();
  _cols = other.cols();
  _p = new double *[_rows];
  for (int i = 0; i < _rows; ++i) {
    _p[i] = new double[_cols];
    for (int j = 0; j < _cols; ++j) {
      _p[i][j] = other._p[i][j];
    }
  }
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  std::cout << "Copy assignment operator: other " << other.rows()
            << other.cols() << "\n";
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < _rows; ++i) {
    delete[] _p[i];
  }
  delete[] _p;

  _rows = other.rows();
  _cols = other.cols();
  _p = new double *[_rows];
  for (int i = 0; i < _rows; ++i) {
    _p[i] = new double[_cols];
    for (int j = 0; j < _cols; ++j) {
      _p[i][j] = other.data()[i][j];
    }
  }
  return *this;
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  std::cout << "Move Constructor" << other.rows() << other.cols() << "\n";
  _rows = other.rows();
  _cols = other.cols();
  _p = other.assigned_data();
  other.set_rows(0);
  other.set_cols(0);
  other.set_data_null();
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  std::cout << "Move assignment operator" << other.rows() << other.cols()
            << "\n";
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < _rows; ++i) {
    delete[] _p[i];
  }
  delete[] _p;
  _rows = other.rows();
  _cols = other.cols();
  _p = other.assigned_data();

  other.set_rows(0);
  other.set_cols(0);
  other.set_data_null();
  return *this;
}

S21Matrix::~S21Matrix() {
  std::cout << "Desctructor" << _rows << _cols << "\n";
  for (int i = 0; i < _rows; ++i) {
    delete[] _p[i];
  }
  delete[] _p;
}
