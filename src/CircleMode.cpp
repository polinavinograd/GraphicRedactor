#include "../headers/CircleMode.hpp"

void CircleMode::initializeLine()
{
  radius =
      std::sqrt((std::pow(line->getStart()->x() - line->getEnd()->x(), 2) +
                 std::pow(line->getStart()->y() - line->getEnd()->y(), 2)));
}

int CircleMode::countStartError()
{
  return 2 - 2 * radius;
}

int CircleMode::countHorizontalError(int x, int error)
{
  return error + 2 * x + 1;
}

int CircleMode::countVerticalError(int y, int error)
{
  return error - 2 * y + 1;
}

int CircleMode::countDiagonalError(int x, int y, int error)
{
  return error + 2 * (x - y + 1);
}

int CircleMode::getStartX()
{
  return 0;
}

int CircleMode::getStartY()
{
  return radius;
}