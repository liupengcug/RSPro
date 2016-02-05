#include <QDebug>
#include "my_thread.h"
#include "main_dialog.h"
#include "ui_maindialog.h"
#include "mypicbox.h"
#include <QFileDialog>
#include <QMainWindow>
MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    ui->label_2->setVisible(false);
    ui->progressBar->setVisible(false);
    hasProgressBarMaxSet = false;
    this->thread = new MyImageProcessThread();
    //---------------为了方便显示，我固定了Dialog大小----------
    QSize size = this->size();
    this->setFixedSize(size);
    //------------------------------------------------------------

    connect(this,SIGNAL(destroyed()),this,SLOT(closeThread()));
    //在这里关联从图像处理线程发出的信号，然后用showImageInNewWindow来处理由信号传入的QImage指针
    connect(thread,SIGNAL(processFinished(QImage*)),this,SLOT(showImageInNewWindow(QImage*)));
    connect(thread,SIGNAL(processProgress(int,int)),this,SLOT(SetProgress(int,int)));
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_pushButton_selectImage_clicked()
{
    this->imagePath = QFileDialog::getOpenFileName();
    ui->lineEdit->setText(imagePath);
}

void MainDialog::on_pushButton_toGrayImage_clicked()
{
    if(this->imagePath.isEmpty())
    {
        qDebug()<<"imagePath is  empty !!!";
        return ;
    }
     qDebug()<<"Start a new thread !!!";
     //由于子线程的创建是在Dialog的构造函数中进行的，那个时候图像路径还没有指定
     this->thread->setImagePath(this->imagePath);
     this->thread->start();
}

void MainDialog::showImageInNewWindow(QImage *image)
{
    QMainWindow*  picWindow = new QMainWindow(this);
    MyPicBox* picBox = new MyPicBox(image,picWindow);
    picWindow->setCentralWidget(picBox);

    //----------------为了防止图像过大，这里对图像显示窗口的大小做了点儿限制-----------------------
    if(image->width() > 600)
    {
        double scaleCoefficient =600.0/image->width();//压缩系数,以600宽度为准
        picWindow->resize(600,scaleCoefficient*image->height());//重新设定窗口大小
    }
    else if(image->height() > 800)
    {
        double scaleCoefficient =800.0/image->height();//压缩系数,以800高度为准
        picWindow->resize( scaleCoefficient*image->width(),800);//重新设定窗口大小
    }
   else
        picWindow->resize(image->width(),image->height());
    //----------------------------------------------------------------------------------------------------
    picWindow->setWindowTitle("处理结果");
    picWindow->move(100,100);//调整一下窗口位置
    picWindow->show();
}

void MainDialog::closeThread()
{
    if(this->thread->isRunning())
    {
        this->thread->terminate();
        qDebug()<<"Thread has been terminated !!!";
    }
}

void MainDialog::SetProgress(int max, int value)
{
  ui->label_2->setVisible(true);
  ui->progressBar->setVisible(true);
  if(!hasProgressBarMaxSet)
  {
      ui->progressBar->setMaximum(max);
      hasProgressBarMaxSet = true;
  }
  ui->progressBar->setValue(value);
}
