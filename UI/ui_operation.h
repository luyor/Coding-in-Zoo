/********************************************************************************
** Form generated from reading UI file 'operation.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATION_H
#define UI_OPERATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Operation
{
public:
    QFrame *line_3;
    QLineEdit *lineEdit_4;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QDial *dial;
    QFrame *line_2;
    QComboBox *comboBox;
    QFrame *line;
    QFrame *line_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_10;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_11;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QCheckBox *checkBox_3;
    QLineEdit *lineEdit_11;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;

    void setupUi(QDialog *Operation)
    {
        if (Operation->objectName().isEmpty())
            Operation->setObjectName(QStringLiteral("Operation"));
        Operation->resize(557, 440);
        line_3 = new QFrame(Operation);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(320, 270, 71, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        lineEdit_4 = new QLineEdit(Operation);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(380, 180, 41, 31));
        lineEdit_4->setAlignment(Qt::AlignCenter);

        layoutWidget_3 = new QWidget(Operation);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 330, 311, 47));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(layoutWidget_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout_12->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(layoutWidget_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        horizontalLayout_12->addWidget(pushButton_9);

        dial = new QDial(Operation);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(380, 250, 50, 64));
        line_2 = new QFrame(Operation);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(380, 300, 61, 61));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        comboBox = new QComboBox(Operation);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(30, 60, 130, 41));
        line = new QFrame(Operation);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(370, 210, 61, 61));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Operation);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(420, 280, 71, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(Operation);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 130, 191, 173));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(9);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_13->addWidget(label_9);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        horizontalLayout_13->addWidget(lineEdit_8);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(9);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_14->addWidget(label_10);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        horizontalLayout_14->addWidget(lineEdit_9);


        verticalLayout_6->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(9);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_15->addWidget(label_11);

        lineEdit_10 = new QLineEdit(layoutWidget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        horizontalLayout_15->addWidget(lineEdit_10);


        verticalLayout_6->addLayout(horizontalLayout_15);


        verticalLayout_5->addLayout(verticalLayout_6);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_16->addWidget(label_12);

        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setContextMenuPolicy(Qt::NoContextMenu);
        checkBox_3->setAcceptDrops(false);
        checkBox_3->setChecked(true);
        checkBox_3->setTristate(false);

        horizontalLayout_16->addWidget(checkBox_3);


        verticalLayout_5->addLayout(horizontalLayout_16);

        lineEdit_11 = new QLineEdit(Operation);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(390, 360, 41, 31));
        pushButton_3 = new QPushButton(Operation);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 60, 201, 45));
        lineEdit_12 = new QLineEdit(Operation);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(490, 280, 41, 31));
        lineEdit_13 = new QLineEdit(Operation);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(280, 270, 41, 31));

        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_8->setAlignment(Qt::AlignCenter);
        lineEdit_9->setAlignment(Qt::AlignCenter);
        lineEdit_10->setAlignment(Qt::AlignCenter);
        lineEdit_11->setAlignment(Qt::AlignCenter);
        lineEdit_12->setAlignment(Qt::AlignCenter);
        lineEdit_13->setAlignment(Qt::AlignCenter);


        retranslateUi(Operation);

        QMetaObject::connectSlotsByName(Operation);
    } // setupUi

    void retranslateUi(QDialog *Operation)
    {
        Operation->setWindowTitle(QApplication::translate("Operation", "Operation", 0));
        lineEdit_4->setText(QApplication::translate("Operation", "W", 0));
        pushButton_8->setText(QApplication::translate("Operation", "OK", 0));
        pushButton_9->setText(QApplication::translate("Operation", "Cancel", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Operation", "Keyboard", 0)
         << QApplication::translate("Operation", "Joypad", 0)
        );
        label_9->setText(QApplication::translate("Operation", "Fire(F)", 0));
        lineEdit_8->setText(QApplication::translate("Operation", ",", 0));
        label_10->setText(QApplication::translate("Operation", "Bomb(B)", 0));
        lineEdit_9->setText(QApplication::translate("Operation", ".", 0));
        label_11->setText(QApplication::translate("Operation", "Start(S)", 0));
        lineEdit_10->setText(QApplication::translate("Operation", "Space", 0));
        label_12->setText(QApplication::translate("Operation", "Laster Fire", 0));
        checkBox_3->setText(QString());
        lineEdit_11->setText(QApplication::translate("Operation", "S", 0));
        pushButton_3->setText(QApplication::translate("Operation", "DefaultSetting", 0));
        lineEdit_12->setText(QApplication::translate("Operation", "D", 0));
        lineEdit_13->setText(QApplication::translate("Operation", "A", 0));
    } // retranslateUi

};

namespace Ui {
    class Operation: public Ui_Operation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATION_H
