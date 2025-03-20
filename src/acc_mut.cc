#include "matrix.h"

int S21Matrix::rows() const { return _rows; }
int S21Matrix::cols() const { return _cols; }
const double *const *S21Matrix::data() const { return _p; }
double **S21Matrix::assigned_data() const { return _p; }

S21Matrix &S21Matrix::set_rows(int rows) {
  _rows = rows;
  return *this;
}
S21Matrix &S21Matrix::set_cols(int cols) {
  _cols = cols;
  return *this;
}
S21Matrix &S21Matrix::set_data_null() {
  _p = nullptr;
  return *this;
}
