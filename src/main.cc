#include <gtest/gtest.h>

#include "lib/s21_matrix_oop.h"

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

TEST(S21Matrix, MoveAssignmentOperator) {
  S21Matrix mat1(3, 3);
  mat1.FillWith(4);
  S21Matrix mat2(3, 3);
  mat2 = std::move(mat1);
  EXPECT_EQ(mat1.data(), nullptr);
  EXPECT_EQ(mat2(0, 0), 4);
  EXPECT_NE(mat1.data(), mat2.data());
  EXPECT_NE(&mat1, &mat2);
}

TEST(S21Matrix, Destructor) {
  S21Matrix mat(3, 3);
  mat.~S21Matrix();
  EXPECT_EQ(mat.data(), nullptr);
}

TEST(S21Matrix, OperatorSumTrue) {
  S21Matrix mat1(3, 3);
  mat1.FillWith(4);
  S21Matrix mat2(3, 3);
  mat2.FillWith(5.5);
  S21Matrix mat3 = mat1 + mat2;
  EXPECT_EQ(mat3.rows(), 3);
  EXPECT_EQ(mat3.cols(), 3);
  EXPECT_EQ(mat3(0, 0), 9.5);
}

TEST(S21Matrix, OperatorSumFalse) {
  S21Matrix mat1(2, 2);
  mat1.FillWith(4);
  S21Matrix mat2(3, 3);
  mat2.FillWith(5.5);
  try {
    S21Matrix mat3 = mat1 + mat2;
    FAIL() << "Matrices must not be able to add up" << std::endl;
  } catch (const S21MatrixException &e) {
    EXPECT_EQ(
        e.get_type(),
        S21MatrixException::S21ExceptionType::MatrixDimensionsAreNotEqual);
  }
}

TEST(S21Matrix, OperatorPlusEq) {
  S21Matrix mat1(3, 3);
  mat1.FillWith(4);
  S21Matrix mat2(3, 3);
  mat2.FillWith(5.5);
  mat1 += mat2;
  EXPECT_EQ(mat1(0, 0), 9.5);
  EXPECT_EQ(mat2(0, 0), 5.5);
}

TEST(S21Matrix, OperatorSubTrue) {
  S21Matrix mat1(3, 3);
  mat1.FillWith(5);
  S21Matrix mat2(3, 3);
  mat2.FillWith(4.5);
  S21Matrix mat3 = mat1 - mat2;
  EXPECT_EQ(mat3.rows(), 3);
  EXPECT_EQ(mat3.cols(), 3);
  EXPECT_EQ(mat3(0, 0), 0.5);
}

TEST(S21Matrix, OperatorSubFalse) {
  S21Matrix mat1(2, 2);
  mat1.FillWith(5);
  S21Matrix mat2(3, 3);
  mat2.FillWith(4.5);
  try {
    S21Matrix mat3 = mat1 - mat2;
    FAIL() << "Matrices must not be able to add up" << std::endl;
  } catch (const S21MatrixException &e) {
    EXPECT_EQ(
        e.get_type(),
        S21MatrixException::S21ExceptionType::MatrixDimensionsAreNotEqual);
  }
}

TEST(S21Matrix, OperatorMinusEq) {
  S21Matrix mat1(3, 3);
  mat1.FillWith(5);
  S21Matrix mat2(3, 3);
  mat2.FillWith(4.5);
  mat1 -= mat2;
  EXPECT_EQ(mat1(0, 0), 0.5);
  EXPECT_EQ(mat2(0, 0), 4.5);
}

TEST(S21Matrix, OperatorMulNumber) {
  S21Matrix mat1(3, 3);
  mat1.FillWith(4);
  S21Matrix mat2 = mat1 * 4;
  EXPECT_EQ(mat2.rows(), 3);
  EXPECT_EQ(mat2.cols(), 3);
  EXPECT_EQ(mat2(0, 0), 16);
}

TEST(S21Matrix, OperatorMulEqNumber) {
  S21Matrix mat1(3, 3);
  mat1.FillWith(4);
  mat1 *= 4;
  EXPECT_EQ(mat1.rows(), 3);
  EXPECT_EQ(mat1.cols(), 3);
  EXPECT_EQ(mat1(0, 0), 16);
}

TEST(S21Matrix, OperatorMulMatrixTrue) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(0, 2) = 3;
  mat1(1, 0) = 4;
  mat1(1, 1) = 5;
  mat1(1, 2) = 6;
  S21Matrix mat2(3, 2);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(1, 0) = 3;
  mat2(1, 1) = 4;
  mat2(2, 0) = 5;
  mat2(2, 1) = 6;
  S21Matrix mat3(mat1.cols(), mat2.rows());
  mat3 = mat1 * mat2;
  EXPECT_EQ(mat3(0, 0), 22);
  EXPECT_EQ(mat3(0, 1), 28);
  EXPECT_EQ(mat3(1, 0), 49);
  EXPECT_EQ(mat3(1, 1), 64);
}

TEST(S21Matrix, OperatorMulMatrixFalse) {
  S21Matrix mat1(2, 4);
  S21Matrix mat2(3, 2);
  S21Matrix mat3(mat1.cols(), mat2.cols());
  try {
    mat3 = mat1 * mat2;
    FAIL() << "Matrix must not be multiplied because matrix1-cols are not "
              "equal to matrix2-rows";
  } catch (const S21MatrixException &e) {
    EXPECT_EQ(e.get_type(), S21MatrixException::S21ExceptionType::
                                MatrixColsAndOtherRowsAreNotEqual);
  }
}

TEST(S21Matrix, OperatorMulEqMatrix) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(0, 2) = 3;
  mat1(1, 0) = 4;
  mat1(1, 1) = 5;
  mat1(1, 2) = 6;
  S21Matrix mat2(3, 2);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(1, 0) = 3;
  mat2(1, 1) = 4;
  mat2(2, 0) = 5;
  mat2(2, 1) = 6;
  mat1 *= mat2;
  EXPECT_EQ(mat1(0, 0), 22);
  EXPECT_EQ(mat1(0, 1), 28);
  EXPECT_EQ(mat1(1, 0), 49);
  EXPECT_EQ(mat1(1, 1), 64);
}

TEST(S21Matrix, OperatorEqMatrixTrue) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(0, 2) = 3;
  mat1(1, 0) = 4;
  mat1(1, 1) = 5;
  mat1(1, 2) = 6;
  S21Matrix mat2(2, 3);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(0, 2) = 3;
  mat2(1, 0) = 4;
  mat2(1, 1) = 5;
  mat2(1, 2) = 6;
  EXPECT_EQ(mat1 == mat2, true);
}

TEST(S21Matrix, OperatorEqMatrixFalse) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(0, 2) = 3;
  mat1(1, 0) = 4;
  mat1(1, 1) = 5;
  mat1(1, 2) = 6;
  S21Matrix mat2(2, 3);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(0, 2) = 3;
  mat2(1, 0) = 6;
  mat2(1, 1) = 5;
  mat2(1, 2) = 6;
  EXPECT_EQ(mat1 == mat2, false);
}

TEST(S21Matrix, Transpose) {
  S21Matrix mat1(2, 3);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(0, 2) = 3;
  mat1(1, 0) = 4;
  mat1(1, 1) = 5;
  mat1(1, 2) = 6;
  S21Matrix mat2 = mat1.Transpose();
  EXPECT_EQ(mat2(0, 0), 1);
  EXPECT_EQ(mat2(0, 1), 4);
  EXPECT_EQ(mat2(1, 0), 2);
  EXPECT_EQ(mat2(1, 1), 5);
  EXPECT_EQ(mat2(2, 0), 3);
  EXPECT_EQ(mat2(2, 1), 6);
}

TEST(S21Matrix, DeterminantOfMatrix3x3) {
  S21Matrix mat(5, 5);
  mat.fillMatrix5x5ForTestOnly();
  double d = mat.Determinant();
  EXPECT_EQ(d, -32);
}

TEST(S21Matrix, CalcComplements) {
  S21Matrix mat(3, 3);
  mat.fillMatrix3x3ForTestOnly();
  S21Matrix mat2(3, 3);
  mat2 = mat.CalcComplements();
  EXPECT_EQ(mat2(0, 0), -1);
  EXPECT_EQ(mat2(0, 1), 6);
  EXPECT_EQ(mat2(0, 2), -7);
  EXPECT_EQ(mat2(1, 0), -1);
  EXPECT_EQ(mat2(1, 1), 0);
  EXPECT_EQ(mat2(1, 2), 5);
  EXPECT_EQ(mat2(2, 0), 3);
  EXPECT_EQ(mat2(2, 1), -6);
  EXPECT_EQ(mat2(2, 2), 3);
}

TEST(S21Matrix, InverseMatrix) {
  S21Matrix mat(3, 3);
  mat.fillMatrix3x3ForTestOnly();
  S21Matrix mat2(3, 3);
  mat2 = mat.InverseMatrix();
  EXPECT_EQ(mat2(0, 2), 0.5);
  EXPECT_EQ(mat2(1, 0), 1);
  EXPECT_EQ(mat2(2, 2), 0.5);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
