#include "../headers/ParabolaMode.hpp"
#include <cmath>

void ParabolaMode::initializeLine()
{
  isNegative = line->getEnd()->x() - line->getStart()->x() < 0;
  p          = std::abs(line->getStart()->x() - line->getEnd()->x());
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
  return p / 2;
}

int ParabolaMode::getStartY()
{
  return 0;
}

void ParabolaMode::addPoints(std::vector<Point>& points, int x, int y) const
{
  if (isNegative)
  {
    addPoint(points, Point(-x, -y).toScreenPoint(zero));
    addPoint(points, Point(-x, y).toScreenPoint(zero));
  }
  else
  {
    addPoint(points, Point(x, y).toScreenPoint(zero));
    addPoint(points, Point(x, -y).toScreenPoint(zero));
  }
}

bool ParabolaMode::isDiagonalOrHorizontal(int error) const
{
  return error > 0;
}

bool ParabolaMode::isDiagonalOrVertical(int error) const
{
  return error < 0;
}