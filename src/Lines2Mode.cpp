#include "../headers/Lines2Mode.hpp"
#include "../headers/Point.hpp"
#include "../headers/mainwindow.hpp"
#include <algorithm>

bool Lines2Mode::stopCondition(int x, int y)
{
  int limitX =
      std::max(line->getStart()->x(), window->width() - line->getStart()->x());
  int limitY =
      std::max(line->getStart()->y(), window->height() - line->getStart()->y());

  return x > limitX || y > limitY;
}

std::vector<Point> Lines2Mode::calculatePoints()
{
  initializeLine();
  zero = *line->getStart();

  std::vector<Point> result;

  int x = getStartX();
  int y = getStartY();

  int error = countStartError();
  while (!stopCondition(x, y))
  {
    addPoints(result, x, y);
    if (isDiagonalOrHorizontal(error))
    {
      if (std::abs(countHorizontalError(x, error)) -
              std::abs(countDiagonalError(x, y, error)) >
          0)
      {
        error = countDiagonalError(x, y, error);
        x += 1;
        y += deltaY();
      }
      else
      {
        error = countHorizontalError(x, error);
        x += 1;
      }
      continue;
    }
    if (isDiagonalOrVertical(error))
    {
      if (std::abs(countDiagonalError(x, y, error)) -
              std::abs(countVerticalError(y, error)) >
          0)
      {
        error = countVerticalError(y, error);
        y += deltaY();
      }
      else
      {
        error = countDiagonalError(x, y, error);
        x += 1;
        y += deltaY();
      }
      continue;
    }
    if (error == 0)
    {
      error = countDiagonalError(x, y, error);
      x += 1;
      y += deltaY();
      continue;
    }
  }
  addPoints(result, x, y);

  return result;
}

void Lines2Mode::addPoint(std::vector<Point>& points, const Point& point) const
{
  if (point.x() < 0 || point.y() < 0 || point.x() > window->width() ||
      point.y() > window->height())
    return;
  points.emplace_back(point);
}

void Lines2Mode::addPoints(std::vector<Point>& points, int x, int y) const
{
  addPoint(points, Point(-x, -y).toScreenPoint(zero));
  addPoint(points, Point(-x, y).toScreenPoint(zero));
  addPoint(points, Point(x, y).toScreenPoint(zero));
  addPoint(points, Point(x, -y).toScreenPoint(zero));
}

bool Lines2Mode::isDiagonalOrHorizontal(int error) const
{
  return error < 0;
}

bool Lines2Mode::isDiagonalOrVertical(int error) const
{
  return error > 0;
}

int Lines2Mode::deltaY() const
{
  return 1;
}