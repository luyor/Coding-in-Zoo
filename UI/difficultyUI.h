/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DIFFICULTYUI_H
#define DIFFICULTYUI_H

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

class Ui_Dialog_Difficulty
{

public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QLabel *label_3;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QRadioButton *radioButton_11;
    QRadioButton *radioButton_12;
    QLabel *label_4;
    QRadioButton *radioButton_13;
    QRadioButton *radioButton_14;


    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(557, 440);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 311, 51));
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(210, 360, 311, 47));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        horizontalLayout_2->addWidget(pushButton_2);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 141, 24));
        radioButton_5 = new QRadioButton(Dialog);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(180, 100, 91, 28));
        radioButton_6 = new QRadioButton(Dialog);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(350, 100, 141, 28));
        radioButton_7 = new QRadioButton(Dialog);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setGeometry(QRect(350, 140, 161, 28));
        radioButton_8 = new QRadioButton(Dialog);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setGeometry(QRect(180, 140, 151, 28));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 180, 151, 24));
        radioButton_9 = new QRadioButton(Dialog);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        radioButton_9->setGeometry(QRect(180, 180, 131, 28));
        radioButton_10 = new QRadioButton(Dialog);
        radioButton_10->setObjectName(QStringLiteral("radioButton_10"));
        radioButton_10->setGeometry(QRect(180, 220, 141, 28));
        radioButton_11 = new QRadioButton(Dialog);
        radioButton_11->setObjectName(QStringLiteral("radioButton_11"));
        radioButton_11->setGeometry(QRect(350, 180, 151, 28));
        radioButton_12 = new QRadioButton(Dialog);
        radioButton_12->setObjectName(QStringLiteral("radioButton_12"));
        radioButton_12->setGeometry(QRect(350, 220, 141, 28));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 270, 151, 24));
        radioButton_13 = new QRadioButton(Dialog);
        radioButton_13->setObjectName(QStringLiteral("radioButton_13"));
        radioButton_13->setGeometry(QRect(180, 270, 141, 28));
        radioButton_14 = new QRadioButton(Dialog);
        radioButton_14->setObjectName(QStringLiteral("radioButton_14"));
        radioButton_14->setGeometry(QRect(350, 270, 161, 28));

        retranslateUi(Dialog);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Difficulty Setting", 0));
        label->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:12pt;\">Difficulty Setting</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("Dialog", "OK", 0));
        pushButton_2->setText(QApplication::translate("Dialog", "Cancel", 0));
        label_2->setText(QApplication::translate("Dialog", "Difficulty:", 0));
        radioButton_5->setText(QApplication::translate("Dialog", "Easy", 0));
        radioButton_6->setText(QApplication::translate("Dialog", "Ordinary", 0));
        radioButton_7->setText(QApplication::translate("Dialog", "Nightmare", 0));
        radioButton_8->setText(QApplication::translate("Dialog", "Difficult", 0));
        label_3->setText(QApplication::translate("Dialog", "Reborn Time:", 0));
        radioButton_9->setText(QApplication::translate("Dialog", "3 Reborn", 0));
        radioButton_10->setText(QApplication::translate("Dialog", "7 Reborn", 0));
        radioButton_11->setText(QApplication::translate("Dialog", "5 Reborn", 0));
        radioButton_12->setText(QApplication::translate("Dialog", "9 Reborn", 0));
        label_4->setText(QApplication::translate("Dialog", "Initial Bomb:", 0));
        radioButton_13->setText(QApplication::translate("Dialog", "Read One", 0));
        radioButton_14->setText(QApplication::translate("Dialog", "Yellow One", 0));
    } // retranslateUi

};



class difficultyUI : public QDialog,public Ui_Dialog_Difficulty
{
public:
    difficultyUI();
};



namespace Ui {
    class Dialog_Difficulty: public Ui_Dialog_Difficulty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
