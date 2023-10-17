#include "../headers/Lines2Mode.hpp"
#include "../headers/mainwindow.hpp"
#include <algorithm>
#include <qpoint.h>

bool Lines2Mode::stopCondition(int x, int y)
{
  int limitX =
      std::max(line->getStart()->x(), window->width() - line->getStart()->x());
  int limitY =
      std::max(line->getStart()->y(), window->height() - line->getStart()->y());

  return x > limitX || y > limitY;
}

std::vector<QPoint> Lines2Mode::calculatePoints()
{
  initializeLine();

  std::vector<QPoint> result;

  int x = line->getStart()->x();
  int y = line->getStart()->y();

  int error = countStartError();
  while (!stopCondition(x, y))
  {
    result.emplace_back(QPoint(x, y));
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
  return result;
}