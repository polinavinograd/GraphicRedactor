#include "../headers/HyperbolaMode.hpp"

void HyperbolaMode::initializeLine()
{
  a = std::abs(line->getEnd()->x() - line->getStart()->x());
  b = std::abs(line->getEnd()->y() - line->getStart()->y());
}

int HyperbolaMode::countStartError()
{
  return std::pow(b, 2) - std::pow(a, 2) + 2 * std::pow(a, 2) * b -
         2 * std::pow(a, 2) * std::pow(b, 2);
}

int HyperbolaMode::countHorizontalError(int x, int error)
{
  return error + std::pow(b, 2) * (2 * x + 1);
}

int HyperbolaMode::countVerticalError(int y, int error)
{
  return error - std::pow(a, 2) * (2 * y - 1);
}

int HyperbolaMode::countDiagonalError(int x, int y, int error)
{
  return error + std::pow(b, 2) * (2 * x + 1) - std::pow(a, 2) * (1 - 2 * y);
}