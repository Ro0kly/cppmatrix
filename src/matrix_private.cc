#include "matrix.h"

double S21Matrix::det_rec(const S21Matrix &mat) const {
  if (mat.rows() == 1) {
    return mat.data()[0][0];
  }
  if (mat.rows() == 2) {
    return mat.data()[0][0] * mat.data()[1][1] -
           mat.data()[0][1] * mat.data()[1][0];
  }
  int side = mat.rows();

  double det = 0;
  for (int j = 0; j < side; ++j) {
    S21Matrix temp(side - 1, side - 1);
    int r = 0;
    for (int i = 1; i < side; ++i) {
      int c = 0;
      for (int k = 0; k < side; ++k) {
        if (k == j)
          continue;
        temp(r, c) = mat(i, k);
        c++;
      }
      r++;
    }
    int cofactor = (j % 2 == 0 ? 1 : -1) * mat(0, j) * det_rec(temp);
    det += cofactor;
  }
  return det;
}

double S21Matrix::Determinant() const {
  if (_rows != _cols) {
    throw S21MatrixError("Determinant: matrix rows and cols are not equal");
  }
  return det_rec(*this);
}
