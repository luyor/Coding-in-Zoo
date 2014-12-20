/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Sound
{
public:
    QSlider *verticalSlider_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSlider *verticalSlider;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(557, 440);
        verticalSlider_3 = new QSlider(Dialog);
        verticalSlider_3->setObjectName(QStringLiteral("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(390, 100, 41, 171));
        verticalSlider_3->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 360, 311, 47));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        verticalSlider = new QSlider(Dialog);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(120, 100, 41, 171));
        verticalSlider->setOrientation(Qt::Vertical);
        checkBox_2 = new QCheckBox(Dialog);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(350, 296, 161, 28));
        checkBox = new QCheckBox(Dialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(50, 290, 221, 41));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 271, 81));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "SoundSetting", 0));
        pushButton->setText(QApplication::translate("Dialog", "OK", 0));
        pushButton_2->setText(QApplication::translate("Dialog", "Cancel", 0));
        checkBox_2->setText(QApplication::translate("Dialog", "Bomb Sound", 0));
        checkBox->setText(QApplication::translate("Dialog", "Background Sound", 0));
        label->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:16pt;\">Sound Effect</span></p></body></html>", 0));
    } // retranslateUi

};


class soundUI : public QDialog,private Ui_Dialog_Sound
{
public:
    soundUI();
};



namespace Ui {
    class Dialog_Sound: public Ui_Dialog_Sound {};
} // namespace Ui

QT_END_NAMESPACE

#endif
