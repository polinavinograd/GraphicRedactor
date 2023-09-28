#include "../headers/DrawableObject.hpp"

void DrawableObject::setMode(std::shared_ptr<Mode> mode)
{
  this->mode = mode;
}
/*
void DrawableObject::draw(QPainter& painter)
{
    for (const auto& point : points)
    {
        painter.drawPoint(point.x(), point.y());
    }
}*/
