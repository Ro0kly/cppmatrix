#include "matrix.h"
#include <iostream>
#include <ostream>

int main() {
  S21Matrix mat1(3, 3);
  S21Matrix mat2(4, 4);
  S21Matrix &ref1 = mat1;
  ref1 = mat2;
  return 0;
}
