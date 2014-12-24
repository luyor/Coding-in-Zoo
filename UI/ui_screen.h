/********************************************************************************
** Form generated from reading UI file 'screen.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_H
#define UI_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screen
{
public:
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *screen)
    {
        if (screen->objectName().isEmpty())
            screen->setObjectName(QStringLiteral("screen"));
        screen->resize(557, 440);
        radioButton_2 = new QRadioButton(screen);
        buttonGroup = new QButtonGroup(screen);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(40, 170, 241, 28));
        radioButton_4 = new QRadioButton(screen);
        buttonGroup->addButton(radioButton_4);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(40, 290, 241, 28));
        radioButton = new QRadioButton(screen);
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(40, 110, 231, 28));
        radioButton_3 = new QRadioButton(screen);
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(40, 230, 231, 28));
        label = new QLabel(screen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 231, 51));
        layoutWidget = new QWidget(screen);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 350, 311, 47));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        retranslateUi(screen);

        QMetaObject::connectSlotsByName(screen);
    } // setupUi

    void retranslateUi(QDialog *screen)
    {
        screen->setWindowTitle(QApplication::translate("screen", "screen", 0));
        radioButton_2->setText(QApplication::translate("screen", "Small Screen Mode", 0));
        radioButton_4->setText(QApplication::translate("screen", "Full Screen Mode", 0));
        radioButton->setText(QApplication::translate("screen", "Current Setting", 0));
        radioButton_3->setText(QApplication::translate("screen", "Big Screen Mode", 0));
        label->setText(QApplication::translate("screen", "<html><head/><body><p><span style=\" font-size:12pt;\">Size Of Screen</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("screen", "OK", 0));
        pushButton_2->setText(QApplication::translate("screen", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class screen: public Ui_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_H
