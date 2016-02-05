#pragma once
#pragma once
#include <QThread>
#include <QImage>
#include <QObject>
/**
 * @brief The MyImageProcessThread class
 *
 * 图像处理的线程类，需要传入一个QImage图像指针
 * 同时包含两个自定义信号
 */
class MyImageProcessThread : public QThread
{
    /*
     * 注意：必须添加Q_OBJECT宏使其能够应用Qt的信号槽机制，不然你就没法更新UI界面啦
     */
    Q_OBJECT

public:
    MyImageProcessThread();
    MyImageProcessThread(QString& imagePath,QObject* parent = 0);

    ~MyImageProcessThread();
    /*
     *继承QThread类之后，必须实现 run() 函数。在run函数中实现你要在子线程中运行的代码
     */
    virtual void run();


    QString getImagePath() const;
    void setImagePath(const QString &value);

signals:
    void processFinished(QImage*);//自定义信号。表示处理结束了。可以百度“自定义信号”查找更多内容
    void processProgress(int maxValue,int progress);//自定义信号。用以表示算法进度,maxValue表示进度最大值，progress表示当前值
private:
    QString imagePath;
    QImage* result;
};

