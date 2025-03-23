#include "matrix.h"
#include <iostream>
#include <ostream>

int main() {
  S21Matrix mat1(5, 5);
  // S21Matrix mat2(3, 2);
  mat1(0, 0) = 5;
  mat1(0, 1) = 3;
  mat1(0, 2) = 1;
  mat1(0, 3) = 1;
  mat1(0, 4) = 1;

  mat1(1, 0) = 4;
  mat1(1, 1) = 3;
  mat1(1, 2) = 2;
  mat1(1, 3) = 3;
  mat1(1, 4) = 3;

  mat1(2, 0) = 5;
  mat1(2, 1) = 2;
  mat1(2, 2) = 1;
  mat1(2, 3) = 4;
  mat1(2, 4) = 4;

  mat1(3, 0) = 1;
  mat1(3, 1) = 2;
  mat1(3, 2) = 1;
  mat1(3, 3) = 2;
  mat1(3, 4) = 1;

  mat1(4, 0) = 3;
  mat1(4, 1) = 3;
  mat1(4, 2) = 4;
  mat1(4, 3) = 3;
  mat1(4, 4) = 3;

  mat1.Print();
  std::cout << mat1.Determinant() << std::endl;

  // mat2(0, 0) = 7;
  // mat2(0, 1) = 8;
  // mat2(1, 0) = 9;
  // mat2(1, 1) = 10;
  // mat2(2, 0) = 11;
  // mat2(2, 1) = 12;

  // mat1.MulMatrix(mat2);

  // S21Matrix mat3(mat1.cols(), mat1.rows());
  // S21Matrix mat3 = mat1.Transpose();
  // mat3 = mat1.Transpose();
  // mat3.Print();
  return 0;
}
