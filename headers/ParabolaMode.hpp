#pragma once

#include "DrawableObject.hpp"
#include "Lines2Mode.hpp"

class ParabolaMode : public Lines2Mode
{
  public:
  ParabolaMode(std::shared_ptr<DrawableObject> currentLine,
               std::shared_ptr<MainWindow>     newWindow)
      : Lines2Mode(currentLine, newWindow){};

  protected:
  void initializeLine() override final;

  bool isDiagonalOrHorizontal(int error) const final;
  bool isDiagonalOrVertical(int error) const final;

  int countHorizontalError(int x, int error) override final;
  int countVerticalError(int y, int error) override final;
  int countDiagonalError(int x, int y, int error) override final;
  int countStartError() override;

  int getStartX() override final;
  int getStartY() override final;

  void addPoints(std::vector<Point>& points, int x, int y) const final;

  private:
  bool isNegative = false;
  int  p;
};