#include "emexposure.h"

EMExposure::EMExposure(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	
	ReadConfigurationFile();

	ui.verticalSlider_EM->setRange(0,100);
	ui.verticalSlider_Exposure->setRange(0,1000);
	
	QObject::connect(ui.verticalSlider_EM,SIGNAL(valueChanged(int)),this,SLOT(setlineEdit_EMValue(int))); 
	QObject::connect(ui.lineEdit_EM,SIGNAL(textChanged(const QString &)),this,SLOT(setverticalSlider_EMValue(const QString &)));

	QObject::connect(ui.verticalSlider_Exposure,SIGNAL(valueChanged(int)),this,SLOT(setverticalSlider_ExposureValue(int))); 
	QObject::connect(ui.lineEdit_Exposure,SIGNAL(textChanged(const QString &)),this,SLOT(setverticalSlider_ExposureValue(const QString &)));

	ui.verticalSlider_EM->setVisible(false);
	ui.lineEdit_EM->setVisible(false);
}

void EMExposure::setlineEdit_EMValue(int verticalSlider_EM_string)
{
	emit sendandorsoftwareEMableValue(verticalSlider_EM_string); //向主窗口发送EM值
	QString lineEdit_EM_value = QString::number(verticalSlider_EM_string);
	ui.lineEdit_EM->setText(lineEdit_EM_value);

}

void EMExposure::setverticalSlider_EMValue(const QString &lineEdit_EM_string)
{
	bool lineEdit_EM_ok;
	int lineEdit_EM_Number = lineEdit_EM_string.toInt(&lineEdit_EM_ok,10);
	emit sendandorsoftwareEMableValue(lineEdit_EM_Number); ////向主窗口发送EM值
	ui.verticalSlider_EM->setValue(lineEdit_EM_Number);
}

void EMExposure::setverticalSlider_ExposureValue(int verticalSlider_Exposure_string)
{
	emit sendandorsoftwareEMableValue(verticalSlider_Exposure_string); ////向主窗口发送Exposure值
	QString verticalSlider_Exposure_value = QString::number(verticalSlider_Exposure_string);
	ui.lineEdit_Exposure->setText(verticalSlider_Exposure_value);

}

void EMExposure::setverticalSlider_ExposureValue(const QString &lineEdit_Exposure_string)
{
	bool verticalSlider_Exposure_ok;
	int verticalSlider_Exposure_Number = lineEdit_Exposure_string.toInt(&verticalSlider_Exposure_ok,10);
	emit sendandorsoftwareEMableValue(verticalSlider_Exposure_Number); ////向主窗口发送Exposure值
	ui.verticalSlider_Exposure->setValue(verticalSlider_Exposure_Number);
}

void EMExposure::receiveemexposureEMable(bool EMable)
{
	EMOK = EMable;
	if(EMable)
	{
		ui.checkBox_EM->setChecked(true);
		ui.verticalSlider_EM->setVisible(true);
		ui.lineEdit_EM->setVisible(true);
	
	}
	else
	{
		ui.checkBox_EM->setChecked(false);
		ui.verticalSlider_EM->setVisible(false);
		ui.lineEdit_EM->setVisible(false);	
		ui.label_EM1->setText("");
		ui.label_EM2->setText("");
	
	}

}

void EMExposure::receiveEMValueRange(int min, int max)
{
	ui.label_EM1->setNum(min);
	ui.label_EM2->setNum(max);
	ui.verticalSlider_EM->setMinimum(min);
	ui.verticalSlider_EM->setMaximum(max);
}

void EMExposure::receiveemexposureEMableValue(int EMableValue)
{
	setEMableValue = EMableValue;
	QString QStringEMableValue = QString::number(setEMableValue);
	ui.lineEdit_EM->setText(QStringEMableValue);
	ui.verticalSlider_EM->setValue(setEMableValue);
}

void EMExposure::on_checkBox_EM_clicked()
{
	if(Qt::Checked == ui.checkBox_EM->checkState())
	{
/*		ui.label_Num2->setText("EM");
		EMenable = true;
		ui.spinBox_EMRange->setVisible(true);
		ui.pushButton_EMAdvanced->setVisible(true);
		emit sendEMenableOK(true);*/
		ui.lineEdit_EM->setVisible(true);
		ui.verticalSlider_EM->setVisible(true);
		emit sendEMabletoandorsoftware(true);
	
	}
	if(Qt::Unchecked == ui.checkBox_EM->checkState())
	{
/*		ui.label_Num2->setText("EM2");
		EMenable = false;
		ui.spinBox_EMRange->setVisible(false);
		ui.pushButton_EMAdvanced->setVisible(false);
		emit sendEMenableOK(false);*/
		ui.lineEdit_EM->setVisible(false);
		ui.verticalSlider_EM->setVisible(false);
		ui.label_EM1->setText(" ");
		ui.label_EM2->setText(" ");
		emit sendEMabletoandorsoftware(false);
	}

}


void EMExposure::ReadConfigurationFile()
{
	QFile f(".\\bin\\EM.ini");
	if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, tr("Warnning!!"), tr("初始配置文件读取失败！！！"), QMessageBox::Ok);

	}

	QTextStream txtInput(&f);

	if (!txtInput.atEnd())
	{
		lineStrSet = txtInput.readLine();     //EM第一个值用于判断开启的是低EM还是高EM
	}
	if (!txtInput.atEnd())
	{
		lineStrEM = txtInput.readLine();  //第二个值是EM的值
	}

	f.close();


	QFile f2(".\\bin\\Exposure.ini");
	if (!f2.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, tr("Warnning!!"), tr("初始配置文件读取失败！！！"), QMessageBox::Ok);

	}

	QTextStream txtInput2(&f2);

	if (!txtInput2.atEnd())
	{
		lineStrSet = txtInput2.readLine();   //Exposure只写入一个值，并读取(Exposure)值
	}

	f2.close();


}


void EMExposure::on_pushButton_OK_clicked()
{

}

void EMExposure::on_pushButton_Cancel_clicked()
{

}

EMExposure::~EMExposure()
{

}
