/********************************************************************************
** Form generated from reading UI file 'lose.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSE_H
#define UI_LOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lose
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *lose)
    {
        if (lose->objectName().isEmpty())
            lose->setObjectName("lose");
        lose->resize(327, 277);
        lose->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(lose);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 90, 301, 141));
        pushButton = new QPushButton(lose);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 321, 281));

        retranslateUi(lose);

        QMetaObject::connectSlotsByName(lose);
    } // setupUi

    void retranslateUi(QWidget *lose)
    {
        lose->setWindowTitle(QCoreApplication::translate("lose", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("lose", "T\351\230\265\350\220\245\350\203\234\345\210\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lose: public Ui_lose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSE_H
