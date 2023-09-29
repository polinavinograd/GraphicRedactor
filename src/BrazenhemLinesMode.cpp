#include "../headers/BrazenhemLinesMode.hpp"

std::vector<QPoint> BrazenhemLinesMode::calculatePoints()
{
  int x1 = line->getStart()->x();
  int x2 = line->getEnd()->x();
  int y1 = line->getStart()->y();
  int y2 = line->getEnd()->y();

  std::vector<QPoint> result;

  const int deltaX = abs(x2 - x1);
  const int deltaY = abs(y2 - y1);
  const int signX  = x1 < x2 ? 1 : -1;
  const int signY  = y1 < y2 ? 1 : -1;
  int       error  = deltaX - deltaY;
  result.emplace_back(x2, y2);

  while (x1 != x2 || y1 != y2)
  {
    result.emplace_back(x1, y1);
    int error2 = error * 2;
    if (error2 > -deltaY)
    {
      error -= deltaY;
      x1 += signX;
    }
    if (error2 < deltaX)
    {
      error += deltaX;
      y1 += signY;
    }
  }

  return result;
}