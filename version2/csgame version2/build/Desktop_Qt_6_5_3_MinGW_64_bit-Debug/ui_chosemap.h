/********************************************************************************
** Form generated from reading UI file 'chosemap.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOSEMAP_H
#define UI_CHOSEMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chosemap
{
public:
    QPushButton *map_2;
    QPushButton *map_3;
    QPushButton *map_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;

    void setupUi(QWidget *chosemap)
    {
        if (chosemap->objectName().isEmpty())
            chosemap->setObjectName("chosemap");
        chosemap->setEnabled(true);
        chosemap->resize(676, 298);
        chosemap->setMouseTracking(false);
        chosemap->setStyleSheet(QString::fromUtf8(""));
        map_2 = new QPushButton(chosemap);
        map_2->setObjectName("map_2");
        map_2->setGeometry(QRect(50, 80, 100, 100));
        map_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 50%;          \n"
"\n"
"	border-image: url(:/images/dust2.jpg);\n"
"}\n"
"\n"
""));
        map_3 = new QPushButton(chosemap);
        map_3->setObjectName("map_3");
        map_3->setGeometry(QRect(260, 80, 100, 100));
        map_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-image: url(:/images/mirrage.jpg);\n"
"    border-radius: 50%;          \n"
"\n"
"\n"
"    \n"
"}"));
        map_4 = new QPushButton(chosemap);
        map_4->setObjectName("map_4");
        map_4->setGeometry(QRect(470, 80, 100, 100));
        map_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-image: url(:/images/INFERNO.jpg);\n"
"    border-radius: 50%;          \n"
"\n"
"}"));
        label = new QLabel(chosemap);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 190, 71, 21));
        label_2 = new QLabel(chosemap);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 190, 61, 20));
        label_3 = new QLabel(chosemap);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(500, 190, 51, 16));
        lineEdit = new QLineEdit(chosemap);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(270, 10, 81, 41));
        lineEdit->setReadOnly(true);
        lineEdit->setClearButtonEnabled(false);

        retranslateUi(chosemap);

        QMetaObject::connectSlotsByName(chosemap);
    } // setupUi

    void retranslateUi(QWidget *chosemap)
    {
        chosemap->setWindowTitle(QCoreApplication::translate("chosemap", "Form", nullptr));
        map_2->setText(QString());
        map_3->setText(QString());
        map_4->setText(QString());
        label->setText(QCoreApplication::translate("chosemap", "\347\202\231\347\203\255\346\262\231\345\237\2162", nullptr));
        label_2->setText(QCoreApplication::translate("chosemap", "\350\215\222\346\274\240\350\277\267\345\237\216", nullptr));
        label_3->setText(QCoreApplication::translate("chosemap", "\347\202\274\347\213\261\345\260\217\351\225\207", nullptr));
        lineEdit->setText(QCoreApplication::translate("chosemap", "   \351\200\211\346\213\251\344\275\240\347\232\204\345\234\260\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chosemap: public Ui_chosemap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOSEMAP_H
