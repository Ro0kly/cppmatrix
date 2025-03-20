#include "matrix.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <utility>
void use_matrix(S21Matrix mat) { std::cout << mat.rows() << std::endl; }
S21Matrix create() {
  S21Matrix m(2, 2);
  return m;
}
int main() {
  S21Matrix mat1(3, 3);
  S21Matrix mat2(4, 4);
  mat1 = mat2;
  return 0;
}
