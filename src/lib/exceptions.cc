#include "exceptions.h"

#include <string>

S21MatrixException::S21ExceptionType S21MatrixException::get_type() const {
  return type;
}

std::string S21MatrixException::get_message() const { return message; }
S21MatrixException::S21MatrixException(S21ExceptionType type,
                                       const std::string msg)
    : type(type), message(msg) {
  switch (type) {
    case S21ExceptionType::MatrixDimensionsAreNotEqual:
      message = message + "Matrix dimensions are not equal";
      break;
    case S21ExceptionType::MatrixColsAndOtherRowsAreNotEqual:
      message = message + "Matrix cols and Other rows are not equal";
      break;
    case S21ExceptionType::DeterminantIsZero:
      message = message + "Determinant is 0";
      break;
    case S21ExceptionType::TryingToSetZeroRows:
      message = message + "Failed to set rows: trying to set rows to 0";
      break;
    case S21ExceptionType::TryingToSetZeroCols:
      message = message + "Failed to set cols: trying to set cols to 0";
      break;
    case S21ExceptionType::MatrixIsNotReadyToWork:
      message = message +
                "Matrix is not ready for work, rows or cols are equal "
                "to 0. Or matrix_ == nullptr";
      break;
    case S21ExceptionType::InvalidMatrixIndexes:
      message = message + "Indexes of matrix are out of range";
      break;
    case S21ExceptionType::RowOrColIsZeroOrLess:
      message =
          message +
          "Trying to get value by indexes, but ROW or COLUMN is less than 0";
      break;
    case S21ExceptionType::FailedToConstructor:
      message = message +
                "Failed in Costructor: rows or cols are less or equal to zero";
      break;
  }
}
