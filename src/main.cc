#include "matrix.h"
#include <cstddef>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <utility>

void fillMatrix5x5(S21Matrix &mat) {
  mat(0, 0) = 5;
  mat(0, 1) = 3;
  mat(0, 2) = 1;
  mat(0, 3) = 1;
  mat(0, 4) = 1;

  mat(1, 0) = 4;
  mat(1, 1) = 3;
  mat(1, 2) = 2;
  mat(1, 3) = 3;
  mat(1, 4) = 3;

  mat(2, 0) = 5;
  mat(2, 1) = 2;
  mat(2, 2) = 1;
  mat(2, 3) = 4;
  mat(2, 4) = 4;

  mat(3, 0) = 1;
  mat(3, 1) = 2;
  mat(3, 2) = 1;
  mat(3, 3) = 2;
  mat(3, 4) = 1;

  mat(4, 0) = 3;
  mat(4, 1) = 3;
  mat(4, 2) = 4;
  mat(4, 3) = 3;
  mat(4, 4) = 3;
}
TEST(S21Matrix, ConstructorDefault) {

  S21Matrix mat;
  EXPECT_EQ(mat.rows(), 3);
  EXPECT_EQ(mat.cols(), 3);
}

TEST(S21Matrix, ConstructorWithParams) {
  S21Matrix mat(5, 5);
  EXPECT_EQ(mat.rows(), 5);
  EXPECT_EQ(mat.cols(), 5);
}

TEST(S21Matrix, ConstructorWithZeroParams) {
  try {
    S21Matrix mat(0, 0);
    FAIL() << "Expected Matrix Exception";
  } catch (const S21MatrixException &e) {
    EXPECT_EQ(e.get_type(),
              S21MatrixException::S21ExceptionType::FailedToConstructor);
  }
}

TEST(S21Matrix, CopyConstructor) {
  S21Matrix mat1(3, 3);
  mat1.FillWith(4);
  S21Matrix mat2 = mat1;
  EXPECT_EQ(mat1(0, 0), mat2(0, 0));
  EXPECT_NE(mat1.data(), mat2.data());
  EXPECT_NE(&mat1, &mat2);
}

TEST(S21Matrix, CopyAssignmentOperator) {
  S21Matrix mat1(3, 3);
  S21Matrix mat2(3, 3);
  mat1.FillWith(4);
  mat2.FillWith(5);
  mat1 = mat2;
  EXPECT_EQ(mat1(0, 0), mat2(0, 0));
  EXPECT_NE(mat2.data(), nullptr);
  EXPECT_NE(mat1.data(), mat2.data());
  EXPECT_NE(&mat1, &mat2);
}

TEST(S21Matrix, MoveConstructor) {
  S21Matrix mat1(3, 3);
  mat1.FillWith(4);
  S21Matrix mat2 = std::move(mat1);
  EXPECT_EQ(mat1.data(), nullptr);
  EXPECT_EQ(mat2(0, 0), 4);
  EXPECT_NE(mat1.data(), mat2.data());
  EXPECT_NE(&mat1, &mat2);
}

// TEST(S21Matrix, MoveAssignmentOperator) {
//   S21Matrix mat1(3, 3);
//   S21Matrix mat2(3, 3);
//   mat1.FillWith(4);
//   mat2.FillWith(5);
//   mat2 = std::move(mat1);
//   EXPECT_EQ(mat2.data(), nullptr);
//   EXPECT_EQ(mat1(0, 0), 4);
//   EXPECT_NE(mat1.data(), mat2.data());
//   EXPECT_NE(&mat1, &mat2);
// }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
