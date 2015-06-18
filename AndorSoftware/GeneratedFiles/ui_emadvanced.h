/********************************************************************************
** Form generated from reading UI file 'emadvanced.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMADVANCED_H
#define UI_EMADVANCED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_EMAdvancedClass
{
public:
    QLabel *label_Dispaly;
    QCheckBox *checkBox_Advanced_EM;

    void setupUi(QDialog *EMAdvancedClass)
    {
        if (EMAdvancedClass->objectName().isEmpty())
            EMAdvancedClass->setObjectName(QStringLiteral("EMAdvancedClass"));
        EMAdvancedClass->resize(430, 269);
        QFont font;
        font.setPointSize(9);
        EMAdvancedClass->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/EMAdvanced/Resources/xidian2.png"), QSize(), QIcon::Normal, QIcon::Off);
        EMAdvancedClass->setWindowIcon(icon);
        label_Dispaly = new QLabel(EMAdvancedClass);
        label_Dispaly->setObjectName(QStringLiteral("label_Dispaly"));
        label_Dispaly->setGeometry(QRect(20, 30, 351, 141));
        QFont font1;
        font1.setPointSize(10);
        label_Dispaly->setFont(font1);
        label_Dispaly->setCursor(QCursor(Qt::SizeAllCursor));
        checkBox_Advanced_EM = new QCheckBox(EMAdvancedClass);
        checkBox_Advanced_EM->setObjectName(QStringLiteral("checkBox_Advanced_EM"));
        checkBox_Advanced_EM->setGeometry(QRect(120, 190, 181, 31));

        retranslateUi(EMAdvancedClass);

        QMetaObject::connectSlotsByName(EMAdvancedClass);
    } // setupUi

    void retranslateUi(QDialog *EMAdvancedClass)
    {
        EMAdvancedClass->setWindowTitle(QApplication::translate("EMAdvancedClass", "EMAdvanced", 0));
        label_Dispaly->setText(QApplication::translate("EMAdvancedClass", "TextLabel", 0));
        checkBox_Advanced_EM->setText(QApplication::translate("EMAdvancedClass", "Enable high gain levels", 0));
    } // retranslateUi

};

namespace Ui {
    class EMAdvancedClass: public Ui_EMAdvancedClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMADVANCED_H
