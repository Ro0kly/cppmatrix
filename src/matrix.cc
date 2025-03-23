#include "matrix.h"
#include <iostream>
#include <ostream>

void S21Matrix::Print() const {
  for (int i = 0; i < rows(); ++i) {
    for (int j = 0; j < cols(); ++j) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << "\n";
  }
}

void S21Matrix::FillWith(double value) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = value;
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  bool flag = true;
  if (rows_ != other.rows() || cols_ != other.cols()) {
    flag = false;
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (matrix_[i][j] != other.data()[i][j]) {
        flag = false;
        break;
      }
    }
  }
  return flag;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows() || cols_ != other.cols()) {
    throw S21MatrixError("SumMatrix: matrix dimensions are not equal");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.data()[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows() || cols_ != other.cols()) {
    throw S21MatrixError("SubMatrix: matrix dimensions are not equal");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.data()[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows()) {
    throw S21MatrixError("MulMatrix: matrix cols and other rows are not equal");
  }
  S21Matrix res(rows_, other.cols());
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols(); ++j) {
      for (int k = 0; k < cols_; ++k) {
        res(i, j) += matrix_[i][k] * other.data()[k][j];
      }
    }
  }
  (*this) = res;
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < res.rows(); ++i) {
    for (int j = 0; j < res.cols(); ++j) {
      res(i, j) = matrix_[j][i];
    }
  }
  return res;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw S21MatrixError("Determinant: matrix rows and cols are not equal");
  }
  return det_rec(*this);
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw S21MatrixError("CalcComplements: matrix rows and cols are not equal");
  }
  S21Matrix res(rows_, cols_);
  for (int i = 0; i < res.rows(); ++i) {
    for (int j = 0; j < res.cols(); ++j) {
      S21Matrix temp = get_minor_matrix(i, j);
      res(i, j) = ((i + j) % 2 == 0 ? 1 : -1) * det_rec(temp);
    }
  }
  return res;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != cols_) {
    throw S21MatrixError("InverseMatrix: matrix rows and cols are not equal");
  }
  double det = (*this).Determinant();
  if (det == 0) {
    throw S21MatrixError(
        "Inverse Matrix: determinant is 0 so there is no inverse matrix");
  }
  S21Matrix mat = (*this).CalcComplements().Transpose();
  S21Matrix mat_inverse(mat.rows(), mat.cols());
  for (int i = 0; i < mat_inverse.rows(); ++i) {
    for (int j = 0; j < mat_inverse.cols(); ++j) {
      mat_inverse(i, j) = mat(i, j) / det;
    }
  }
  return mat_inverse;
}
