#include "matrix.h"
S21Matrix::S21Matrix() {
  _rows = 3;
  _cols = 3;
  _p = new double *[_rows];
  for (int i = 0; i < _rows; ++i) {
    _p[i] = new double[_cols];
  }
}
