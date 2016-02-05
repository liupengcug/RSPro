#pragma once
#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QDialog>
#include <QImage>
#include "my_thread.h"
namespace Ui {
class MainDialog;
}
/**
 * @brief The MainDialog class
 *
 * 主对话框类
 */
class MainDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private slots:
    void on_pushButton_selectImage_clicked();

    void on_pushButton_toGrayImage_clicked();
    /**
     * @brief showImageInNewWindow 接收由子线程信号传来的QImage指针，并显示这个QImage
     * @param image
     */
    void showImageInNewWindow(QImage* image);
    /**
     * @brief closeThread 如果关闭Dialog的时候子线程还没有结束，应该手动结束它
     */
    void closeThread();
    /**
     * @brief SetProgress 设置对话框中的进度条进度
     * @param max 进度条最大值
     * @param value 当前值
     */
    void SetProgress(int max,int value);
private:
    Ui::MainDialog *ui;
    MyImageProcessThread* thread;
    QString imagePath;
    bool hasProgressBarMaxSet;//进度条的最大值是否已经设置，如果已经设置了就不需要重新设置了，不然UI会反复出现进度条增长
    QImage* imageSelected;//原来的图片(无视，这里根本没用它)
    QImage* imageAfterProceess;//处理后的图片(无视，这里根本没用它)
};

#endif // MAIN_DIALOG_H
