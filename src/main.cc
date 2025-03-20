#include "matrix.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <utility>
S21Matrix create() {
  S21Matrix m(4, 4);
  return m;
}

int main() {
  S21Matrix mat1 = create();
  return 0;
}
