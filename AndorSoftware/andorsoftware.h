#ifndef ANDORSOFTWARE_H
#define ANDORSOFTWARE_H

#include <QtWidgets/QMainWindow>
#include "ui_andorsoftware.h"


#include<QString>
#include<QLabel>
#include<QTextEdit>
#include<QLineEdit>
#include<QPushButton>
#include<QTimer>
#include<QTime>
#include<QImage>
#include<QFileDialog>
#include<QMessageBox>
#include<QFont>
#include <QSpinBox>
#include <QPainter>
#include <QTextCodec>
#include <QRGB>
#include <QProcess>

#include <assert.h>
#include "andorThread.h"
#include "setting.h"
#include "emexposure.h"

#define MAXSIZE_Thread  3

#define RaisingTemperureOnShutDown 3000





class AndorSoftware : public QMainWindow
{
	Q_OBJECT

public:
	AndorSoftware(QWidget *parent = 0);
	~AndorSoftware();
	
	void  Andor_Initialize();
	void closeEvent ( QCloseEvent * e );
	void VideoImage();
//	void Show_image();
	void PaintImage();

	QImage Andor16bitGrayToQImage(const unsigned char *pBuffer, const int &bufWidth, const int &bufHight); //将16bit灰度数据封装成QImage

private:
	Ui::AndorSoftwareClass ui;
	acqThread newAcqThread;
	tempratureThread newTempShowThread;
	KineticThread newKineticThread;
	VideoThread newVideoThread;

//	QVector<QRgb> vcolorTable; //生成灰度颜色表 
	QVector<QRgb> vgrayTable; //生成灰度颜色表 

	QString ChooseMode;
	QString filepath;
	QString filename1;
	QString Fullfilename;
	int		KineticNumber;
	

	QString KineticFliepathName;

	float setfExposure;
	int sethBinning;
	int setvBinning;
	float   setKineticCycleTime;
	float   setKineticTime;
	int     setKineticNumber;
	int     chooseNumberImage;    //选择连拍时显示的图片

	int     EMAdvancedState;
	int     EMCCDggain;
	int     EMGainRangelow;
	int     EMGainRangehigh;

	bool    AndorEMAdvanced;
	bool	AndorEM;
	int     AndorEMValue;

	bool setSingleAcq;
	bool setKineticAcq;
	bool setVideoAcq;

	QProcess actionCT;
	QProcess actionPET;
private slots:
	void on_action_Open_triggered();
	void on_action_Save_triggered();
	void on_action_Exit_triggered();
	void on_action_SetParameter_triggered();
	void on_action_SingleAcquisition_triggered();
	void on_action_KineticAcquisition_triggered();
	void on_action_VideoAcquisition_triggered();
	
	void on_action_CT_triggered();
	void on_actionPET_triggered();
	
	void on_action_Stop_triggered();
	void on_action_About_triggered();
	void on_action_QT_triggered();
	void on_action_Help_triggered();
	void on_action_EMExposure_triggered();
	void on_action_scan3d_capture_triggered();

	void on_pushButton_CoolerOn_clicked();
	void on_pushButton_CoolerOff_clicked();


	void reciveSingleSettingParameters(float fExposure, int hBinning, int vBinning ); // fExposure   hBinning  vBinning  
	void reciveKineticSettingParameters(float , int , int , float , float , int); // fExposure   hBinning  vBinning  CycleTime  TotalTime KineticNumber
	void reciveVideoSettingParameters(float fExposure, int hBinning, int vBinning );


	void reciveAquisitionSignals(unsigned int sig);
	void reciveTempSignals(QString str);
	void reciveKineticImg(unsigned int sig);
	void KineticImageData(void);
	void reciveVideoSignals(unsigned int sig);

	void recivespinBoxEMValue( int); //EM value
	void reciveEMableOK(bool); //open EM
	void receiveEMadvanced(bool); //open EMadvanced
	void receiveandorsoftwareEMValue(int);

	void chooseImage(int);


signals:
	void sendTemperatureSetting(int,bool);
	void sendSingleSignals(unsigned int);
	void sendKineticSignals(unsigned int);
	void sendVideoSignals(unsigned int );
	void valueChanged(int);  //spinBox选择连拍时的照片
	void sendemexposureEMable(bool); //打开em  slider
	void sendemexposureEMValue(int);
	void sendsettingEMValue(int);
	void sendEMValueRange(int,int);
	void sendEMabletosetting(bool);


};

#endif // ANDORSOFTWARE_H
