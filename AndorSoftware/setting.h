#ifndef SETTING_H
#define SETTING_H

#include <QtWidgets/QWidget>
#include "ui_setting.h"
#include <QComboBox>
#include <QRadioButton>
#include <QMessageBox>
#include <QTextCodec>
#include "emadvanced.h"
#include "ATMCD32D.H"

#include <QFile>
#include <QTextStream>

class setting : public QWidget
{
	Q_OBJECT

public:
	setting(QWidget *parent = 0);
	~setting();

private slots:
	void on_pushButton_SetAcqParameter_clicked();
	void on_pushButton_CancelAcqParameter_clicked();
	void on_pushButton_EMAdvanced_clicked();
	
	void on_radioButton_Binning1_clicked();
	void on_radioButton_Binning2_clicked();
	void on_radioButton_Binning4_clicked();
	void on_radioButton_Binning8_clicked();
	void on_radioButton_Binning16_clicked();
	void on_radioButton_BinningCustom_clicked();
	void on_radioButton_Kinetic1_clicked();
	void on_radioButton_Kinetic2_clicked();

	void on_checkBox_EMEnable_clicked();
	void spinBoxEMValue(int);
	void receivesettingEMValue(int); //接受emexposure （andorsoftware） 发来的EM值
	void receiveEMValueRange(int,int);
	void receiveEMableFromAndorsofterware(bool);

	void GetEMAdvanced(bool );

	//void on_sel(const QString &text);
private:
	Ui::settingClass ui;
	int hBinning;
	int vBinning;

	bool Binning1;
	bool Binning2;
	bool Binning4;
	bool Binning8;
	bool Binning16;
	bool BinningCustom;
	bool Parameters;

	int EMGainRangelow;
	int EMGainRangehigh;


	bool KineticMode1;
	bool KineticMode2;
	float KineticCycleTime;
	float KineticTime;
	int   KineticNumber;

	bool EMenable;
	bool EMAdvancedenable;

	QString lineStrSet;
	QString lineStrEM;

	void  ReadConfigurationFile();
	void  WriteConfigurationFile(int EMvalue, int Exposure);

signals:
	void sendSingleSettingParameters(float , int , int); // fExposure   hBinning  vBinning  
	void sendKineticSettingParameters(float , int , int , float , float , int ); // fExposure   hBinning  vBinning  CycleTime  TotalTime KineticNumber
	void sendVideoSettingParameters(float , int , int  ); // fExposure   hBinning  vBinning 
	void sendspinBoxEMValue(int);
	void sendEMenableOK(bool);
	void sendEMadvancedOK(bool);

};

#endif // SETTING_H
