#include <iostream>

class S21Matrix {
private:
  int _rows, _cols;
  double **_p;

public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  ~S21Matrix();

  int rows() const;
  int cols() const;
  double &operator()(int row, int col);
  const int &operator()(int row, int col) const;

  void Print() const;
  const double *const *data() const;
};
