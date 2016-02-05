#pragma once
#include "my_thread.h"
#include <QDebug>
#include <QTime>

MyImageProcessThread::MyImageProcessThread()
{

}

MyImageProcessThread::MyImageProcessThread(QString &imagePath, QObject *parent):QThread(parent)
{
    if(!imagePath.isEmpty())
        this->imagePath = imagePath;
}

MyImageProcessThread::~MyImageProcessThread()
{

}

void MyImageProcessThread::run()
{
    //这里我们记录下当前系统时间，统计一下算法耗时
    QTime timer = QTime::currentTime();
    timer.start();//开始计时

   if(this->imagePath.isEmpty())
   {
        qDebug()<<"path is NULL";
       return;
    }
   //摘自某博文:
   //采用bits()方法的到的数据data中像素的组织形式应为ARGB，
   //但实际调试中发现，每个像素中从字节从低到高依次是BGRA，方向刚好反过来。
   QImage* image = new QImage(imagePath);
   unsigned char* data = image->bits();//取得QImage对应的byte数组
   int byteCount = image->byteCount();//byte数组长度
   unsigned char* dataNew = new unsigned char[byteCount];//再申请一个一样大小的数组

   int counter = 0;//循环记录处理了多少个字节
   int hasDone = 0;//记录累计处理的百分比
   for(int i  = 0 ; i <byteCount ; i+=4)
    {
        unsigned char grayByte = (unsigned char)(0.30 *data[ i+2] +0.59*data[ i + 1]+0.11*data[ i]);
        dataNew[i]     = grayByte;
        dataNew[i+1] = grayByte;
        dataNew[i+2] = grayByte;
        dataNew[i+3] = data[i+3];
        //每处理到字节总量的1/100就更新一次UI
        if(counter == (int)(byteCount/100))
          {
            counter = 0;
            hasDone +=1;
            emit processProgress(100,hasDone);
            this->sleep(1);//这里我让线程休眠1秒，不然进度条瞬间就走完了。
            }
        else
            counter++;

    }
   emit processProgress(100,100);
   //生成新的QImage
    int w = image->width();
   int h = image->height();
   QImage* newImage = new QImage(dataNew,w,h,image->format());

   //取得算法结束的时间
  int timeTaken = timer.elapsed();
   qDebug()<<"Processing takes "<<timeTaken<<"ms"<<endl;

    //处理完毕后，我们就可以发射信号让UI线程接收处理后的图像了
   qDebug()<<"process has been finished.Get ready for emitting the signal !!! ";
   emit processFinished(newImage);
}


QString MyImageProcessThread::getImagePath() const
{
    return imagePath;
}

void MyImageProcessThread::setImagePath(const QString &value)
{
    imagePath = value;
}


