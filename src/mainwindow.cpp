#include "../headers/mainwindow.hpp"
#include "./ui_mainwindow.h"
// #include <qpainter.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MyGraphicRedactor)
    , pm(800, 600)
{
  ui->setupUi(this);

  pm.fill();
  painter = new QPainter(&pm);

  // painter = new QPainter(this);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
  if (event->button() == Qt::LeftButton)
  {
    if (!currentObject)
    {
      return;
    }
    if (currentObject->tryFinish(event->pos()))
    {
      currentObject = nullptr;
    }
    ui->editX->setText(QString::number(event->pos().x()));
    ui->editY->setText(QString::number(event->pos().y()));
    ui->editZ->setText(QString::number(0));
    ui->editRotation->setText(QString::number(1));

    update();
  }
}

void MainWindow::paintEvent(QPaintEvent* event)
{
  // if (!painter)
  // {
  //     painter = new QPainter(this);
  // }
  // painter.drawPoint(100, 100);

  painter->begin(this);
  painter->drawPixmap(0, 0, 800, 600, pm);

  for (auto& obj : objs)
  {
    obj->draw(*painter);
  }
  painter->end();
}

MainWindow::~MainWindow()
{
  delete ui;
  delete painter;
}

void MainWindow::on_selectModeBox_activated(int index)
{
  switch (index)
  {
    case 0:
      currentObject = std::make_shared<Line>();
      mode          = std::make_shared<DDAMode>(currentObject);
      currentObject->setMode(mode);
      objs.emplace_back(currentObject);
      break;
    case 1:
      currentObject = std::make_shared<Line>();
      mode          = std::make_shared<BrazenhemLinesMode>(currentObject);
      currentObject->setMode(mode);
      objs.emplace_back(currentObject);
      break;
      /*case 2:
          currentObject = std::make_shared<Line>();
          mode          = std::make_shared<WuMode>(currentObject);
          objs.emplace_back(currentObject);
          break;*/
  }
}
