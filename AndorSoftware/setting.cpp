#include "setting.h"


setting::setting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QFile f(".\\bin\\test.txt");
	if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, tr("Warnning!!"), tr("初始配置文件读取失败！！！"), QMessageBox::Ok);
		
	}

	QTextStream txtInput(&f);
	
	if (!txtInput.atEnd())
	{
		lineStrSet = txtInput.readLine();
	}
	if (!txtInput.atEnd())
	{
		lineStrEM = txtInput.readLine();
	}

	f.close();



	//Binning判断选择的Binning到底是是哪个
    Binning1 = false;
	Binning2 = false;
	Binning4 = false;
	Binning8 = false;
	Binning16 = false;
	BinningCustom = false;
	Parameters = false;
	KineticMode1 = false;  //选择的连拍模式
	KineticMode2 = false;
	EMenable = false; //默认EM关闭
	EMAdvancedenable = false; //默认EMAdvanced关闭
	if(Qt::Unchecked == ui.checkBox_EMEnable->checkState())
	{
//		ui.label_Num2->setText("EM2");
		EMenable = false;
		ui.spinBox_EMRange->setVisible(false);
		ui.pushButton_EMAdvanced->setVisible(false);
	}
	QObject::connect(ui.spinBox_EMRange,SIGNAL(valueChanged(int)),this,SLOT(spinBoxEMValue(int)));

}

void setting::on_pushButton_SetAcqParameter_clicked()
{
	while(true)
	{
		QString str = ui.comboBox_AcquisitionMode->itemText(ui.comboBox_AcquisitionMode->currentIndex());
		if("Single" == str )   //选择是哪种模式
		{
			float fExposure=ui.lineEdit_ExposureTime->text().toFloat();
			if(fExposure == 0.0)  //未选择曝光时间
			{
				QMessageBox::information(NULL,tr("Warnning"),tr("You don't choose Exposure.Please choose Exposure!!!"),QMessageBox::Ok);
				break;
			}
			if( Binning1 == false && Binning2 == false && Binning4 == false && Binning8 == false && Binning16 == false && BinningCustom == false)
			{
				hBinning = ui.lineEdit_Binning1->text().toInt();
				vBinning = ui.lineEdit_Binning2->text().toInt();
				if(hBinning == 0 || vBinning == 0)
				{	QMessageBox::information(NULL,tr("Warnning"),tr("You don't choose binning.Please choose binning!!!"),QMessageBox::Ok);
					break;
				}
				else
				{
				emit sendSingleSettingParameters(fExposure,  hBinning, vBinning );
				Parameters = true;
//				ui.label_Num2->setText("11");
				break;
				}
			}
			else
			{
				emit sendSingleSettingParameters(fExposure,  hBinning, vBinning );
				Parameters = true;
				break;
			}
//			ui.label_Num->setText("sendSingleOk");	
		}
	

		if("Kinetic" == str )
		{
					
			if(KineticMode1)
			{
				KineticNumber = -1; //选择mode1 KineticNumber用不到 值为零
				float fExposure=ui.lineEdit_ExposureTime->text().toFloat();
				if(fExposure == 0.0)  //未选择曝光时间
				{
				QMessageBox::information(NULL,tr("Warnning"),tr("You don't choose Exposure.Please choose Exposure!!!"),QMessageBox::Ok);
				break;
				}
				if( Binning1 == false && Binning2 == false && Binning4 == false && Binning8 == false && Binning16 == false && BinningCustom == false)
				{
					hBinning = ui.lineEdit_Binning1->text().toInt();
					vBinning = ui.lineEdit_Binning2->text().toInt();
					if(hBinning == 0 || vBinning == 0)
					{	
						QMessageBox::information(NULL,tr("Warnning"),tr("You don't choose binning.Please choose binning!!!"),QMessageBox::Ok);
						KineticMode1 = false;
						break;
					}
					KineticCycleTime = ui.lineEdit_KineticCycleTime->text().toFloat();
					KineticTime = ui.lineEdit_KineticTime->text().toFloat();
					emit sendKineticSettingParameters(fExposure,  hBinning, vBinning , KineticCycleTime , KineticTime ,KineticNumber);
					Parameters = true;
//					ui.label_Num2->setText("22");
					KineticMode1 = false;
//					ui.label_Num->setText("sendKineticOk");
					break;
				}
				else
				{
					KineticCycleTime = ui.lineEdit_KineticCycleTime->text().toFloat();
					KineticTime = ui.lineEdit_KineticTime->text().toFloat();
					emit  sendKineticSettingParameters(fExposure , hBinning , vBinning , KineticCycleTime , KineticTime ,KineticNumber);
					Parameters = true;
					KineticMode1 = false;
//					ui.label_Num->setText("sendKineticOk");
					break;
				}
				
				
			}
			else if(KineticMode2)
			{
				KineticTime = -1; //选择mode2 KineticTime用不到 值为零
				float fExposure=ui.lineEdit_ExposureTime->text().toFloat();
				if(fExposure == 0.0)  //未选择曝光时间
				{
				QMessageBox::information(NULL,tr("Warnning"),tr("You don't choose Exposure.Please choose Exposure!!!"),QMessageBox::Ok);
				break;
				}
				if( Binning1 == false && Binning2 == false && Binning4 == false && Binning8 == false && Binning16 == false && BinningCustom == false)
				{
					hBinning = ui.lineEdit_Binning1->text().toInt();
					vBinning = ui.lineEdit_Binning2->text().toInt();
					if(hBinning == 0 || vBinning == 0)
					{	
						QMessageBox::information(NULL,tr("Warnning"),tr("You don't choose binning.Please choose binning!!!"),QMessageBox::Ok);
						KineticMode2 = false;
						break;
					}
					KineticCycleTime = ui.lineEdit_KineticCycleTime_2->text().toFloat();
					KineticNumber = ui.lineEdit_KineticNumber->text().toInt();
					emit sendKineticSettingParameters(fExposure,  hBinning, vBinning ,KineticCycleTime , KineticTime ,KineticNumber);
					Parameters = true;
					KineticMode2 = false;
//					ui.label_Num2->setText("22");
//					ui.label_Num->setText("sendKineticOk");	
					break;
				}
				else
				{
					KineticCycleTime = ui.lineEdit_KineticCycleTime_2->text().toFloat();
					KineticNumber = ui.lineEdit_KineticNumber->text().toInt();
					emit  sendKineticSettingParameters(fExposure , hBinning , vBinning , KineticCycleTime , KineticTime ,KineticNumber );
					Parameters = true;
					KineticMode2 = false;
//					ui.label_Num->setText("sendKineticOk");	
					break;
				}
				
					
			}
			else
			{
				QMessageBox::information(NULL,tr("Warnning"),tr("You don't choose Kinetic Mode .Please choose Kinetic Mode first!!!"),QMessageBox::Ok);
				break;
			}
		
		}

		if("Video" == str )
		{
			float fExposure=ui.lineEdit_ExposureTime->text().toFloat();
			if(fExposure == 0.0)  //未选择曝光时间
				{
				QMessageBox::information(NULL,tr("Warnning"),tr("You don't choose Exposure.Please choose Exposure!!!"),QMessageBox::Ok);
				break;
				}
			if( Binning1 == false && Binning2 == false && Binning4 == false && Binning8 == false && Binning16 == false && BinningCustom == false)
			{
				hBinning = ui.lineEdit_Binning1->text().toInt();
				vBinning = ui.lineEdit_Binning2->text().toInt();
				if(hBinning == 0 || vBinning == 0)
				{	
					QMessageBox::information(NULL,tr("Warnning"),tr("You don't choose binning.Please choose binning!!!"),QMessageBox::Ok);
					break;
				}
				emit sendVideoSettingParameters(fExposure,  hBinning, vBinning );
				Parameters = true;
				break;
//				ui.label_Num2->setText("33");
			}
			else
			{
				emit  sendVideoSettingParameters(fExposure , hBinning , vBinning );
//				ui.label_Num->setText("sendVideoOk");
				Parameters = true;
				break;
			}
			
	
		}
	}
	
	if(Parameters == true)
	{
		this->close();
	}

}


void setting::on_pushButton_CancelAcqParameter_clicked()
{
	
	
	QMessageBox::StandardButton rb = QMessageBox::information(NULL, QString::fromUtf8("Warnning"), "Please choose to confirm or cancel your parameters have been chosen!!!", 
		QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	
	if(rb == QMessageBox::Yes)
	{
		this->close();
	}

}

void setting::on_checkBox_EMEnable_clicked()
{
	if(Qt::Checked == ui.checkBox_EMEnable->checkState())
	{
//		ui.label_Num2->setText("EM");
		EMenable = true;
		ui.spinBox_EMRange->setVisible(true);
		ui.pushButton_EMAdvanced->setVisible(true);
		emit sendEMenableOK(true);
	
	}
	if(Qt::Unchecked == ui.checkBox_EMEnable->checkState())
	{
//		ui.label_Num2->setText("EM2");
		EMenable = false;
		ui.spinBox_EMRange->setVisible(false);
		ui.pushButton_EMAdvanced->setVisible(false);
		emit sendEMenableOK(false);
	}
}

void setting::receiveEMableFromAndorsofterware(bool m)
{
	ui.checkBox_EMEnable->setChecked(m);
	if(Qt::Checked == ui.checkBox_EMEnable->checkState())
	{
//		ui.label_Num2->setText("EM");
		EMenable = m;
		ui.spinBox_EMRange->setVisible(true);
		ui.pushButton_EMAdvanced->setVisible(true);
	
	}
	if(Qt::Unchecked == ui.checkBox_EMEnable->checkState())
	{
//		ui.label_Num2->setText("EM2");
		EMenable = m;
		ui.spinBox_EMRange->setVisible(false);
		ui.pushButton_EMAdvanced->setVisible(false);
	}

}

void setting::on_pushButton_EMAdvanced_clicked()
{
	if(EMenable)
	{
		EMAdvanced *emadvanced = new EMAdvanced;
		connect(emadvanced,SIGNAL(sendEMAdvanced(bool )),this,SLOT(GetEMAdvanced(bool )));
		emadvanced->show();
	}
	else
	{
		QMessageBox::information(NULL,tr("Warnning!"),tr("Please open EM first!!!"),QMessageBox::Ok|QMessageBox::Cancel);
	
	}


}

void setting::spinBoxEMValue(int EMValue)
{
//	ui.label_Num2->setText("libingfdgdfgadfd");
	emit sendspinBoxEMValue(EMValue);

}

void setting::GetEMAdvanced(bool getemadvanced)
{
	if(getemadvanced)
	{
//		ui.label_Num2->setText("true");
		EMAdvancedenable = true;
		emit sendEMadvancedOK(true);
	}
	else
	{
//		ui.label_Num2->setText("false");
		EMAdvancedenable = false;
		emit sendEMadvancedOK(false);
	}

}

void setting::receiveEMValueRange(int min,int max)
{
	ui.spinBox_EMRange->setMinimum(min);
	ui.spinBox_EMRange->setMaximum(max);
}

void setting::receivesettingEMValue(int m) //接受emexposure （andorsoftware） 发来的EM值
{
	ui.spinBox_EMRange->setValue(m);

}

void setting::on_radioButton_Binning1_clicked()
{
	hBinning = 1;
	vBinning = 1;
//	ui.label_Num->setText("1*1");
	Binning1 = true;
	Binning2 = false;
	Binning4 = false;
	Binning8 = false;
	Binning16 = false;
	BinningCustom = false;
}


void setting::on_radioButton_Binning2_clicked()
{
	hBinning = 2;
	vBinning = 2;
//	ui.label_Num->setText("2*2");
	Binning1 = false;
	Binning2 = true;
	Binning4 = false;
	Binning8 = false;
	Binning16 = false;
	BinningCustom = false;

}


void setting::on_radioButton_Binning4_clicked()
{
	hBinning = 4;
	vBinning = 4;
//	ui.label_Num->setText("4*4");
	Binning1 = false;
	Binning2 = false;
	Binning4 = true;
	Binning8 = false;
	Binning16 = false;
	BinningCustom = false;
}


void setting::on_radioButton_Binning8_clicked()
{
	hBinning = 8;
	vBinning = 8;
//	ui.label_Num->setText("8*8");
	Binning1 = false;
	Binning2 = false;
	Binning4 = false;
	Binning8 = true;
	Binning16 = false;
	BinningCustom = false;
}

void setting::on_radioButton_Binning16_clicked()
{
	hBinning = 16;
	vBinning = 16;
//	ui.label_Num->setText("16*16");
	Binning1 = false;
	Binning2 = false;
	Binning4 = false;
	Binning8 = false;
	Binning16 = true;
	BinningCustom = false;
}

void setting::on_radioButton_BinningCustom_clicked()
{
	hBinning = 1;
	vBinning = 1;
//	ui.label_Num->setText("Custom:1*1");
	Binning1 = false;
	Binning2 = false;
	Binning4 = false;
	Binning8 = false;
	Binning16 = false;
	BinningCustom = true;
}

void setting::on_radioButton_Kinetic1_clicked()
{
	KineticMode1 =true;
	KineticCycleTime = ui.lineEdit_KineticCycleTime->text().toFloat();
	KineticTime = ui.lineEdit_KineticTime->text().toFloat();

}

void setting::on_radioButton_Kinetic2_clicked()
{
	KineticMode2 = true;
	KineticCycleTime = ui.lineEdit_KineticCycleTime_2->text().toFloat();
	KineticNumber = ui.lineEdit_KineticNumber->text().toInt();

}

void setting::WriteConfigurationFile(int EMvalue, int Exposure)
{
	QFile f(".\\bin\\EM.ini");
	if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		//cout << "Open failed." << endl;
		//return -1;
	}

	QTextStream txtOutput(&f);
	QString s1("123");
	quint32 n1(123);

	txtOutput << s1 << endl;
	txtOutput << n1 << endl;

	f.close();


}

void setting::ReadConfigurationFile()
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


setting::~setting()
{

}
