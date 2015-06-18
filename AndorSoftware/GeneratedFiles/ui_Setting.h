/********************************************************************************
** Form generated from reading UI file 'Setting.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingClass
{
public:
    QLineEdit *lineEdit_ExposureTime;
    QComboBox *comboBox_AcquisitionMode;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_Binning1;
    QLabel *label_3;
    QLineEdit *lineEdit_Binning2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_Binning1;
    QRadioButton *radioButton_Binning2;
    QRadioButton *radioButton_Binning4;
    QRadioButton *radioButton_Binning8;
    QRadioButton *radioButton_Binning16;
    QRadioButton *radioButton_BinningCustom;
    QLabel *label_5;
    QComboBox *comboBox_TriggerMode;
    QComboBox *comboBox_Shutter;
    QLabel *label_4;
    QLabel *label;
    QSplitter *splitter;
    QPushButton *pushButton_SetAcqParameter;
    QPushButton *pushButton_CancelAcqParameter;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_EMEnable;
    QPushButton *pushButton_EMAdvanced;
    QLabel *label_10;
    QSpinBox *spinBox_EMRange;
    QGroupBox *groupBox_5;
    QRadioButton *radioButton_Kinetic2;
    QGroupBox *groupBox_4;
    QLabel *label_8;
    QLineEdit *lineEdit_KineticCycleTime_2;
    QLabel *label_9;
    QLineEdit *lineEdit_KineticNumber;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_KineticTime;
    QLineEdit *lineEdit_KineticCycleTime;
    QLabel *label_7;
    QLabel *label_6;
    QRadioButton *radioButton_Kinetic1;

    void setupUi(QWidget *settingClass)
    {
        if (settingClass->objectName().isEmpty())
            settingClass->setObjectName(QStringLiteral("settingClass"));
        settingClass->resize(691, 672);
        settingClass->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/setting/Resources/xidian1.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingClass->setWindowIcon(icon);
        lineEdit_ExposureTime = new QLineEdit(settingClass);
        lineEdit_ExposureTime->setObjectName(QStringLiteral("lineEdit_ExposureTime"));
        lineEdit_ExposureTime->setGeometry(QRect(157, 96, 121, 20));
        comboBox_AcquisitionMode = new QComboBox(settingClass);
        comboBox_AcquisitionMode->setObjectName(QStringLiteral("comboBox_AcquisitionMode"));
        comboBox_AcquisitionMode->setGeometry(QRect(18, 34, 131, 31));
        comboBox_AcquisitionMode->setEditable(false);
        groupBox = new QGroupBox(settingClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(338, 64, 271, 231));
        lineEdit_Binning1 = new QLineEdit(groupBox);
        lineEdit_Binning1->setObjectName(QStringLiteral("lineEdit_Binning1"));
        lineEdit_Binning1->setGeometry(QRect(9, 150, 41, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(58, 150, 16, 20));
        lineEdit_Binning2 = new QLineEdit(groupBox);
        lineEdit_Binning2->setObjectName(QStringLiteral("lineEdit_Binning2"));
        lineEdit_Binning2->setGeometry(QRect(70, 150, 41, 20));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 111, 128));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_Binning1 = new QRadioButton(layoutWidget);
        radioButton_Binning1->setObjectName(QStringLiteral("radioButton_Binning1"));

        verticalLayout->addWidget(radioButton_Binning1);

        radioButton_Binning2 = new QRadioButton(layoutWidget);
        radioButton_Binning2->setObjectName(QStringLiteral("radioButton_Binning2"));

        verticalLayout->addWidget(radioButton_Binning2);

        radioButton_Binning4 = new QRadioButton(layoutWidget);
        radioButton_Binning4->setObjectName(QStringLiteral("radioButton_Binning4"));

        verticalLayout->addWidget(radioButton_Binning4);

        radioButton_Binning8 = new QRadioButton(layoutWidget);
        radioButton_Binning8->setObjectName(QStringLiteral("radioButton_Binning8"));

        verticalLayout->addWidget(radioButton_Binning8);

        radioButton_Binning16 = new QRadioButton(layoutWidget);
        radioButton_Binning16->setObjectName(QStringLiteral("radioButton_Binning16"));

        verticalLayout->addWidget(radioButton_Binning16);

        radioButton_BinningCustom = new QRadioButton(layoutWidget);
        radioButton_BinningCustom->setObjectName(QStringLiteral("radioButton_BinningCustom"));

        verticalLayout->addWidget(radioButton_BinningCustom);

        label_5 = new QLabel(settingClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 153, 114, 16));
        comboBox_TriggerMode = new QComboBox(settingClass);
        comboBox_TriggerMode->setObjectName(QStringLiteral("comboBox_TriggerMode"));
        comboBox_TriggerMode->setGeometry(QRect(158, 210, 81, 20));
        comboBox_Shutter = new QComboBox(settingClass);
        comboBox_Shutter->setObjectName(QStringLiteral("comboBox_Shutter"));
        comboBox_Shutter->setGeometry(QRect(158, 153, 81, 20));
        label_4 = new QLabel(settingClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 96, 132, 16));
        label = new QLabel(settingClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(18, 4, 121, 21));
        splitter = new QSplitter(settingClass);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(400, 560, 161, 31));
        splitter->setOrientation(Qt::Horizontal);
        pushButton_SetAcqParameter = new QPushButton(splitter);
        pushButton_SetAcqParameter->setObjectName(QStringLiteral("pushButton_SetAcqParameter"));
        splitter->addWidget(pushButton_SetAcqParameter);
        pushButton_CancelAcqParameter = new QPushButton(splitter);
        pushButton_CancelAcqParameter->setObjectName(QStringLiteral("pushButton_CancelAcqParameter"));
        splitter->addWidget(pushButton_CancelAcqParameter);
        label_2 = new QLabel(settingClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 210, 103, 20));
        groupBox_3 = new QGroupBox(settingClass);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(340, 330, 271, 121));
        checkBox_EMEnable = new QCheckBox(groupBox_3);
        checkBox_EMEnable->setObjectName(QStringLiteral("checkBox_EMEnable"));
        checkBox_EMEnable->setGeometry(QRect(10, 30, 71, 21));
        pushButton_EMAdvanced = new QPushButton(groupBox_3);
        pushButton_EMAdvanced->setObjectName(QStringLiteral("pushButton_EMAdvanced"));
        pushButton_EMAdvanced->setGeometry(QRect(195, 23, 71, 31));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 80, 181, 21));
        spinBox_EMRange = new QSpinBox(groupBox_3);
        spinBox_EMRange->setObjectName(QStringLiteral("spinBox_EMRange"));
        spinBox_EMRange->setGeometry(QRect(201, 80, 61, 21));
        spinBox_EMRange->setMaximum(1000);
        groupBox_5 = new QGroupBox(settingClass);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 260, 311, 311));
        radioButton_Kinetic2 = new QRadioButton(groupBox_5);
        radioButton_Kinetic2->setObjectName(QStringLiteral("radioButton_Kinetic2"));
        radioButton_Kinetic2->setGeometry(QRect(10, 160, 141, 21));
        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 180, 291, 121));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(12, 23, 126, 16));
        lineEdit_KineticCycleTime_2 = new QLineEdit(groupBox_4);
        lineEdit_KineticCycleTime_2->setObjectName(QStringLiteral("lineEdit_KineticCycleTime_2"));
        lineEdit_KineticCycleTime_2->setGeometry(QRect(150, 23, 121, 20));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(12, 80, 131, 16));
        lineEdit_KineticNumber = new QLineEdit(groupBox_4);
        lineEdit_KineticNumber->setObjectName(QStringLiteral("lineEdit_KineticNumber"));
        lineEdit_KineticNumber->setGeometry(QRect(150, 80, 121, 20));
        groupBox_2 = new QGroupBox(groupBox_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 40, 291, 111));
        lineEdit_KineticTime = new QLineEdit(groupBox_2);
        lineEdit_KineticTime->setObjectName(QStringLiteral("lineEdit_KineticTime"));
        lineEdit_KineticTime->setGeometry(QRect(150, 80, 121, 20));
        lineEdit_KineticCycleTime = new QLineEdit(groupBox_2);
        lineEdit_KineticCycleTime->setObjectName(QStringLiteral("lineEdit_KineticCycleTime"));
        lineEdit_KineticCycleTime->setGeometry(QRect(150, 23, 121, 20));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(12, 80, 90, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(12, 23, 126, 16));
        radioButton_Kinetic1 = new QRadioButton(groupBox_5);
        radioButton_Kinetic1->setObjectName(QStringLiteral("radioButton_Kinetic1"));
        radioButton_Kinetic1->setGeometry(QRect(10, 20, 161, 16));

        retranslateUi(settingClass);

        QMetaObject::connectSlotsByName(settingClass);
    } // setupUi

    void retranslateUi(QWidget *settingClass)
    {
        settingClass->setWindowTitle(QApplication::translate("settingClass", "\350\256\276\347\275\256", 0));
        comboBox_AcquisitionMode->clear();
        comboBox_AcquisitionMode->insertItems(0, QStringList()
         << QApplication::translate("settingClass", "Single", 0)
         << QApplication::translate("settingClass", "Kinetic", 0)
         << QApplication::translate("settingClass", "Video", 0)
        );
        groupBox->setTitle(QApplication::translate("settingClass", "Binning \357\274\232", 0));
        label_3->setText(QApplication::translate("settingClass", "*", 0));
        radioButton_Binning1->setText(QApplication::translate("settingClass", "1*1", 0));
        radioButton_Binning2->setText(QApplication::translate("settingClass", "2*2", 0));
        radioButton_Binning4->setText(QApplication::translate("settingClass", "4*4", 0));
        radioButton_Binning8->setText(QApplication::translate("settingClass", "8*8", 0));
        radioButton_Binning16->setText(QApplication::translate("settingClass", "16*16", 0));
        radioButton_BinningCustom->setText(QApplication::translate("settingClass", "Custom", 0));
        label_5->setText(QApplication::translate("settingClass", "Shutter Opens On \357\274\232", 0));
        comboBox_TriggerMode->clear();
        comboBox_TriggerMode->insertItems(0, QStringList()
         << QApplication::translate("settingClass", "0", 0)
         << QApplication::translate("settingClass", "1", 0)
         << QApplication::translate("settingClass", "2", 0)
        );
        comboBox_Shutter->clear();
        comboBox_Shutter->insertItems(0, QStringList()
         << QApplication::translate("settingClass", "ON", 0)
         << QApplication::translate("settingClass", "OFF", 0)
        );
        label_4->setText(QApplication::translate("settingClass", "Exposure Time[secs] \357\274\232", 0));
        label->setText(QApplication::translate("settingClass", "Acquisition Mode \357\274\232", 0));
        pushButton_SetAcqParameter->setText(QApplication::translate("settingClass", "\347\241\256\345\256\232", 0));
        pushButton_CancelAcqParameter->setText(QApplication::translate("settingClass", "\345\217\226\346\266\210", 0));
        label_2->setText(QApplication::translate("settingClass", "Triggering Mode \357\274\232", 0));
        groupBox_3->setTitle(QApplication::translate("settingClass", "Electron Multiplier (EM) Gain", 0));
        checkBox_EMEnable->setText(QApplication::translate("settingClass", "Enable", 0));
        pushButton_EMAdvanced->setText(QApplication::translate("settingClass", "Advanced", 0));
        label_10->setText(QApplication::translate("settingClass", "Electron Multiplier Gain Level", 0));
        groupBox_5->setTitle(QApplication::translate("settingClass", "Kinetic \357\274\232", 0));
        radioButton_Kinetic2->setText(QApplication::translate("settingClass", "Kinetic Mode 2 \357\274\232", 0));
        groupBox_4->setTitle(QString());
        label_8->setText(QApplication::translate("settingClass", "Kinetic Cycle Time \357\274\232", 0));
        label_9->setText(QApplication::translate("settingClass", "The number Kinetic \357\274\232", 0));
        groupBox_2->setTitle(QString());
        label_7->setText(QApplication::translate("settingClass", "Kinetic Time \357\274\232", 0));
        label_6->setText(QApplication::translate("settingClass", "Kinetic Cycle Time \357\274\232", 0));
        radioButton_Kinetic1->setText(QApplication::translate("settingClass", "Kinetic Mode 1 \357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class settingClass: public Ui_settingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
