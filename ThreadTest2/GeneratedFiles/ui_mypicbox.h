/********************************************************************************
** Form generated from reading UI file 'mypicbox.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPICBOX_H
#define UI_MYPICBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyPicBox
{
public:

    void setupUi(QWidget *MyPicBox)
    {
        if (MyPicBox->objectName().isEmpty())
            MyPicBox->setObjectName(QStringLiteral("MyPicBox"));
        MyPicBox->resize(400, 300);

        retranslateUi(MyPicBox);

        QMetaObject::connectSlotsByName(MyPicBox);
    } // setupUi

    void retranslateUi(QWidget *MyPicBox)
    {
        MyPicBox->setWindowTitle(QApplication::translate("MyPicBox", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MyPicBox: public Ui_MyPicBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPICBOX_H
