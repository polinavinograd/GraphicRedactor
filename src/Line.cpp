#include "../headers/Line.hpp"
#include <memory>

bool Line::tryFinish(Point point)
{
  if (!start)
  {
    start = new Point(point);
    return false;
  }
  if (!end)
  {
    end    = new Point(point);
    points = mode->calculatePoints();
  }
  return true;
}

void Line::draw(QPainter& painter)
{
  if (points.empty())
  {
    if (start)
    {
      painter.drawPoint(start->x(), start->y());
    }
    if (end)
    {
      painter.drawPoint(end->x(), end->y());
    }
    return;
  }
  for (const auto& point : points)
  {
    painter.drawPoint(point.x(), point.y());
  }
}

Point* Line::getStart()
{
  return start;
}

Point* Line::getEnd()
{
  return end;
}
