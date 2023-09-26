#pragma once

#include "QPoint"

class Point : public QPoint
{
public:
    Point() = default;
    Point(int x, int y);

private:
    int    x        = 0;
    int    y        = 0;
    int    z        = 0;
    double rotation = 0;
};
