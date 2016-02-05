#pragma once
#include <QWidget>
#include <QImage>

namespace Ui {
class MyPicBox;
}
/**
 * @brief The MyPicBox class
 * 用于绘制QImage的自定义QWidget。同样需要你传入一个QImage指针
 * 当需要显示图片时，这个类（也就是这个QWidget）会被装进一个QMianWindow。
 */
class MyPicBox : public QWidget
{
    Q_OBJECT
public:
    explicit MyPicBox(QWidget *parent = 0);
    explicit MyPicBox(QImage* image , QWidget *parent = 0);
    ~MyPicBox();
protected:
    //考虑到QLabel显示图像时的限制。我们这里直接把图像画出来。
    void paintEvent(QPaintEvent * event);
private:
    Ui::MyPicBox *ui;
    QImage* image;
};

