#include "andorsoftware.h"
#include "ATMCD32D.H"
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#define Color = 256

void Wchar_tToString(std::string& szDst, wchar_t *wchar);

int AllocateBuffers(int gblXPixels, int gblYPixels);
void FreeBuffers(void);

BOOL gblCooler=FALSE;    // Indicate if cooler is on
WORD *pImageArray=NULL;

int gblXPixels, gblYPixels;

int               VSnumber;                 // Vertical Speed Index
int               HSnumber;                 // Horizontal Speed Index
int               ADnumber;                 // AD Index

BOOL Shutter_ONOFF=FALSE;
using namespace std;



AndorSoftware::AndorSoftware(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Andor_Initialize();
	ChooseMode = "Andor";
	KineticNumber = 0;
	chooseNumberImage = 0;
	AndorEMAdvanced = false;//默认EMAdvanced值不开。
	AndorEM = false;//默认EM不开
	setSingleAcq = false;
	setKineticAcq = false;
	setVideoAcq = false;
	
	 //temperature
	 QObject::connect(&newTempShowThread,SIGNAL(sentTempatureSettingInfo(QString)),this,SLOT(reciveTempSignals(QString)));
	 QObject::connect(this,SIGNAL(sendTemperatureSetting(int,bool)),&newTempShowThread,SLOT(recieveTemperatureSetting(int,bool)));

	 //single scan 
	 QObject::connect(&newAcqThread,SIGNAL(sendAquisitionSettingInfo(unsigned int )),this,SLOT(reciveAquisitionSignals(unsigned int )));
	 QObject::connect(&newAcqThread,SLOT(receiveSingleSignal(unsigned int )),this,SIGNAL(sendSingleSignals(unsigned int)));

	 //Kinetic Series
	 QObject::connect(&newKineticThread,SIGNAL(sendKineticsettingInfo(unsigned int)),this,SLOT(reciveKineticImg(unsigned int)));
	 QObject::connect(this,SIGNAL(sendKineticSignals(unsigned int )),&newKineticThread,SLOT(receiveKineticSignal(unsigned int )));
	 QObject::connect(&newKineticThread,SIGNAL(sendKineticsettingInfo(unsigned int)),this,SLOT(AcquireImageData(void)));

	 // Run Till Abort   Video
	 QObject::connect(&newVideoThread,SIGNAL(sendVideoSettingInfo(unsigned int )),this,SLOT(reciveVideoSignals(unsigned int )));
	 QObject::connect(this,SIGNAL(sendVideoSignals(unsigned int )),&newVideoThread,SLOT(receiveVideoSignal(unsigned int )));
	 
	 //action_CT
	// QObject::connect(ui.action_CT, &QAction::triggered, this, &AndorSoftware::on_action_CT_triggered);
	
	 newTempShowThread.start();

//	 ui.spinBox_ChoseImage->setMinimum(1);
	 QObject::connect(ui.spinBox_ChoseImage, SIGNAL(valueChanged(int)),this, SLOT(chooseImage(int)));

	 //初始化QRGB（灰度）
	for (int i = 0; i < 65536; i++)  
    {  
        vgrayTable.append(qRgb(i, i, i));  
    }  

/*	int i(0),j(0);
	for( i = 1; i < 32; ++i )
		vcolorTable.append(qRgb(0,0,131 + (i<<2)));  
	for( i = 32,j = 0; i < 96; ++i )
		vcolorTable.append(qRgb(0,((++j<<2)-1),255)); 
	for( i = 96,j = 0; i < 160; ++i )
	{
		int r=(++j<<2)-1;
		vcolorTable.append(qRgb(r,255,255-r)  );  
	}
	for( i = 160,j = 0; i < 224; ++i )
		vcolorTable.append(qRgb(255,256-(++j<<2),0) );  
	for( i = 224,j = 0; i < 256; ++i )
		vcolorTable.append(qRgb(256-(++j<<2),0,0));  */


}

void  AndorSoftware::Andor_Initialize()
{
	int i=0;
	wchar_t aBuffer[256];
	GetCurrentDirectory(256,aBuffer);
	string temp;
	Wchar_tToString(temp,aBuffer);
	char* aBufferChar=const_cast<char*>(temp.c_str());
	//初始化相机，获取相机相关参数
	int errorValue=Initialize(aBufferChar);
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->setText("Initialize Error");
		ShutDown();
	}
	else
	{
        ui.textEdit_Information->append( tr("Initialize Success") );
	}
	AndorCapabilities caps;
	caps.ulSize=sizeof(AndorCapabilities);
	errorValue=GetCapabilities(&caps);
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( tr("Get Andor Capabilities information Error") );
		ShutDown();
	}
	else
	{
		ui.textEdit_Information->append( tr("Get Andor Capabilities information Success") );
	}
	char model[32];
	errorValue=GetHeadModel(model);
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( tr("Get Head Model information Error") );
        ShutDown();
	}
	else
	{
		ui.textEdit_Information->append( tr("Get Head Model information :") );
		ui.textEdit_Information->moveCursor(QTextCursor::End);
		ui.textEdit_Information->insertPlainText(model);
     }

	errorValue=GetDetector(&gblXPixels,&gblYPixels);
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( tr("Get Detector information Error") );
		ShutDown();
	}
	else
	{
		ui.textEdit_Information->append( tr("Size of CCD: %1*").arg(gblXPixels) );
		ui.textEdit_Information->moveCursor(QTextCursor::End);
		QString  GetDetector_tt= QString::number(gblYPixels, 10);             
		ui.textEdit_Information->insertPlainText(GetDetector_tt);
	}
	int minTemp,maxTemp;
	errorValue=GetTemperatureRange(&minTemp,&maxTemp);
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( tr("Get Temperature Range Error") );
		ShutDown();
	}
	else
	{
		ui.textEdit_Information->append( tr("Temprature Range:%1   To   ").arg(minTemp) );
		ui.textEdit_Information->moveCursor(QTextCursor::End);
		QString  GetTemperatureRange_tt= QString::number(maxTemp, 10);             
		ui.textEdit_Information->insertPlainText(GetTemperatureRange_tt);
	}

	int CurrentTemp;
	errorValue=GetTemperature(&CurrentTemp);
	switch(errorValue)
	{
	case DRV_TEMPERATURE_STABILIZED:
		ui.textEdit_Information->append( "Temperature has stabilized at " );
		break;
	case DRV_TEMPERATURE_NOT_REACHED:
		ui.textEdit_Information->append( "Current temperature is " );
		break;
	default:
		ui.textEdit_Information->append( "Temperature control is disabled " );

		break;
	}
	float  speed, STemp;
    int    iSpeed, iAD, nAD, index;
	// Set Vertical speed to recommended
    GetFastestRecommendedVSSpeed(&VSnumber, &speed);
    errorValue=SetVSSpeed(VSnumber);
    if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( tr("Set Vertical Speed Error\n"));
    }
	// Set Horizontal Speed to max
    STemp = 0;
	HSnumber = 0;
    ADnumber = 0;
    errorValue = GetNumberADChannels(&nAD);
    if (errorValue != DRV_SUCCESS)
	{
		ui.textEdit_Information->append( tr("Get number AD Channel Error\n"));
	}
    else
	{
		for (iAD = 0; iAD < nAD; iAD++) 
		{
			GetNumberHSSpeeds(iAD, 0, &index);
			for (iSpeed = 0; iSpeed < index; iSpeed++) 
			{
				GetHSSpeed(iAD, 0, iSpeed, &speed);
				if(speed > STemp)
				{
					STemp = speed;
					HSnumber = iSpeed;
					ADnumber = iAD;
				}
			}
		}
    }
    errorValue=SetADChannel(ADnumber);
    if(errorValue!=DRV_SUCCESS)
	{
        ui.textEdit_Information->append( tr("Set AD Channel Error\n"));
	}
    errorValue=SetHSSpeed(0,HSnumber);
    if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( tr("Set Horizontal Speed Error\n"));
    }
	GetVSSpeed(VSnumber, &speed);
	ui.textEdit_Information->append( tr("Vertical Speed set to %1 microseconds per pixel shift").arg(speed) );
    GetHSSpeed(ADnumber, 0, HSnumber, &speed);
    ui.textEdit_Information->append( tr("Horizontal Speed set to %1 microseconds per pixel shift").arg(speed) );	 
    if (caps.ulSetFunctions & AC_SETFUNCTION_BASELINECLAMP) 
	{
		errorValue=SetBaselineClamp(1);
		if(errorValue!=DRV_SUCCESS)
		{
			ui.textEdit_Information->append( tr("Set Baseline Clamp Error\n"));
		}
    }
	//shutter  permanent
	int openclose,ttl,shutter;
	shutter=1;
	ttl=1;
	openclose=0;
	errorValue=SetShutter(ttl,shutter,openclose,openclose);
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( "Shutter setting error" );
		ShutDown();
	}
	else
	{
		ui.textEdit_Information->append( "Shutter setting is permanent opening" );
		Shutter_ONOFF=TRUE;
     }

/*	errorValue = GetEMAdvanced(&EMAdvancedState);
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( "GetEMAdvanced  error" );
		ShutDown();
	}
	else
	{
		ui.textEdit_Information->append( tr("EMAdvanced %1").arg(EMAdvancedState) );
	
	}
	errorValue = GetEMCCDGain(&EMCCDggain);
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( "GetEMCCDGain  error" );
		ShutDown();
	}
	else
	{
		ui.textEdit_Information->append( tr("EMCCDGain %1").arg(EMCCDggain) );
	
	}
	errorValue = GetEMGainRange(&EMGainRangelow,&EMGainRangehigh);
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( "GetEMGainRange  error" );
		ShutDown();
	}
	else
	{
		ui.textEdit_Information->append( tr("EMGainRange:%1   To   ").arg(EMGainRangelow) );
		ui.textEdit_Information->moveCursor(QTextCursor::End);
		QString  GetGetEMGainRange_high= QString::number(EMGainRangehigh, 10);             
		ui.textEdit_Information->insertPlainText(GetGetEMGainRange_high);
	}*/


}

void AndorSoftware::on_action_Open_triggered()  //打开
{

	QString Openfilename;  
	QImage *OpenImg = new QImage;
	Openfilename = QFileDialog::getOpenFileName(this,  
    tr("选择图像"),  
    "",  
    tr("Images (*.png *.bmp *.jpg *.tif *.GIF)")); //选择路径  
	if(Openfilename.isEmpty())  
	{  
		return;  
	}  
	else  
	{  
		if(! ( OpenImg->load(Openfilename) ) ) //加载图像  
		{  
			QMessageBox::information(this,  
				tr("打开图像失败"),  
				tr("打开图像失败!"));  
			return;  
		}
		QImage newImg = OpenImg->scaled(ui.label_DisplayImage->width(), ui.label_DisplayImage->height());
		ui.label_DisplayImage->setPixmap(QPixmap::fromImage(newImg)); //显示图像  
	}  

}

void AndorSoftware::on_action_Save_triggered()  //保存
{
	if("SingleAcquisition"  != ChooseMode  &&  "KineticAcquisition"  != ChooseMode &&  "VideoAcquisition"  != ChooseMode)
	{
		QMessageBox::information(this,  
			tr("Attention Please!!!"),  
            tr("There is no image to save!!!"));
	}
	if("SingleAcquisition"  == ChooseMode)
	{
//		QPixmap pix;
//		pix.load("\\AcquisitionImage\\save.tif");
		QString fileName = QFileDialog::getSaveFileName(this,  
		tr("Save Image"),  
		"",  
		tr("*.tif;; ")); //选择路径  
 
		if(fileName.isEmpty())
		{  
			QMessageBox::information(this,  
			tr("Warnning!!!"),  
            tr("Failed to save the image!"));
		}  
		else 
		{
			//QString tempstring=fileName+".tif";
			//pix.save(tempstring,"tif");
			int size,errorValue;
			size=AllocateBuffers(gblXPixels,gblYPixels);
			errorValue=GetAcquiredData16(pImageArray,size);
			QString KineticName = fileName + ".tif";
			const char *Tempspath= KineticName.toStdString().c_str();
			char *spath = const_cast<char*>(Tempspath);
			SaveAsTiff(spath,"GREY.PAL",1,1);
		}
	}

	
	if("KineticAcquisition"  == ChooseMode)
	{
		KineticFliepathName = QFileDialog::getSaveFileName(this,  
		tr("Save Image"),  
		"",  
		tr("*.tif;; ")); //选择路径

	}
}

void AndorSoftware::reciveSingleSettingParameters(float fExposure, int hBinning, int vBinning )
{
	setSingleAcq = true;
	setfExposure = fExposure;
	sethBinning = hBinning;
	setvBinning = vBinning;
	ui.textEdit_Information->append("receiveSingleOk");
}

void AndorSoftware::reciveKineticSettingParameters(float fExposure, int hBinning, int vBinning, float CycleTime, float TotalTime, int KineticNumber)
{
	setKineticAcq = true;
	setfExposure = fExposure;
	sethBinning = hBinning;
	setvBinning = vBinning;
	setKineticCycleTime = CycleTime;
	setKineticTime = TotalTime;
	setKineticNumber = KineticNumber;
	ui.textEdit_Information->append("receiveKineticOk");
}

void AndorSoftware::reciveVideoSettingParameters(float fExposure, int hBinning, int vBinning )
{
	setVideoAcq = true;
	setfExposure = fExposure;
	sethBinning = hBinning;
	setvBinning = vBinning;
	ui.textEdit_Information->append("receiveVideoOk");
}

void AndorSoftware::recivespinBoxEMValue( int EMValue )
{
	AndorEMValue = EMValue;
	emit sendemexposureEMValue(AndorEMValue);
}

void AndorSoftware::reciveEMableOK(bool OKNot) //是否开启EM值
{
	AndorEM = OKNot;
	if(AndorEM)
	{
		int errorValue;
		errorValue = GetEMGainRange(&EMGainRangelow,&EMGainRangehigh);
		if(errorValue!=DRV_SUCCESS)
		{
			ui.textEdit_Information->append( "GetEMGainRange  error" );
			ShutDown();
		}
		else
		{
			ui.textEdit_Information->append( tr("EMGainRange:%1   To   ").arg(EMGainRangelow) );
			ui.textEdit_Information->moveCursor(QTextCursor::End);
			QString  GetGetEMGainRange_high= QString::number(EMGainRangehigh, 10);             
			ui.textEdit_Information->insertPlainText(GetGetEMGainRange_high);
			emit sendEMValueRange(EMGainRangelow,EMGainRangehigh);
			
		}
	}
	emit sendEMabletosetting(AndorEM);
	emit sendemexposureEMable(AndorEM);
}

void AndorSoftware::receiveEMadvanced(bool m) //是否开启EMAdvanced
{
	AndorEMAdvanced = m;
	if(AndorEMAdvanced)
	{
		int errorValue;
		errorValue = SetEMAdvanced(1);
		if(errorValue ==DRV_SUCCESS)
		{
			ui.textEdit_AndorStatus->setText( tr("EMValue Set :%1   ").arg(AndorEMValue) );
//			ui.textEdit_Information->append( "EMAdvanced Parameters set" );
		}
		if(errorValue ==DRV_NOT_INITIALIZED)
		{
			ui.textEdit_Information->append( "EMAdvanced System not initialized" );
		}
		if(errorValue ==DRV_NOT_AVAILABLE)
		{
			ui.textEdit_Information->append( "Advanced EM gain not available for this camera" );
		}
		if(errorValue ==DRV_ACQUIRING)
		{
			ui.textEdit_Information->append( "EMAdvanced Acquisition in progress" );
		}
		if(errorValue ==DRV_P1INVALID)
		{
			ui.textEdit_Information->append( "EMAdvanced State parameter was not zero or one" );
		}

		errorValue = GetEMGainRange(&EMGainRangelow,&EMGainRangehigh);
		if(errorValue!=DRV_SUCCESS)
		{
			ui.textEdit_Information->append( "GetEMGainRange  error" );
			ShutDown();
		}
		else
		{
			//int EMGainRangelow = 50; int EMGainRangehigh = 60;
			ui.textEdit_Information->append( tr("EMGainRange:%1   To   ").arg(EMGainRangelow) );
			ui.textEdit_Information->moveCursor(QTextCursor::End);
			QString  GetGetEMGainRange_high= QString::number(EMGainRangehigh, 10);             
			ui.textEdit_Information->insertPlainText(GetGetEMGainRange_high);
			emit sendEMValueRange(EMGainRangelow,EMGainRangehigh);

		}
	}
	else
	{
		int errorValue;
		errorValue = SetEMAdvanced(0);
		errorValue = GetEMGainRange(&EMGainRangelow,&EMGainRangehigh);
		
		ui.textEdit_Information->append( tr("EMGainRange:%1   To   ").arg(EMGainRangelow) );
		ui.textEdit_Information->moveCursor(QTextCursor::End);
		QString  GetGetEMGainRange_high= QString::number(EMGainRangehigh, 10);             
		ui.textEdit_Information->insertPlainText(GetGetEMGainRange_high);
		emit sendEMValueRange(EMGainRangelow,EMGainRangehigh);
	
	}
}

void AndorSoftware::receiveandorsoftwareEMValue(int EMvalue) //接受emexposure 发来的EM值
{
	AndorEMValue = EMvalue;
	ui.textEdit_AndorStatus->setText( tr("EMValue Set :%1   ").arg(AndorEMValue) );
	emit sendsettingEMValue(EMvalue);
}


void AndorSoftware::on_action_Exit_triggered() //退出
{
	int temperature;
    GetTemperature(&temperature);
    if(temperature<0)
	{
		CoolerOFF();
		emit sendTemperatureSetting(0,false);
		return;
	}
    else
	{
		QPixmap pix;       
	    pix.load("\\AcquisitionImage\\save.tif");
        QDir rmfile;
        rmfile.remove("\\AcquisitionImage\\save.tif");
		if(Shutter_ONOFF==FALSE)
		{
            this->close();
		}
		int openclose,ttl,shutter,errorValue;
	        shutter=2;
	        ttl=0;
	        openclose=27;
	        errorValue=SetShutter(ttl,shutter,openclose,openclose);
			if(errorValue==DRV_SUCCESS)
			{
				 ShutDown();
                 this->close();
			}
	}

}

void AndorSoftware::on_action_SetParameter_triggered()  //设置
{
	setting *set = new setting;
	connect(set,SIGNAL(sendSingleSettingParameters(float , int , int)),
		this,SLOT(reciveSingleSettingParameters(float , int , int  )));
	connect(set,SIGNAL(sendKineticSettingParameters(float , int , int , float , float,int)),
		this,SLOT(reciveKineticSettingParameters(float , int , int , float , float,int )));
	connect(set,SIGNAL(sendVideoSettingParameters(float , int , int  )),
		this,SLOT(reciveVideoSettingParameters(float , int , int  )));
	connect(set,SIGNAL(sendspinBoxEMValue(int)),this,SLOT(recivespinBoxEMValue(int)));
	connect(set,SIGNAL(sendEMenableOK(bool)),this,SLOT(reciveEMableOK(bool)));

	connect(this,SIGNAL(sendsettingEMValue(int)),set,SLOT(receivesettingEMValue(int)));
	connect(set,SIGNAL(sendEMadvancedOK(bool)),this,SLOT(receiveEMadvanced(bool)));
	connect(this,SIGNAL(sendEMValueRange(int,int)),set,SLOT(receiveEMValueRange(int,int)));

	connect(this,SIGNAL(sendEMabletosetting(bool)),set,SLOT(receiveEMableFromAndorsofterware(bool)));
	set->show();
	

}

void AndorSoftware::on_action_SingleAcquisition_triggered() //单拍
{
	if(setSingleAcq)
	{
		ChooseMode = "SingleAcquisition";
		ui.label_DisplayImage->setAlignment(Qt::AlignCenter);
		ui.label_DisplayImage->setText("Please wait!!!");
		float fExposure=setfExposure;
		int acquisitionMode=1;
		int readMode=4;
		int trig=0;
		int hBinning=sethBinning;
		int vBinning=setvBinning;
		int EMemvalue = 0;
		if(AndorEM)
		{
			EMemvalue = AndorEMValue;
			if(AndorEMAdvanced)
			{
				EMemvalue = AndorEMValue;
			}
		}
		else
		{
			EMemvalue = -1;
		}

		newAcqThread.getAndSetParameters(gblXPixels,gblYPixels,fExposure,acquisitionMode,readMode,trig,hBinning,vBinning,EMemvalue);
		newAcqThread.start();
		ui.textEdit_AndorStatus->setText("You choose the SingleAcquisition Mode :");
	}
	else
	{
		QMessageBox::information(NULL,tr("Warnning"),tr("You don't set the parameters of  the SingleAcquisition!!!"),QMessageBox::Ok);	
	}



}

void AndorSoftware::on_action_KineticAcquisition_triggered()  //连拍
{
	if(setKineticAcq)
	{
		if(KineticNumber)
			KineticNumber = 0;
		ChooseMode = "KineticAcquisition";
		on_action_Save_triggered();  //选择保存路径及文件名
		int 	TotalTime = setKineticTime;
		float 	kineticCycleTime = setKineticCycleTime;
		int		acquisitionMode=1;
		int		readMode=4;
		float	fExposure=setfExposure;
		int		KineticNumber = setKineticNumber;
		int EMemvalue = 0;
		if(AndorEM)
		{
			EMemvalue = AndorEMValue;
			if(AndorEMAdvanced)
			{
				EMemvalue = AndorEMValue;
			}
		}
		else
		{
			EMemvalue = -1;
		}
		newKineticThread.getAndorkineticParameters(acquisitionMode,readMode,fExposure,gblXPixels,gblYPixels,TotalTime,kineticCycleTime,KineticNumber,EMemvalue);
		newKineticThread.start();  
		ui.textEdit_AndorStatus->setText("You choose the KineticAcquisition Mode :");
	}
	else
	{
		QMessageBox::information(NULL,tr("Warnning"),tr("You don't set the parameters of  the KineticAcquisition!!!"),QMessageBox::Ok);	
	}


}

void AndorSoftware::on_action_VideoAcquisition_triggered()  //视频
{
	if(setVideoAcq)
	{
		ChooseMode = "VideoAcquisition";
		int acquisitionMode=1;
		int readMode=4;
		int trig=0;
		int hBinning = sethBinning;
		int vBinning = setvBinning;
		float fExposure=setfExposure;
		int EMemvalue = 0;
		if(AndorEM)
		{
			EMemvalue = AndorEMValue;
			if(AndorEMAdvanced)
			{
				EMemvalue = AndorEMValue;
			}
		}
		else
		{
			EMemvalue = -1;
		}
		newVideoThread.getAndVideoSetParameters(gblXPixels,gblYPixels, fExposure, acquisitionMode, readMode, trig, hBinning, vBinning,EMemvalue);
		newVideoThread.start();
		ui.textEdit_AndorStatus->setText("You choose the VideoAcquisition Mode :");
	}
	else
	{
		QMessageBox::information(NULL,tr("Warnning"),tr("You don't set the parameters of  the VideoAcquisition!!!"),QMessageBox::Ok);	
	}
}

void AndorSoftware::on_action_CT_triggered()
{
	actionCT.start(".\\DiskGenius_4.7_x64\\DiskGenius_4.7_x64.exe");
	//actionCT.start(".\\scan3d-capture-x86\\scan3d-capture-x86.exe");
}
void AndorSoftware::on_actionPET_triggered()
{
	//actionCT.start(".\\DiskGenius_4.7_x64\\DiskGenius_4.7_x64.exe");
	actionPET.start(".\\HDTunePro5.5\\HDTunePro5.5.exe");
	//actionCT.start(".\\scan3d-capture-x86\\scan3d-capture-x86.exe");
}

void AndorSoftware::on_action_Stop_triggered() // 中止
{
	if("SingleAcquisition"  == ChooseMode)
	{
		emit sendSingleSignals(SingleAbort);
		ChooseMode = "Andor";
	}
	
	if("KineticAcquisition"  == ChooseMode)
	{
		emit sendKineticSignals(KineticAbort);
		ChooseMode = "Andor";
	}

	if("VideoAcquisition"  == ChooseMode)
	{
		emit sendVideoSignals(VideoAbort); //告诉相机要停止Video
		ChooseMode = "Andor";
	}

}

void AndorSoftware::on_action_EMExposure_triggered()
{
		EMExposure *emexposure = new EMExposure;
		connect(this,SIGNAL(sendemexposureEMable(bool)),emexposure,SLOT(receiveemexposureEMable(bool)));
		connect(this,SIGNAL(sendemexposureEMValue(int)),emexposure,SLOT(receiveemexposureEMableValue(int)));
		connect(emexposure,SIGNAL(sendandorsoftwareEMableValue(int)),this,SLOT(receiveandorsoftwareEMValue(int)));

		connect(this,SIGNAL(sendEMValueRange(int,int)),emexposure,SLOT(receiveEMValueRange(int,int)));
		connect(emexposure,SIGNAL(sendEMabletoandorsoftware(bool)),this,SLOT(reciveEMableOK(bool)));
		emexposure->show();
}

void AndorSoftware::on_action_About_triggered()  // 关于
{
	QMessageBox  AboutBox;
	QPixmap iconImg(".//Resources//xidian.png");
	QIcon icon(iconImg);
	QString sCaption = QStringLiteral("基于Andor相机的契伦科夫光成像数据采集、处理、融合与仿真平台 \n\n本软件由西安电子科技大学负责开发。如果您有好的意见，请联系\n 西安电子科技大学，生命科学与技术学院光学成像研究小组\n 版权保留@！");
	AboutBox.setWindowIcon(icon);
	AboutBox.setWindowTitle("The information about of the Software");
	AboutBox.setText(sCaption);
	AboutBox.exec();
}

void AndorSoftware::on_action_QT_triggered()  //关于QT
{
	QMessageBox::aboutQt(this,"About Qt");
}

void AndorSoftware::on_action_Help_triggered()  //帮助
{



}

void AndorSoftware::on_pushButton_CoolerOn_clicked()
{
	QString txt=ui.lineEdit_TempSetting->text();//获得输入的记录
	int temperature=txt.toInt();
	emit sendTemperatureSetting(temperature,true);


}

void AndorSoftware::on_pushButton_CoolerOff_clicked()
{
	int errorValue;
    errorValue=CoolerOFF();
    if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( tr("Could not switch cooler off") );
		
	}
    else
	{
		emit sendTemperatureSetting(5,false);
		gblCooler=FALSE;
		ui.textEdit_Information->append( tr("Temperature control is disabled") );
	}
}

void AndorSoftware::closeEvent( QCloseEvent * event )
{
	CoolerOFF();
    int temperature;
    GetTemperature(&temperature);
    if(temperature<0)
	{
		emit sendTemperatureSetting(0,false);
		return;
	}
    else
	{
		  if(Shutter_ONOFF=FALSE)
		  {
            this->close();
		  }
		  int openclose,ttl,shutter,errorValue;
			  shutter=2;
	          ttl=0;
	          openclose=27;
	          errorValue=SetShutter(ttl,shutter,openclose,openclose);
			if(errorValue==DRV_SUCCESS)
			{
				 ShutDown();
                 this->close();
			}
    }
}

void AndorSoftware::reciveAquisitionSignals(unsigned int sig)
{
	QString fExposure = QString("%1").arg(setfExposure);
	switch (sig)
	{
	case SetExposureTimeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetSingleExposureTimeError") );
		ui.label_DisplayImage->setText("");
		break;
	case SetAcquisitionModeError:

		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetSingleAcquisitionModeError") );
		ui.label_DisplayImage->setText("");
		break;
	case SetReadModeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetSingleReadModeError") );
		ui.label_DisplayImage->setText("");
		break;
	case SetTriggerModeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetSingleTriggerModeError") );
		ui.label_DisplayImage->setText("");
		break;
	case SetImageError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetSingleImageError") );
		ui.label_DisplayImage->setText("");
		break;
	case StartAcquisitionError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>StartSingleAcquisitionError") );
		ui.label_DisplayImage->setText("");
		break;
	case AcquisitionErrors:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SingleAcquisitionErrors") );
		ui.label_DisplayImage->setText("");
		break;
	case AcuisitionCompleted:
		ui.textEdit_AndorStatus->append( tr("<html><font color=green>SingleAcquisitionCompleted") );
		PaintImage();
		break;
	case TempModeSetError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SingleTempModeSetError") );
		ui.label_DisplayImage->setText("");
		break;
	case SetEMError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SingleEMSetError") );
		break;
	case SetParametersOK:
		ui.textEdit_AndorStatus->append( tr("ExposureTime is ") );
		ui.textEdit_AndorStatus->moveCursor(QTextCursor::End);
		ui.textEdit_AndorStatus->insertPlainText(fExposure);
		ui.textEdit_AndorStatus->append( tr("Single Scan Selected") );
		ui.textEdit_AndorStatus->append( tr("ReadMode is Image") );
		ui.textEdit_AndorStatus->append( "Trigger set to 0" );
		ui.textEdit_AndorStatus->append( "Temperature Mode set to 0" );
		break;
	default:
		break;
	};
}

void AndorSoftware::reciveKineticImg(unsigned int sig)
{
	QString fExposure = QString("%1").arg(setfExposure);
	switch (sig)
	{
	case SetExposureTimeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetKineticExposureTimeError") );
		break;
	case SetAcquisitionModeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetKineticAcquisitionModeError") );
		break;
	case SetReadModeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetKineticReadModeError") );
		break;
	case StartKineticImgError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>Set number kinetics error") );
		break;
	case SetNumberKineticsError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>Set kinetic cycle time error") );
		break;
	case SetEMError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>KineticEMSetError") );
		break;
	case SetParametersOK:
		ui.textEdit_AndorStatus->append( tr("ExposureTime is ") );
		ui.textEdit_AndorStatus->moveCursor(QTextCursor::End);
		
		ui.textEdit_AndorStatus->insertPlainText(fExposure);
		ui.textEdit_AndorStatus->append( tr("Kinetic Scan Selected") );
		ui.textEdit_AndorStatus->append( tr("ReadMode is Image") );
		ui.textEdit_AndorStatus->append( "Trigger set to 0" );
		ui.textEdit_AndorStatus->append( "Temperature Mode set to 0" );
		break;
	case AcquireImageDataOK:
		ui.textEdit_AndorStatus->append( "<html><font color=green>OneAcquisition is Done!!!" );
		KineticImageData();
		KineticNumber++;
		break;
	default:
		break;
	}

}

void AndorSoftware::reciveVideoSignals(unsigned int sig)
{
	QString fExposure = QString("%1").arg(setfExposure);
	switch (sig)
	{
	case SetAcquisitionModeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetVideoAcquisitionModeError") );
		break;
	case SetExposureTimeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetVideoExposureTimeError") );
		break;
	case SetKineticCycleTimeError:
		ui.textEdit_AndorStatus->append(tr("<html><font color=red>SetVideoKineticCycleTimeError"));
		break;
	case SetReadModeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetVideoReadModeError") );
		break;
	case SetTriggerModeError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetVideoTriggerModeError") );
		break;
	case SetImageError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>SetVideoImageError") );
		break;
	case StartAcquisitionError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>StartVideoAcquisitionError") );
		break;
	case AcquisitionErrors:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>VideoAcquisitionErrors") );
		break;
	case TempModeSetError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>VideoTempModeSetError") );
		break;
	case SetEMError:
		ui.textEdit_AndorStatus->append( tr("<html><font color=red>VideoEMSetError") );
		break;
	case SetParametersOK:
		ui.textEdit_AndorStatus->append( tr("ExposureTime is ") );
		ui.textEdit_AndorStatus->moveCursor(QTextCursor::End);
		ui.textEdit_AndorStatus->insertPlainText(fExposure);
		ui.textEdit_AndorStatus->append( tr("Video Mode Selected") );
		ui.textEdit_AndorStatus->append( tr("ReadMode is Image") );
		ui.textEdit_AndorStatus->append( tr("SetKineticCycleTime is 0") );
		ui.textEdit_AndorStatus->append( "Trigger set to 0" );
		ui.textEdit_AndorStatus->append( "Temperature Mode set to 0" );
		break;
	case VideoDataOK:
		VideoImage();
		break;

	default:
		break;
	};
}

void AndorSoftware::reciveTempSignals(QString str)
{
	ui.label_DisplayTemp->setText(str);
}

void AndorSoftware::KineticImageData()
{
	
	int size,errorValue;
	size=AllocateBuffers(gblXPixels,gblYPixels);
    errorValue=GetAcquiredData16(pImageArray,size);
    
	filename1 = QString::number(KineticNumber+1);

	Fullfilename = KineticFliepathName+filename1 +".tif";
	
	QByteArray ba = Fullfilename.toLatin1();  
	char *spath = ba.data(); 
	SaveAsTiff(spath,"GREY.PAL",1,1);
	emit sendKineticSignals(KineticDataOK);	


}

void AndorSoftware::VideoImage()
{
	PaintImage();
	emit sendVideoSignals(VideoDataOK); //告诉相机一次采集结束，准备下次采集。	
}

void AndorSoftware::chooseImage(int m)
{
	if(m > KineticNumber)
		m = 1;	
	ui.spinBox_ChoseImage->setValue(m);

//	KineticFliepathName
//	QString ss = "D:\\libin\\Kinetic\\";
	filename1 = QString::number(chooseNumberImage+1);
//	QString ss2 = QString::number(chooseNumberImage+1);
	chooseNumberImage++;
	if(chooseNumberImage <= KineticNumber)
	{
		Fullfilename = KineticFliepathName+filename1 +".tif";
//		Fullfilename = ss + ss2 +".tif";
		QImage *kineticimage = new QImage;
		kineticimage->load(Fullfilename);
		QImage newImg = kineticimage->scaled(ui.label_DisplayImage->width(), ui.label_DisplayImage->height());
		ui.label_DisplayImage->setPixmap(QPixmap::fromImage(newImg));
	}
	else
	{
		chooseNumberImage = 0; //重新显示第一张图
	}
}

void AndorSoftware::PaintImage()
{
	int 		size;
	int 		errorValue;
	size=gblXPixels*gblYPixels;
	// only allocate if necessary
	if(!pImageArray)
  	pImageArray=(WORD*) malloc(size*sizeof(WORD)); // Allocate memory for image data. Size is returned
													// for GetAcquiredData which needs the buffer size
	errorValue=GetAcquiredData16(pImageArray,size); //将相机数据存到内存中
	if(errorValue!=DRV_SUCCESS)
	{
		ui.textEdit_Information->append( "Vedio acquisition error! " );
	}
	//以下是进行数据的处理并显示到屏幕上
	int Start = 0;
	float xscale, yscale, zscale, modrange;
	double dTemp;
	int width, height;
	int i, j, x, z, iTemp;
	uchar *DataArray;
	long 			MaxValue=1;
	long            MinValue=65536;
	if( pImageArray!=NULL)
	{
		// Find max value and scale data to fill rect
		for(i=0;i<(gblXPixels*gblYPixels);i++)
		{
			if(pImageArray[i]>MaxValue)
					MaxValue=pImageArray[i];
			if(pImageArray[i]<MinValue)
					MinValue=pImageArray[i];
		}

		modrange     = MaxValue - MinValue;
		width        = 561;
		if(width%4)                 // width must be a multiple of 4,
		width += (4-width%4);     // otherwise StretchDIBits has problems
		height       = 551;
		xscale       = (float)(gblXPixels)/(float)(width);
		yscale       = (256.0)/(float)modrange;
		zscale       = (float)(gblYPixels)/(float)(height);
		DataArray = (uchar*)malloc(width * height * sizeof(uchar));
		memset(DataArray, 255, width * height);
		for (i = 0; i < height; i++)
		{
			z = (int)(i * zscale);
			for (j = 0; j < width; j++)
			{
				x = (int)(j * xscale);
				dTemp = ceil(yscale * (pImageArray[Start + x + z * gblXPixels] - MinValue));
				if (dTemp < 0)
					iTemp = 0;
				else if (dTemp > 256 - 1) 
					iTemp = 255;
				else 
					iTemp = (int)dTemp;
				DataArray[j + i * width] = (uchar)iTemp;
			}
		}

	}
	QPixmap resultPixmap(width,height);
	QPainter painter(&resultPixmap);
	QImage Qimg = QImage(DataArray, width, height, QImage::Format_Indexed8);  //封装QImage 
	Qimg.setColorTable(vgrayTable);
	painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
	painter.drawImage(resultPixmap.rect(),Qimg);
	ui.label_DisplayImage->setPixmap(resultPixmap);
	FreeBuffers();
	free (DataArray);
}

void AndorSoftware::on_action_scan3d_capture_triggered()
{
	QProcess::startDetached("scan3d-capture-x86.exe", QStringList());

}

void  Wchar_tToString(std::string& szDst, wchar_t *wchar)
{
	wchar_t * wText = wchar;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wText,-1,NULL,0,NULL,FALSE);// WideCharToMultiByte的运用
	char *psText;  // psText为char*的临时数组，作为赋值给std::string的中间变量
	psText = new char[dwNum];
	WideCharToMultiByte (CP_OEMCP,NULL,wText,-1,psText,dwNum,NULL,FALSE);// WideCharToMultiByte的再次运用
	szDst = psText;// std::string赋值
	delete []psText;// psText的清除
}

int  AllocateBuffers(int gblXPixels,int gblYPixels)
{
	int size;
	FreeBuffers();
	size=gblXPixels*gblYPixels;
	if(!pImageArray)
		pImageArray=(WORD*) malloc(size*sizeof(WORD));
	return size;
}

void FreeBuffers(void)
{
	if(pImageArray)
	{
		free(pImageArray);
		pImageArray=NULL;
	}
} 

AndorSoftware::~AndorSoftware()
{

}
