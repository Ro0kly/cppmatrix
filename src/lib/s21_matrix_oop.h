#include <exception>
#include <iostream>
#include <string>

#include "exceptions.h"

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;
  double **assigned_data() const;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  S21Matrix &operator=(S21Matrix &&other);
  ~S21Matrix();

  int rows() const;
  int cols() const;
  const double *const *data() const;

  double &operator()(int row, int col);
  const double &operator()(int row, int col) const;
  bool operator==(const S21Matrix &other) const;
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix operator*(const double num) const;
  S21Matrix &operator*=(const double num);
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix &operator*=(const S21Matrix &other);

  void Print() const;
  void FillWith(double value);
  S21Matrix Transpose() const;
  double Determinant() const;
  S21Matrix CalcComplements() const;
  S21Matrix InverseMatrix() const;

  // TEST FUNCTIONS ONLY
  void fillMatrix3x3ForTestOnly();
  void fillMatrix5x5ForTestOnly();

 private:
  void is_ready_for_work() const;
  double det_rec(const S21Matrix &mat) const;
  S21Matrix get_minor_matrix(int excludeR, int excludeC) const;
  S21Matrix &set_rows(int rows);
  S21Matrix &set_cols(int cols);
  S21Matrix &set_data_null();
  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
};
