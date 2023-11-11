#include "../headers/DrawableObject.hpp"

void DrawableObject::setMode(std::shared_ptr<Mode> mode)
{
  this->mode = mode;
}

void DrawableObject::setFinished()
{
  this->finished = true;
}

std::shared_ptr<Point> DrawableObject::getStart()
{
  return start;
}

std::shared_ptr<Point> DrawableObject::getEnd()
{
  return end;
}

void DrawableObject::draw(QPainter& painter)
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
