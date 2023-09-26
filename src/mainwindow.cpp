#include "../headers/mainwindow.hpp"
#include "./ui_mainwindow.h"
// #include <qpainter.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MyGraphicRedactor)
{
    ui->setupUi(this);

    // pm.fill();
    painter = new QPainter(this);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (!currentObject)
        {
            return;
        }
        if (currentObject->isFinished(event->pos()))
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
    // QPainter painter(&pm);
    // painter.drawPixmap(0, 0, 700, 600, pm);
    // painter.drawPoint(100, 100);

    painter->begin(this);
    for (auto& obj : objs)
    {
        obj->draw(*painter);
    }
    painter->end();
}

MainWindow::~MainWindow()
{
    delete ui;
    // delete painter;
}

void MainWindow::on_selectModeBox_activated(int index)
{
    switch (index)
    {
        case 0:
            currentObject = std::make_shared<Line>();
            mode          = std::make_shared<DDAMode>(currentObject);
            objs.emplace_back(currentObject);
            break;
        case 1:
            currentObject = std::make_shared<Line>();
            mode          = std::make_shared<BrazenhemLinesMode>(currentObject);
            objs.emplace_back(currentObject);
            break;
            /*case 2:
                currentObject = std::make_shared<Line>();
                mode          = std::make_shared<WuMode>(currentObject);
                objs.emplace_back(currentObject);
                break;*/
    }
}
