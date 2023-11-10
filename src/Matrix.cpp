#include "../headers/Matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int rows, int cols)
    : rows(rows)
    , cols(cols)
    , data(rows, std::vector<int>(cols, 0))
{
}

Matrix Matrix::operator*(const Matrix& right) const
{
  if (cols != right.rows)
  {
    throw std::invalid_argument("Wrong matrix size");
  }

  Matrix result = Matrix(rows, right.cols);

  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < right.cols; column++)
    {
      for (int el = 0; el < cols; el++)
      {
        result.data[row][column] += data[row][el] * right.data[el][column];
      }
    }
  }

  return result;
}

Matrix Matrix::operator*(double number) const
{
  Matrix result = Matrix(rows, cols);
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < cols; column++)
    {
      result.data[row][column] = number * data[row][column];
    }
  }
  return result;
}