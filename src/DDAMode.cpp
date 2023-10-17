#include "../headers/DDAMode.hpp"
#include "../headers/mainwindow.hpp"

int sign(float number)
{
  if (number == 0.0f)
    return 0;
  else
    return (number > 0) ? 1 : -1;
}

std::vector<QPoint> DDAMode::calculatePoints()
{
  std::vector<QPoint> result;

  int deltaX = line->getEnd()->x() - line->getStart()->x();
  int deltaY = line->getEnd()->y() - line->getStart()->y();

  int length;
  if (abs(deltaX) > abs(deltaY))
  {
    length = abs(deltaX);
  }
  else
  {
    length = abs(deltaY);
  }

  float dx = float(deltaX) / length;
  float dy = float(deltaY) / length;

  float x = line->getStart()->x() + 0.5 * sign(dx);
  float y = line->getStart()->y() + 0.5 * sign(dy);
  for (int i = 0; i < length; i++)
  {
    x += dx;
    y += dy;
    result.emplace_back(QPoint(round(x), round(y)));
  }

  return result;
}
