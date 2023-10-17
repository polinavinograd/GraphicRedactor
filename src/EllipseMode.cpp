#include "../headers/EllipseMode.hpp"

void EllipseMode::initializeLine()
{
  a = std::abs(line->getEnd()->x() - line->getStart()->x());
  b = std::abs(line->getEnd()->y() - line->getStart()->y());
}

int EllipseMode::countStartError()
{
  return std::pow(a, 2) + std::pow(b, 2) - 2 * std::pow(a, 2) * b;
}

int EllipseMode::countHorizontalError(int x, int error)
{
  return error + std::pow(b, 2) * (2 * x + 1);
}

int EllipseMode::countVerticalError(int y, int error)
{
  return error + std::pow(a, 2) * (1 - 2 * y);
}

int EllipseMode::countDiagonalError(int x, int y, int error)
{
  return error + std::pow(b, 2) * (2 * x + 1) + std::pow(a, 2) * (1 - 2 * y);
}

int EllipseMode::getStartX()
{
  return 0;
}

int EllipseMode::getStartY()
{
  return b;
}