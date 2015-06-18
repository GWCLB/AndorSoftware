#ifndef EMEXPOSURE_H
#define EMEXPOSURE_H

#include <QtWidgets/QDialog>
#include "ui_emexposure.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

class EMExposure : public QDialog
{
	Q_OBJECT

public:
	EMExposure(QWidget *parent = 0);
	~EMExposure();

	void  ReadConfigurationFile();


private:
	Ui::EMExposureClass ui;

	bool EMOK;

	int setEMableValue;

	QString lineStrSet;
	QString lineStrEM;

private slots:

	void setlineEdit_EMValue(int);
	void setverticalSlider_EMValue(const QString &);
	void setverticalSlider_ExposureValue(int);
	void setverticalSlider_ExposureValue(const QString &);
	void on_pushButton_OK_clicked();
	void on_pushButton_Cancel_clicked();
	void receiveemexposureEMable(bool);
	void receiveemexposureEMableValue(int);
	void receiveEMValueRange(int,int);

	void on_checkBox_EM_clicked();
signals:
	void sendandorsoftwareEMableValue(int);

	void sendEMabletoandorsoftware(bool);
	


};

#endif // EMEXPOSURE_H
