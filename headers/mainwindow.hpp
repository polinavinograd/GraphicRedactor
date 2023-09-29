#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "DrawableObject.hpp"
#include "Line.hpp"
#include "Modes.hpp"
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MyGraphicRedactor;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
  MainWindow(QWidget* parent = nullptr);
  void mousePressEvent(QMouseEvent* event) override;
  void paintEvent(QPaintEvent* event) override;
  ~MainWindow();

  private slots:
  void on_selectModeBox_activated(int index);

  private:
  std::shared_ptr<Line>                        currentObject;
  std::vector<std::shared_ptr<DrawableObject>> objs;
  std::shared_ptr<Mode>                        mode;
  Ui::MyGraphicRedactor*                       ui;
};
#endif // MAINWINDOW_HPP
