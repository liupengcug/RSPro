/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QPushButton *pushButton_toGrayImage;
    QPushButton *pushButton_selectImage;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QProgressBar *progressBar;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QStringLiteral("MainDialog"));
        MainDialog->resize(520, 81);
        pushButton_toGrayImage = new QPushButton(MainDialog);
        pushButton_toGrayImage->setObjectName(QStringLiteral("pushButton_toGrayImage"));
        pushButton_toGrayImage->setGeometry(QRect(430, 50, 81, 21));
        pushButton_selectImage = new QPushButton(MainDialog);
        pushButton_selectImage->setObjectName(QStringLiteral("pushButton_selectImage"));
        pushButton_selectImage->setGeometry(QRect(340, 50, 75, 23));
        widget = new QWidget(MainDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 501, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        widget1 = new QWidget(MainDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 50, 321, 22));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        progressBar = new QProgressBar(widget1);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);

        QWidget::setTabOrder(pushButton_selectImage, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton_toGrayImage);

        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "\351\200\211\346\213\251\345\233\276\347\211\207", 0));
        pushButton_toGrayImage->setText(QApplication::translate("MainDialog", "\345\244\232\347\272\277\347\250\213\347\201\260\345\272\246\345\214\226", 0));
        pushButton_selectImage->setText(QApplication::translate("MainDialog", "\351\200\211\346\213\251\345\233\276\347\211\207", 0));
        label->setText(QApplication::translate("MainDialog", "\345\233\276\347\211\207\350\267\257\345\276\204:", 0));
        label_2->setText(QApplication::translate("MainDialog", "\345\275\223\345\211\215\350\277\233\345\272\246:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
