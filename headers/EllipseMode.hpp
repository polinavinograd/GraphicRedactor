#pragma once

#include "Lines2Mode.hpp"

class EllipseMode : public Lines2Mode
{
  public:
  EllipseMode(std::shared_ptr<Line> currentLine)
      : line(currentLine){};

  protected:
  void initializeLine() override final;

  int countHorizontalError(int x, int error) override final;
  int countVerticalError(int y, int error) override final;
  int countDiagonalError(int x, int y, int error) override final;
  int countStartError() override;

  private:
  int                   a;
  int                   b;
  std::shared_ptr<Line> line;
};