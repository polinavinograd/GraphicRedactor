#include "../headers/Lines2Mode.hpp"

std::vector<QPoint> Lines2Mode::calculatePoints()
{
  initializeLine();

  std::vector<QPoint> result;

  int x = line->getStart()->x();
  int y = line->getStart()->y();

  int error = countStartError();
  while (...) // add stop-condition
  {
    // add mirrored points
    if (error < 0)
    {
      if (std::abs(countHorizontalError(x, error)) -
              std::abs(countDiagonalError(x, y, error)) >
          0)
      {
        error = countDiagonalError(x, y, error);
        x += 1;
        y -= 1;
      }
      else
      {
        error = countHorizontalError(x, error);
        x += 1;
      }
      continue;
    }
    if (error > 0)
    {
      if (std::abs(countDiagonalError(x, y, error)) -
              std::abs(countVerticalError(y, error)) >
          0)
      {
        error = countVerticalError(y, error);
        y -= 1;
      }
      else
      {
        error = countDiagonalError(x, y, error);
        x += 1;
        y -= 1;
      }
      continue;
    }
    if (error == 0)
    {
      error = countDiagonalError(x, y, error);
      x += 1;
      y -= 1;
      continue;
    }
  }
  // add mirrored points
}