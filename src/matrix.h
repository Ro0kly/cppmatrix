#include <iostream>
class S21MatrixError : public std::runtime_error {
public:
  S21MatrixError(const std::string &message)
      : std::runtime_error("Matrix Error: " + message) {}
};
class S21Matrix {
private:
  int _rows, _cols;
  double **_p;
  double **assigned_data() const;

public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;
  S21Matrix &operator=(S21Matrix &&other) noexcept;
  ~S21Matrix();

  int rows() const;
  int cols() const;
  const double *const *data() const;
  S21Matrix &set_rows(int rows);
  S21Matrix &set_cols(int cols);
  S21Matrix &set_data_null();

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
  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
};
