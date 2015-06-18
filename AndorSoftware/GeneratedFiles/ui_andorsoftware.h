/********************************************************************************
** Form generated from reading UI file 'andorsoftware.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANDORSOFTWARE_H
#define UI_ANDORSOFTWARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AndorSoftwareClass
{
public:
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Exit;
    QAction *action_SetParameter;
    QAction *action_SingleAcquisition;
    QAction *action_KineticAcquisition;
    QAction *action_VideoAcquisition;
    QAction *action_About;
    QAction *action_QT;
    QAction *action_Help;
    QAction *action_Stop;
    QAction *action_EMExposure;
    QAction *action_scan3d_capture;
    QAction *action_CT;
    QAction *actionPET;
    QWidget *centralWidget;
    QLineEdit *lineEdit_TempSetting;
    QLabel *label_DisplayTemp;
    QSplitter *splitter;
    QLabel *label_2;
    QSpinBox *spinBox_ChoseImage;
    QPushButton *pushButton_CoolerOn;
    QPushButton *pushButton_CoolerOff;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit_AndorStatus;
    QGroupBox *groupBox_1;
    QTextEdit *textEdit_Information;
    QGroupBox *groupBox_3;
    QLabel *label_DisplayImage;
    QLabel *label_1;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu;
    QMenu *menu_H;
    QMenu *menu_2;
    QMenu *menuCT;
    QMenu *menuPET;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AndorSoftwareClass)
    {
        if (AndorSoftwareClass->objectName().isEmpty())
            AndorSoftwareClass->setObjectName(QStringLiteral("AndorSoftwareClass"));
        AndorSoftwareClass->resize(1010, 792);
        QIcon icon;
        icon.addFile(QStringLiteral(":/AndorSoftware/Resources/xidian.png"), QSize(), QIcon::Normal, QIcon::Off);
        AndorSoftwareClass->setWindowIcon(icon);
        action_Open = new QAction(AndorSoftwareClass);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/AndorSoftware/Resources/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Save = new QAction(AndorSoftwareClass);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/AndorSoftware/Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon2);
        action_Exit = new QAction(AndorSoftwareClass);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        action_SetParameter = new QAction(AndorSoftwareClass);
        action_SetParameter->setObjectName(QStringLiteral("action_SetParameter"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/AndorSoftware/Resources/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SetParameter->setIcon(icon3);
        action_SingleAcquisition = new QAction(AndorSoftwareClass);
        action_SingleAcquisition->setObjectName(QStringLiteral("action_SingleAcquisition"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/AndorSoftware/Resources/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SingleAcquisition->setIcon(icon4);
        action_KineticAcquisition = new QAction(AndorSoftwareClass);
        action_KineticAcquisition->setObjectName(QStringLiteral("action_KineticAcquisition"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/AndorSoftware/Resources/ContinuousShooting.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_KineticAcquisition->setIcon(icon5);
        action_VideoAcquisition = new QAction(AndorSoftwareClass);
        action_VideoAcquisition->setObjectName(QStringLiteral("action_VideoAcquisition"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/AndorSoftware/Resources/video.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_VideoAcquisition->setIcon(icon6);
        action_About = new QAction(AndorSoftwareClass);
        action_About->setObjectName(QStringLiteral("action_About"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/AndorSoftware/Resources/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_About->setIcon(icon7);
        action_QT = new QAction(AndorSoftwareClass);
        action_QT->setObjectName(QStringLiteral("action_QT"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/AndorSoftware/Resources/aboutqt.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_QT->setIcon(icon8);
        action_Help = new QAction(AndorSoftwareClass);
        action_Help->setObjectName(QStringLiteral("action_Help"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/AndorSoftware/Resources/Help.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Help->setIcon(icon9);
        action_Stop = new QAction(AndorSoftwareClass);
        action_Stop->setObjectName(QStringLiteral("action_Stop"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/AndorSoftware/Resources/abort.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Stop->setIcon(icon10);
        action_EMExposure = new QAction(AndorSoftwareClass);
        action_EMExposure->setObjectName(QStringLiteral("action_EMExposure"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/AndorSoftware/Resources/EM.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_EMExposure->setIcon(icon11);
        action_scan3d_capture = new QAction(AndorSoftwareClass);
        action_scan3d_capture->setObjectName(QStringLiteral("action_scan3d_capture"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/AndorSoftware/Resources/ImageProcessing.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_scan3d_capture->setIcon(icon12);
        action_CT = new QAction(AndorSoftwareClass);
        action_CT->setObjectName(QStringLiteral("action_CT"));
        actionPET = new QAction(AndorSoftwareClass);
        actionPET->setObjectName(QStringLiteral("actionPET"));
        centralWidget = new QWidget(AndorSoftwareClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_TempSetting = new QLineEdit(centralWidget);
        lineEdit_TempSetting->setObjectName(QStringLiteral("lineEdit_TempSetting"));
        lineEdit_TempSetting->setGeometry(QRect(158, 621, 133, 31));
        label_DisplayTemp = new QLabel(centralWidget);
        label_DisplayTemp->setObjectName(QStringLiteral("label_DisplayTemp"));
        label_DisplayTemp->setGeometry(QRect(158, 667, 131, 41));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(560, 630, 281, 31));
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter->addWidget(label_2);
        spinBox_ChoseImage = new QSpinBox(splitter);
        spinBox_ChoseImage->setObjectName(QStringLiteral("spinBox_ChoseImage"));
        splitter->addWidget(spinBox_ChoseImage);
        pushButton_CoolerOn = new QPushButton(centralWidget);
        pushButton_CoolerOn->setObjectName(QStringLiteral("pushButton_CoolerOn"));
        pushButton_CoolerOn->setGeometry(QRect(311, 622, 75, 31));
        pushButton_CoolerOff = new QPushButton(centralWidget);
        pushButton_CoolerOff->setObjectName(QStringLiteral("pushButton_CoolerOff"));
        pushButton_CoolerOff->setGeometry(QRect(311, 670, 75, 31));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 380, 381, 211));
        textEdit_AndorStatus = new QTextEdit(groupBox_2);
        textEdit_AndorStatus->setObjectName(QStringLiteral("textEdit_AndorStatus"));
        textEdit_AndorStatus->setGeometry(QRect(10, 20, 361, 181));
        textEdit_AndorStatus->setUndoRedoEnabled(true);
        textEdit_AndorStatus->setReadOnly(true);
        textEdit_AndorStatus->setAcceptRichText(true);
        groupBox_1 = new QGroupBox(centralWidget);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        groupBox_1->setGeometry(QRect(10, 10, 381, 371));
        textEdit_Information = new QTextEdit(groupBox_1);
        textEdit_Information->setObjectName(QStringLiteral("textEdit_Information"));
        textEdit_Information->setGeometry(QRect(10, 20, 361, 311));
        textEdit_Information->setReadOnly(true);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(400, 10, 591, 591));
        label_DisplayImage = new QLabel(groupBox_3);
        label_DisplayImage->setObjectName(QStringLiteral("label_DisplayImage"));
        label_DisplayImage->setGeometry(QRect(10, 20, 564, 564));
        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(7, 621, 132, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(7, 669, 132, 31));
        AndorSoftwareClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AndorSoftwareClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1010, 23));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menuCT = new QMenu(menuBar);
        menuCT->setObjectName(QStringLiteral("menuCT"));
        menuPET = new QMenu(menuBar);
        menuPET->setObjectName(QStringLiteral("menuPET"));
        AndorSoftwareClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AndorSoftwareClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AndorSoftwareClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AndorSoftwareClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AndorSoftwareClass->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuCT->menuAction());
        menuBar->addAction(menuPET->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(action_Open);
        menu_F->addSeparator();
        menu_F->addAction(action_Save);
        menu_F->addSeparator();
        menu_F->addAction(action_Exit);
        menu_E->addAction(action_SetParameter);
        menu->addAction(action_SingleAcquisition);
        menu->addAction(action_KineticAcquisition);
        menu->addAction(action_VideoAcquisition);
        menu->addSeparator();
        menu->addAction(action_Stop);
        menu_H->addAction(action_About);
        menu_H->addAction(action_QT);
        menu_H->addAction(action_Help);
        menu_2->addAction(action_scan3d_capture);
        menuCT->addAction(action_CT);
        menuPET->addAction(actionPET);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_SetParameter);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_EMExposure);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_SingleAcquisition);
        mainToolBar->addAction(action_KineticAcquisition);
        mainToolBar->addAction(action_VideoAcquisition);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Stop);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_scan3d_capture);

        retranslateUi(AndorSoftwareClass);

        QMetaObject::connectSlotsByName(AndorSoftwareClass);
    } // setupUi

    void retranslateUi(QMainWindow *AndorSoftwareClass)
    {
        AndorSoftwareClass->setWindowTitle(QApplication::translate("AndorSoftwareClass", "OPTICAL", 0));
        action_Open->setText(QApplication::translate("AndorSoftwareClass", "\346\211\223\345\274\200(&O)", 0));
        action_Open->setShortcut(QApplication::translate("AndorSoftwareClass", "Ctrl+O", 0));
        action_Save->setText(QApplication::translate("AndorSoftwareClass", "\344\277\235\345\255\230(&S)", 0));
        action_Save->setShortcut(QApplication::translate("AndorSoftwareClass", "Ctrl+S", 0));
        action_Exit->setText(QApplication::translate("AndorSoftwareClass", "\351\200\200\345\207\272(&X)", 0));
        action_Exit->setShortcut(QApplication::translate("AndorSoftwareClass", "Ctrl+X", 0));
        action_SetParameter->setText(QApplication::translate("AndorSoftwareClass", "\350\256\276\347\275\256(&P)", 0));
        action_SetParameter->setShortcut(QApplication::translate("AndorSoftwareClass", "Ctrl+P", 0));
        action_SingleAcquisition->setText(QApplication::translate("AndorSoftwareClass", "\345\215\225\346\213\215(&F5) ", 0));
        action_SingleAcquisition->setShortcut(QApplication::translate("AndorSoftwareClass", "F5", 0));
        action_KineticAcquisition->setText(QApplication::translate("AndorSoftwareClass", "\350\277\236\346\213\215(&F6) ", 0));
        action_KineticAcquisition->setShortcut(QApplication::translate("AndorSoftwareClass", "F6", 0));
        action_VideoAcquisition->setText(QApplication::translate("AndorSoftwareClass", "\350\247\206\351\242\221(&F7) ", 0));
        action_VideoAcquisition->setShortcut(QApplication::translate("AndorSoftwareClass", "F7", 0));
        action_About->setText(QApplication::translate("AndorSoftwareClass", "\345\205\263\344\272\216(&F1)", 0));
        action_About->setShortcut(QApplication::translate("AndorSoftwareClass", "F1", 0));
        action_QT->setText(QApplication::translate("AndorSoftwareClass", "\345\205\263\344\272\216QT", 0));
        action_Help->setText(QApplication::translate("AndorSoftwareClass", "\345\270\256\345\212\251(&H)", 0));
        action_Help->setShortcut(QApplication::translate("AndorSoftwareClass", "Ctrl+H", 0));
        action_Stop->setText(QApplication::translate("AndorSoftwareClass", "\344\270\255\346\255\242(&F8)", 0));
        action_Stop->setShortcut(QApplication::translate("AndorSoftwareClass", "F8", 0));
        action_EMExposure->setText(QApplication::translate("AndorSoftwareClass", "EMExposure", 0));
        action_EMExposure->setShortcut(QApplication::translate("AndorSoftwareClass", "F2", 0));
        action_scan3d_capture->setText(QApplication::translate("AndorSoftwareClass", "\345\233\276\345\203\217\345\244\204\347\220\206", 0));
        action_scan3d_capture->setShortcut(QApplication::translate("AndorSoftwareClass", "F10", 0));
        action_CT->setText(QApplication::translate("AndorSoftwareClass", "CT\351\207\207\351\233\206", 0));
        actionPET->setText(QApplication::translate("AndorSoftwareClass", "PET\351\207\207\351\233\206", 0));
        label_DisplayTemp->setText(QString());
        label_2->setText(QApplication::translate("AndorSoftwareClass", "Kinetic Scan to display \357\274\232", 0));
        pushButton_CoolerOn->setText(QApplication::translate("AndorSoftwareClass", "Cooler On", 0));
        pushButton_CoolerOff->setText(QApplication::translate("AndorSoftwareClass", "Cooler Off", 0));
        groupBox_2->setTitle(QApplication::translate("AndorSoftwareClass", "Camera Status \357\274\232", 0));
        textEdit_AndorStatus->setHtml(QApplication::translate("AndorSoftwareClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        groupBox_1->setTitle(QApplication::translate("AndorSoftwareClass", "Information about Camera:", 0));
        textEdit_Information->setHtml(QApplication::translate("AndorSoftwareClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        groupBox_3->setTitle(QApplication::translate("AndorSoftwareClass", "\347\233\270\346\234\272\351\207\207\351\233\206\345\233\276\345\203\217\346\230\276\347\244\272\345\214\272\345\237\237 \357\274\232", 0));
        label_DisplayImage->setText(QApplication::translate("AndorSoftwareClass", "                                 \347\233\270\346\234\272\351\207\207\351\233\206\345\233\276\345\203\217\346\230\276\347\244\272\345\214\272\345\237\237", 0));
        label_1->setText(QApplication::translate("AndorSoftwareClass", "Temperature Setting \357\274\232", 0));
        label_3->setText(QApplication::translate("AndorSoftwareClass", "Current Temperature \357\274\232", 0));
        menu_F->setTitle(QApplication::translate("AndorSoftwareClass", "\346\226\207\344\273\266(&F)", 0));
        menu_E->setTitle(QApplication::translate("AndorSoftwareClass", "\350\256\276\347\275\256(&E)", 0));
        menu->setTitle(QApplication::translate("AndorSoftwareClass", "\345\205\211\345\255\246\351\207\207\351\233\206", 0));
        menu_H->setTitle(QApplication::translate("AndorSoftwareClass", "\345\270\256\345\212\251(&H)", 0));
        menu_2->setTitle(QApplication::translate("AndorSoftwareClass", "\345\233\276\345\203\217\345\244\204\347\220\206", 0));
        menuCT->setTitle(QApplication::translate("AndorSoftwareClass", "CT\351\207\207\351\233\206", 0));
        menuPET->setTitle(QApplication::translate("AndorSoftwareClass", "PET\351\207\207\351\233\206", 0));
    } // retranslateUi

};

namespace Ui {
    class AndorSoftwareClass: public Ui_AndorSoftwareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANDORSOFTWARE_H
