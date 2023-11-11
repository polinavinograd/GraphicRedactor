#include "../headers/Matrix.hpp"
#include <stdexcept>
#include <vector>

Matrix::Matrix(int rows, int cols)
    : rows(rows)
    , cols(cols)
    , data(rows, std::vector<double>(cols, 0))
{
}

Matrix::Matrix(std::vector<std::vector<double>> matrix)
{
  if (matrix.size() > 0)
  {
    size_t prev_size = matrix[0].size();
    for (size_t row = 1; row < matrix.size(); row++)
    {
      if (matrix[row].size() != prev_size)
      {
        throw std::invalid_argument("Different sizes of rows");
      }
    }
    rows = matrix.size();
    cols = prev_size;
    data = matrix;
  }
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

Matrix Matrix::transpose()
{
  Matrix result = Matrix(cols, rows);
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      result.data[j][i] = data[i][j];
    }
  }
  return result;
}

std::vector<std::vector<double>> Matrix::getData()
{
  return data;
}