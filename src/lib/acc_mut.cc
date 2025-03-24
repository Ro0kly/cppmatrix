#include "s21_matrix_oop.h"

int S21Matrix::rows() const { return rows_; }
int S21Matrix::cols() const { return cols_; }
const double *const *S21Matrix::data() const { return matrix_; }
double **S21Matrix::assigned_data() const { return matrix_; }

S21Matrix &S21Matrix::set_rows(int rows) {
  rows_ = rows;
  return *this;
}
S21Matrix &S21Matrix::set_cols(int cols) {
  cols_ = cols;
  return *this;
}
S21Matrix &S21Matrix::set_data_null() {
  matrix_ = nullptr;
  return *this;
}
