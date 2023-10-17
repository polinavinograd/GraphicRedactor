#include "../headers/Line.hpp"
#include <memory>

bool Line::tryFinish(Point point)
{
  if (!start)
  {
    start = std::make_shared<Point>(point);
    return false;
  }
  if (!end)
  {
    end    = std::make_shared<Point>(point);
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

std::shared_ptr<Point> Line::getStart()
{
  return start;
}

std::shared_ptr<Point> Line::getEnd()
{
  return end;
}
