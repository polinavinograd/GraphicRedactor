#include "../headers/ParabolaMode.hpp"
#include <cmath>

void ParabolaMode::initializeLine()
{
  p = std::abs(line->getStart()->x() - line->getEnd()->x());
}

int ParabolaMode::countStartError()
{
  return -2 * p + 1;
}

int ParabolaMode::countHorizontalError(int x, int error)
{
  return error - 2 * p;
}

int ParabolaMode::countVerticalError(int y, int error)
{
  return error + 2 * y + 1;
}

int ParabolaMode::countDiagonalError(int x, int y, int error)
{
  return error + 2 * y + 1 - 2 * p;
}

int ParabolaMode::getStartX()
{
  return 0;
}

int ParabolaMode::getStartY()
{
  return p / 2;
}