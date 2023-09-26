#include "../headers/mainwindow.hpp"
#include "./ui_mainwindow.h"

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
        if (currentObject->isFinished(event->pos()))
        {
            currentObject = nullptr;
        }
        repaint();
    }
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    painter->begin(this);
    for (auto& obj : objs)
    {
        obj->draw(painter);
    }
    painter->end();
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
