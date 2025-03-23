#include <exception>
#include <string>
class S21MatrixException : public std::exception {

public:
  enum class S21ExceptionType {
    MatrixDimensionsAreNotEqual,
    MatrixColsAndOtherRowsAreNotEqual,
    DeterminantIsZero,
    TryingToSetZeroRows,
    TryingToSetZeroCols,
    MatrixIsNotReadyToWork,
    InvalidMatrixIndexes,
    RowOrColIsZeroOrLess,
    FailedToConstructor
  };
  explicit S21MatrixException(S21ExceptionType type,
                              const std::string msg = "");
  std::string get_message() const;
  S21ExceptionType get_type() const;

private:
  S21ExceptionType type;
  std::string message;
};
