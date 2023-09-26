#include "../headers/Line.hpp"
#include <qpoint.h>

bool Line::isFinished(QPoint point)
{
    if (!start)
    {
        start = &point;
        return false;
    }
    if (!end)
    {
        end    = &point;
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

QPoint* Line::getStart()
{
    return start;
}

QPoint* Line::getEnd()
{
    return end;
}
