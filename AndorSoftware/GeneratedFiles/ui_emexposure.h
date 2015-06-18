/********************************************************************************
** Form generated from reading UI file 'emexposure.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMEXPOSURE_H
#define UI_EMEXPOSURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_EMExposureClass
{
public:
    QSlider *verticalSlider_EM;
    QSlider *verticalSlider_Exposure;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;
    QLineEdit *lineEdit_EM;
    QLineEdit *lineEdit_Exposure;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_EM2;
    QLabel *label_EM1;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *checkBox_EM;

    void setupUi(QDialog *EMExposureClass)
    {
        if (EMExposureClass->objectName().isEmpty())
            EMExposureClass->setObjectName(QStringLiteral("EMExposureClass"));
        EMExposureClass->resize(240, 390);
        QIcon icon;
        icon.addFile(QStringLiteral(":/EMExposure/Resources/EM.png"), QSize(), QIcon::Normal, QIcon::Off);
        EMExposureClass->setWindowIcon(icon);
        verticalSlider_EM = new QSlider(EMExposureClass);
        verticalSlider_EM->setObjectName(QStringLiteral("verticalSlider_EM"));
        verticalSlider_EM->setGeometry(QRect(47, 79, 19, 211));
        verticalSlider_EM->setOrientation(Qt::Vertical);
        verticalSlider_Exposure = new QSlider(EMExposureClass);
        verticalSlider_Exposure->setObjectName(QStringLiteral("verticalSlider_Exposure"));
        verticalSlider_Exposure->setGeometry(QRect(141, 79, 21, 211));
        verticalSlider_Exposure->setOrientation(Qt::Vertical);
        pushButton_OK = new QPushButton(EMExposureClass);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(112, 350, 51, 23));
        pushButton_Cancel = new QPushButton(EMExposureClass);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(170, 350, 51, 23));
        lineEdit_EM = new QLineEdit(EMExposureClass);
        lineEdit_EM->setObjectName(QStringLiteral("lineEdit_EM"));
        lineEdit_EM->setGeometry(QRect(27, 309, 61, 20));
        lineEdit_Exposure = new QLineEdit(EMExposureClass);
        lineEdit_Exposure->setObjectName(QStringLiteral("lineEdit_Exposure"));
        lineEdit_Exposure->setGeometry(QRect(127, 309, 61, 20));
        label = new QLabel(EMExposureClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(47, 40, 41, 21));
        label_2 = new QLabel(EMExposureClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 40, 51, 21));
        label_EM2 = new QLabel(EMExposureClass);
        label_EM2->setObjectName(QStringLiteral("label_EM2"));
        label_EM2->setGeometry(QRect(70, 70, 31, 21));
        label_EM1 = new QLabel(EMExposureClass);
        label_EM1->setObjectName(QStringLiteral("label_EM1"));
        label_EM1->setGeometry(QRect(70, 260, 31, 21));
        label_5 = new QLabel(EMExposureClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(171, 71, 24, 16));
        label_6 = new QLabel(EMExposureClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(171, 262, 20, 20));
        checkBox_EM = new QCheckBox(EMExposureClass);
        checkBox_EM->setObjectName(QStringLiteral("checkBox_EM"));
        checkBox_EM->setGeometry(QRect(30, 350, 71, 21));

        retranslateUi(EMExposureClass);

        QMetaObject::connectSlotsByName(EMExposureClass);
    } // setupUi

    void retranslateUi(QDialog *EMExposureClass)
    {
        EMExposureClass->setWindowTitle(QApplication::translate("EMExposureClass", "EMExposure", 0));
        pushButton_OK->setText(QApplication::translate("EMExposureClass", "OK", 0));
        pushButton_Cancel->setText(QApplication::translate("EMExposureClass", "Cancel", 0));
        label->setText(QApplication::translate("EMExposureClass", "EM", 0));
        label_2->setText(QApplication::translate("EMExposureClass", "Exposure", 0));
        label_EM2->setText(QString());
        label_EM1->setText(QString());
        label_5->setText(QApplication::translate("EMExposureClass", "1000", 0));
        label_6->setText(QApplication::translate("EMExposureClass", "0", 0));
        checkBox_EM->setText(QApplication::translate("EMExposureClass", "EM", 0));
    } // retranslateUi

};

namespace Ui {
    class EMExposureClass: public Ui_EMExposureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMEXPOSURE_H
