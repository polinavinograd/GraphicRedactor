#include "../headers/ParabolaMode.hpp"
#include <cmath>

void ParabolaMode::initializeLine()
{
  p = std::abs(line->getStart()->x() - line->getEnd()->x());
}

int ParabolaMode::countStartError()
{
  return 1 - std::pow(p, 2) - 2 * p;
}

int ParabolaMode::countHorizontalError(int x, int error)
{
  return error - 2 * p;
}

int ParabolaMode::countVerticalError(int y, int error)
{
  return error + 1 - 2 * y;
}

int ParabolaMode::countDiagonalError(int x, int y, int error)
{
  return error - 2 * y + 1 - 2 * p;
}