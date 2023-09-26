#pragma once

#include <QPoint>
#include <vector>

class Mode
{
public:
    virtual std::vector<QPoint> calculatePoints() = 0;
};