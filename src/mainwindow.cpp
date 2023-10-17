#include "../headers/mainwindow.hpp"
#include "./ui_mainwindow.h"
#include <memory>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MyGraphicRedactor)
{
  ui->setupUi(this);
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
  QPainter painter(this);
  // QPen     linepen(Qt::red);
  // linepen.setCapStyle(Qt::RoundCap);
  // linepen.setWidth(30);
  // painter.setRenderHint(QPainter::Antialiasing, true);
  // painter.setPen(linepen);

  for (auto& obj : objs)
  {
    obj->draw(painter);
  }
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_selectModeBox_activated(int index)
{
  switch (index)
  {
    case 0:
      currentObject = std::make_shared<Line>();
      mode          = std::make_shared<DDAMode>(currentObject,
                                       std::shared_ptr<MainWindow>(this));
      currentObject->setMode(mode);
      objs.emplace_back(currentObject);
      break;
    case 1:
      currentObject = std::make_shared<Line>();
      mode          = std::make_shared<BrazenhemLinesMode>(
          currentObject, std::shared_ptr<MainWindow>(this));
      currentObject->setMode(mode);
      objs.emplace_back(currentObject);
      break;
    case 2:
      currentObject = std::make_shared<Line>();
      mode          = std::make_shared<WuMode>(currentObject,
                                      std::shared_ptr<MainWindow>(this));
      currentObject->setMode(mode);
      objs.emplace_back(currentObject);
      break;
    case 3:
      currentObject = std::make_shared<Line>();
      mode          = std::make_shared<CircleMode>(currentObject,
                                          std::shared_ptr<MainWindow>(this));
      currentObject->setMode(mode);
      objs.emplace_back(currentObject);
      break;
    case 4:
      currentObject = std::make_shared<Line>();
      mode          = std::make_shared<EllipseMode>(currentObject,
                                           std::shared_ptr<MainWindow>(this));
      currentObject->setMode(mode);
      objs.emplace_back(currentObject);
      break;
    case 5:
      currentObject = std::make_shared<Line>();
      mode          = std::make_shared<ParabolaMode>(currentObject,
                                            std::shared_ptr<MainWindow>(this));
      currentObject->setMode(mode);
      objs.emplace_back(currentObject);
      break;
    case 6:
      currentObject = std::make_shared<Line>();
      mode          = std::make_shared<HyperbolaMode>(currentObject,
                                             std::shared_ptr<MainWindow>(this));
      currentObject->setMode(mode);
      objs.emplace_back(currentObject);
      break;
  }
}

void MainWindow::on_clearBtn_clicked()
{
  objs.clear();
  update();
}
