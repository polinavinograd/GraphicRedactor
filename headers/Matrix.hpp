#pragma once

#include "Point.hpp"
#include <vector>

class Matrix
{
  public:
  Matrix() = default;
  Matrix(int rows, int cols);
  Matrix(std::vector<std::vector<double>> matrix);
  Matrix(const std::vector<double>& data);

  Matrix operator*(const Matrix& right) const;
  Matrix operator*(double number) const;

  Matrix                           transpose();
  std::vector<std::vector<double>> getData();

  private:
  int rows = 0;
  int cols = 0;

  std::vector<std::vector<double>> data = {};
};