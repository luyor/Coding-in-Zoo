/********************************************************************************
** Form generated from reading UI file 'difficulty.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTY_H
#define UI_DIFFICULTY_H

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

class Ui_Difficulty
{
public:
    QRadioButton *radioButton_10;
    QRadioButton *radioButton_13;
    QRadioButton *radioButton_14;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QLabel *label_3;
    QLabel *label;
    QRadioButton *radioButton_11;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_9;
    QLabel *label_4;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_12;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup_3;

    void setupUi(QDialog *Difficulty)
    {
        if (Difficulty->objectName().isEmpty())
            Difficulty->setObjectName(QStringLiteral("Difficulty"));
        Difficulty->resize(557, 440);
        radioButton_10 = new QRadioButton(Difficulty);
        buttonGroup_2 = new QButtonGroup(Difficulty);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(radioButton_10);
        radioButton_10->setObjectName(QStringLiteral("radioButton_10"));
        radioButton_10->setGeometry(QRect(360, 180, 151, 28));
        radioButton_13 = new QRadioButton(Difficulty);
        buttonGroup_3 = new QButtonGroup(Difficulty);
        buttonGroup_3->setObjectName(QStringLiteral("buttonGroup_3"));
        buttonGroup_3->addButton(radioButton_13);
        radioButton_13->setObjectName(QStringLiteral("radioButton_13"));
        radioButton_13->setGeometry(QRect(190, 270, 141, 28));
        radioButton_13->setChecked(true);
        radioButton_14 = new QRadioButton(Difficulty);
        buttonGroup_3->addButton(radioButton_14);
        radioButton_14->setObjectName(QStringLiteral("radioButton_14"));
        radioButton_14->setGeometry(QRect(360, 270, 161, 28));
        radioButton_6 = new QRadioButton(Difficulty);
        buttonGroup = new QButtonGroup(Difficulty);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_6);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(360, 100, 141, 28));
        radioButton_7 = new QRadioButton(Difficulty);
        buttonGroup->addButton(radioButton_7);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setGeometry(QRect(190, 140, 151, 28));
        label_3 = new QLabel(Difficulty);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 180, 151, 24));
        label = new QLabel(Difficulty);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 311, 51));
        radioButton_11 = new QRadioButton(Difficulty);
        buttonGroup_2->addButton(radioButton_11);
        radioButton_11->setObjectName(QStringLiteral("radioButton_11"));
        radioButton_11->setGeometry(QRect(190, 220, 141, 28));
        label_2 = new QLabel(Difficulty);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 141, 24));
        layoutWidget = new QWidget(Difficulty);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 360, 311, 47));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_3->addWidget(pushButton_4);

        radioButton_5 = new QRadioButton(Difficulty);
        buttonGroup->addButton(radioButton_5);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(190, 100, 91, 28));
        radioButton_5->setChecked(true);
        radioButton_9 = new QRadioButton(Difficulty);
        buttonGroup_2->addButton(radioButton_9);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        radioButton_9->setGeometry(QRect(190, 180, 131, 28));
        radioButton_9->setChecked(true);
        label_4 = new QLabel(Difficulty);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 270, 151, 24));
        radioButton_8 = new QRadioButton(Difficulty);
        buttonGroup->addButton(radioButton_8);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setGeometry(QRect(360, 140, 161, 28));
        radioButton_12 = new QRadioButton(Difficulty);
        buttonGroup_2->addButton(radioButton_12);
        radioButton_12->setObjectName(QStringLiteral("radioButton_12"));
        radioButton_12->setGeometry(QRect(360, 220, 141, 28));

        retranslateUi(Difficulty);

        QMetaObject::connectSlotsByName(Difficulty);
    } // setupUi

    void retranslateUi(QDialog *Difficulty)
    {
        Difficulty->setWindowTitle(QApplication::translate("Difficulty", "Difficulty", 0));
        radioButton_10->setText(QApplication::translate("Difficulty", "5 Reborn", 0));
        radioButton_13->setText(QApplication::translate("Difficulty", "Read One", 0));
        radioButton_14->setText(QApplication::translate("Difficulty", "Yellow One", 0));
        radioButton_6->setText(QApplication::translate("Difficulty", "Ordinary", 0));
        radioButton_7->setText(QApplication::translate("Difficulty", "Difficult", 0));
        label_3->setText(QApplication::translate("Difficulty", "Reborn Time:", 0));
        label->setText(QApplication::translate("Difficulty", "<html><head/><body><p><span style=\" font-size:12pt;\">Difficulty Setting</span></p></body></html>", 0));
        radioButton_11->setText(QApplication::translate("Difficulty", "7 Reborn", 0));
        label_2->setText(QApplication::translate("Difficulty", "Difficulty:", 0));
        pushButton_3->setText(QApplication::translate("Difficulty", "OK", 0));
        pushButton_4->setText(QApplication::translate("Difficulty", "Cancel", 0));
        radioButton_5->setText(QApplication::translate("Difficulty", "Easy", 0));
        radioButton_9->setText(QApplication::translate("Difficulty", "3 Reborn", 0));
        label_4->setText(QApplication::translate("Difficulty", "Initial Bomb:", 0));
        radioButton_8->setText(QApplication::translate("Difficulty", "Nightmare", 0));
        radioButton_12->setText(QApplication::translate("Difficulty", "9 Reborn", 0));
    } // retranslateUi

};

namespace Ui {
    class Difficulty: public Ui_Difficulty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTY_H
