#pragma once

#include "mypicbox.h"
#include "ui_mypicbox.h"
#include <QPainter>
#include <QRect>
#include <QDebug>
MyPicBox::MyPicBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPicBox)
{
    ui->setupUi(this);
}

MyPicBox::MyPicBox(QImage *image, QWidget *parent):QWidget(parent),ui(new Ui::MyPicBox)
{
    ui->setupUi(this);
    if(image != NULL)
       {
        this->image = image;
        }
}

MyPicBox::~MyPicBox()
{
    delete ui;
    //记得要释放QImage对象
    if(this->image != NULL)
        delete this->image;
}

void MyPicBox::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect = this->geometry();
    painter.drawImage(rect,*(this->image));
}
