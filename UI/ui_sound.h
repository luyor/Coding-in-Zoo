/********************************************************************************
** Form generated from reading UI file 'sound.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUND_H
#define UI_SOUND_H

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

class Ui_Sound
{
public:
    QCheckBox *checkBox;
    QSlider *verticalSlider;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QCheckBox *checkBox_2;
    QSlider *verticalSlider_2;

    void setupUi(QDialog *Sound)
    {
        if (Sound->objectName().isEmpty())
            Sound->setObjectName(QStringLiteral("Sound"));
        Sound->resize(557, 440);
        checkBox = new QCheckBox(Sound);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(40, 290, 221, 41));
        checkBox->setChecked(true);
        verticalSlider = new QSlider(Sound);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(110, 100, 41, 171));
        verticalSlider->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(Sound);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 360, 311, 47));
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

        label = new QLabel(Sound);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 271, 81));
        checkBox_2 = new QCheckBox(Sound);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(340, 296, 161, 28));
        checkBox_2->setChecked(true);
        verticalSlider_2 = new QSlider(Sound);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(380, 100, 41, 171));
        verticalSlider_2->setOrientation(Qt::Vertical);

        retranslateUi(Sound);

        QMetaObject::connectSlotsByName(Sound);
    } // setupUi

    void retranslateUi(QDialog *Sound)
    {
        Sound->setWindowTitle(QApplication::translate("Sound", "Sound", 0));
        checkBox->setText(QApplication::translate("Sound", "Background Sound", 0));
        pushButton->setText(QApplication::translate("Sound", "OK", 0));
        pushButton_2->setText(QApplication::translate("Sound", "Cancel", 0));
        label->setText(QApplication::translate("Sound", "<html><head/><body><p><span style=\" font-size:16pt;\">Sound Effect</span></p></body></html>", 0));
        checkBox_2->setText(QApplication::translate("Sound", "Bomb Sound", 0));
    } // retranslateUi

};

namespace Ui {
    class Sound: public Ui_Sound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUND_H
