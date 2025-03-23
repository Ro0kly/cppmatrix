#include "matrix.h"

S21Matrix S21Matrix::get_minor_matrix(int excludeR, int excludeC) const {
  if (excludeR < 0 || excludeR >= rows_ || excludeC < 0 || excludeC >= cols_) {
    throw S21MatrixError(
        "get_minor_matrix Error: excludeRow or excludeCol is out of range");
  }
  S21Matrix temp(rows_ - 1, cols_ - 1);
  int r = 0;
  for (int i = 0; i < rows_; ++i) {
    if (i == excludeR)
      continue;
    int c = 0;
    for (int j = 0; j < cols_; ++j) {
      if (j == excludeC)
        continue;
      temp(r, c) = matrix_[i][j];
      c++;
    }
    r++;
  }
  return temp;
}

double S21Matrix::det_rec(const S21Matrix &mat) const {
  // mat.Print();
  if (mat.rows() == 1) {
    return mat.data()[0][0];
  }
  if (mat.rows() == 2) {
    return mat.data()[0][0] * mat.data()[1][1] -
           mat.data()[0][1] * mat.data()[1][0];
  }
  double det = 0;
  for (int j = 0; j < mat.rows(); ++j) {
    S21Matrix temp = mat.get_minor_matrix(0, j);
    int c = (j % 2 == 0 ? 1 : -1) * mat(0, j) * det_rec(temp);
    det += c;
  }
  return det;
}
