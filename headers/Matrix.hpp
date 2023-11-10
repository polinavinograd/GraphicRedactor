#pragma once

#include <vector>

class Matrix
{
  public:
  Matrix(int rows, int cols);
  Matrix operator*(const Matrix& right) const;
  Matrix operator*(double number) const;

  private:
  int rows;
  int cols;

  std::vector<std::vector<int>> data;
};