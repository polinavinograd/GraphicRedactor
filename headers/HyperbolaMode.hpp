#pragma once

#include "DrawableObject.hpp"
#include "Lines2Mode.hpp"

class HyperbolaMode : public Lines2Mode
{
  public:
  HyperbolaMode(std::shared_ptr<DrawableObject> currentLine,
                std::shared_ptr<MainWindow>     newWindow)
      : Lines2Mode(currentLine, newWindow){};

  protected:
  void initializeLine() override final;

  int countHorizontalError(int x, int error) override final;
  int countVerticalError(int y, int error) override final;
  int countDiagonalError(int x, int y, int error) override final;
  int countStartError() override;

  bool isDiagonalOrHorizontal(int error) const final;
  bool isDiagonalOrVertical(int error) const final;

  int getStartX() override final;
  int getStartY() override final;

  private:
  int a;
  int b;
};