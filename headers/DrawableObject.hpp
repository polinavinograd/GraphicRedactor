#pragma once

#include "Mode.hpp"

#include <QPainter>
#include <vector>

// class MainWindow;

class DrawableObject
{
public:
    DrawableObject()                                     = default;
    virtual void draw(std::shared_ptr<QPainter> painter) = 0;
    virtual bool isFinished(QPoint point)                = 0;

protected:
    std::shared_ptr<Mode> mode;
    std::vector<QPoint>   points;
};
