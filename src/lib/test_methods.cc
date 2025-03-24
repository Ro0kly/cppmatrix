#include "s21_matrix_oop.h"

void S21Matrix::fillMatrix3x3ForTestOnly() {
  matrix_[0][0] = 5;
  matrix_[0][1] = 3;
  matrix_[0][2] = 1;

  matrix_[1][0] = 4;
  matrix_[1][1] = 3;
  matrix_[1][2] = 2;

  matrix_[2][0] = 5;
  matrix_[2][1] = 2;
  matrix_[2][2] = 1;
}

void S21Matrix::fillMatrix5x5ForTestOnly() {
  matrix_[0][0] = 5;
  matrix_[0][1] = 3;
  matrix_[0][2] = 1;
  matrix_[0][3] = 1;
  matrix_[0][4] = 1;

  matrix_[1][0] = 4;
  matrix_[1][1] = 3;
  matrix_[1][2] = 2;
  matrix_[1][3] = 3;
  matrix_[1][4] = 3;

  matrix_[2][0] = 5;
  matrix_[2][1] = 2;
  matrix_[2][2] = 1;
  matrix_[2][3] = 4;
  matrix_[2][4] = 4;

  matrix_[3][0] = 1;
  matrix_[3][1] = 2;
  matrix_[3][2] = 1;
  matrix_[3][3] = 2;
  matrix_[3][4] = 1;

  matrix_[4][0] = 3;
  matrix_[4][1] = 3;
  matrix_[4][2] = 4;
  matrix_[4][3] = 3;
  matrix_[4][4] = 3;
}
