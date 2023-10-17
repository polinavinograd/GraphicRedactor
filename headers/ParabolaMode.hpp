#pragma once

#include "Lines2Mode.hpp"

class ParabolaMode : public Lines2Mode
{
  public:
  ParabolaMode(std::shared_ptr<Line>       currentLine,
               std::shared_ptr<MainWindow> newWindow)
      : Lines2Mode(currentLine, newWindow){};

  protected:
  void initializeLine() override final;

  int countHorizontalError(int x, int error) override final;
  int countVerticalError(int y, int error) override final;
  int countDiagonalError(int x, int y, int error) override final;
  int countStartError() override;

  private:
  int p;
};