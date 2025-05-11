/********************************************************************************
** Form generated from reading UI file 'win.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_H
#define UI_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_win
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *win)
    {
        if (win->objectName().isEmpty())
            win->setObjectName("win");
        win->resize(234, 188);
        win->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(win);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 241, 191));

        retranslateUi(win);

        QMetaObject::connectSlotsByName(win);
    } // setupUi

    void retranslateUi(QWidget *win)
    {
        win->setWindowTitle(QCoreApplication::translate("win", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("win", "CT\351\230\265\350\220\245\350\203\234\345\210\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class win: public Ui_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_H
