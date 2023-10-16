#include "../headers/ParabolaMode.hpp"

void ParabolaMode::initializeLine()
{
  // add p-init
}

int ParabolaMode::countStartError()
{
  // add start-error and start-point
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