#include "matrix.h"
#include <iostream>
#include <ostream>

int main() {
  S21Matrix mat1(2, 3);
  S21Matrix mat2(3, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(0, 2) = 3;
  mat1(1, 0) = 4;
  mat1(1, 1) = 5;
  mat1(1, 2) = 6;

  mat2(0, 0) = 7;
  mat2(0, 1) = 8;
  mat2(1, 0) = 9;
  mat2(1, 1) = 10;
  mat2(2, 0) = 11;
  mat2(2, 1) = 12;

  mat1 *= mat2;
  mat1.Print();
  return 0;
}
