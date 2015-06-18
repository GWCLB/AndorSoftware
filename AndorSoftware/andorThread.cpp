#include "andorThread.h"

#include <QMessageBox>
#include "ATMCD32D.H"

acqThread::acqThread()
{
	parametersInitialed=false;
	errorValue=0;
	SingleAbortAcquisition=false;
}

void acqThread::receiveSingleSignal(unsigned int sig)
{
	switch(sig)
	{

	case SingleAbortOK:
		SingleAbortAcquisition = true;
		break;
	default:
		break;
	}

}

int acqThread::getAndSetParameters(int gblXPixcels,int gblYPixels,float fExposure,int acquisitionMode,int readMode,int trig,int hBinning,int vBinning,int EMvalue)
{
	errorValue=-1;
	errorValue=SetAcquisitionMode(acquisitionMode);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendAquisitionSettingInfo(SetAcquisitionModeError);
		return 0;
	}
	errorValue=SetExposureTime(fExposure);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendAquisitionSettingInfo(SetExposureTimeError);
		return 0;
	}
	errorValue=SetReadMode(readMode);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendAquisitionSettingInfo(SetReadModeError);
		return 0;
	}
	errorValue=SetTriggerMode(trig);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendAquisitionSettingInfo(SetTriggerModeError);
		return 0;
	}
	errorValue=SetCoolerMode(0);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendAquisitionSettingInfo(TempModeSetError);
		return 0;
	}
	errorValue=SetImage(hBinning,vBinning,1,gblXPixcels,1,gblYPixels);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendAquisitionSettingInfo(SetImageError);
		return 0;
	}
	int setEMvalue = EMvalue;
	if(setEMvalue == -1)
	{		
		;												//略过，不处理。
	}
	else
	{
		errorValue=SetEMCCDGain(setEMvalue);
		if(errorValue!=DRV_SUCCESS)
		{
			emit sendAquisitionSettingInfo(SetEMError);
			return 0;
		}
	}
	parametersInitialed=true;
	return 1;
}
void acqThread::run()
{
	if (!parametersInitialed)
	{
		return;
	}
	emit sendAquisitionSettingInfo(SetParametersOK);
	errorValue=StartAcquisition();
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendAquisitionSettingInfo(StartAcquisitionError);
		AbortAcquisition();
		return;
	}
	int status=0;
	while (true)
	{
		GetStatus(&status);
		if(!SingleAbortAcquisition)
		{
			if (status==DRV_ACQUISITION_ERRORS)
			{
				emit sendAquisitionSettingInfo(AcquisitionErrors);
				AbortAcquisition();
				break;
			}
			if (status==DRV_ACQUIRING)
			{
				continue;
			}
			if (status==DRV_IDLE)
			{
				emit sendAquisitionSettingInfo(AcuisitionCompleted);
				break;
			}
		}
		else
		{
			if(status==DRV_ACQUIRING)
			{
				errorValue=AbortAcquisition();
				if(errorValue!=DRV_SUCCESS)
				{
					emit sendAquisitionSettingInfo (SingleAbortError);
					ShutDown();
					break;
				}
				else
				{
					emit sendAquisitionSettingInfo (SingleAbortOK); 
					break;
				}
			 }
		}
	}
	parametersInitialed=false;
}

//temperature 构造函数
tempratureThread::tempratureThread()
{
	temperatureInitialed=false;
	errorValue=0;
	currentTemp=0;
	settingTemp=0;
	tempInfoStr="";
	coolerIsOn=false;
}
int tempratureThread::getAndSetTemperature(int temperature)
{
	if(coolerIsOn!=true)
	{
		temperatureInitialed=false;
		CoolerOFF();
		return 0;
	}
	errorValue=-1;
	settingTemp=temperature;
	errorValue=SetTemperature(settingTemp);
	if(errorValue!=DRV_SUCCESS)
	{
		tempInfoStr="SetTemperatureError";
		emit sentTempatureSettingInfo(tempInfoStr);
		temperatureInitialed=false;
		CoolerOFF();
		coolerIsOn=false;
		return 0;
	}
	temperatureInitialed=true;
	CoolerON();
	return 1;
}
void tempratureThread::recieveTemperatureSetting(int temp,bool coolerOnOff)
{
	coolerIsOn=coolerOnOff;
	getAndSetTemperature(temp);
}
void tempratureThread::run()
{
	unsigned int status;
	while (true)
	{
		if(temperatureInitialed!=true )
		{
			GetTemperature(&currentTemp);
			tempInfoStr="Current: "+QString::number(currentTemp,10);
			emit sentTempatureSettingInfo(tempInfoStr);                                        
			sleep(1);
			continue;
		}
 		GetTemperature(&currentTemp);
		tempInfoStr="Object: "+QString::number(settingTemp,10)+"\nCurrent: "+QString::number(currentTemp,10);
 		emit sentTempatureSettingInfo(tempInfoStr);
 		sleep(1);
	}
}


//连拍...

KineticThread::KineticThread()
{
	parametersInitialed=false;
	KineticAbortAcquisition=false;
	KineticPrepareOk=true;
	errorValue=0;
	setKineticTotalTime = 0;
	setKineticCycleTime = 0;
	setKineticNumber = 0;

}

void KineticThread::receiveKineticSignal(unsigned int sig)
{
	switch(sig)
	{

	case KineticDataOK:
		KineticPrepareOk=true;
		break;
	case KineticAbort:
		KineticAbortAcquisition = true;
		break;
	default:
		break;
	}

}


int  KineticThread::getAndorkineticParameters(int acquisitionMode,int readMode, float fExposure,int gblXPixels,int gblYPixels,int TotalTime,float kineticCycleTime, int KineticNumber,int EMvalue)
{
	errorValue=-1;
	setKineticTotalTime = TotalTime;
	setKineticCycleTime = kineticCycleTime;
	setfExposure = fExposure;
	setKineticNumber = KineticNumber;
	errorValue=SetAcquisitionMode(acquisitionMode);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendKineticsettingInfo(SetAcquisitionModeError);
		return 0;
	}
	errorValue=SetExposureTime(fExposure);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendKineticsettingInfo(SetExposureTimeError);
		return 0;
	}
	errorValue=SetReadMode(readMode);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendKineticsettingInfo(SetReadModeError);
		return 0;
	}
	int trig = 0;
	errorValue=SetTriggerMode(trig);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendKineticsettingInfo(SetTriggerModeError);
		return 0;
	}
	errorValue=SetCoolerMode(0);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendKineticsettingInfo(TempModeSetError);
		return 0;
	}
	int hBinning = 1, vBinning = 1;
	errorValue=SetImage(hBinning,vBinning,1,gblXPixels,1,gblYPixels);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendKineticsettingInfo(SetImageError);
		return 0;
	}
	int setEMvalue = EMvalue;
	if(setEMvalue == -1)
	{		
		;												//略过，不处理。
	}
	else
	{
		errorValue=SetEMCCDGain(setEMvalue);
		if(errorValue!=DRV_SUCCESS)
		{
			emit sendKineticsettingInfo(SetEMError);
			return 0;
		}
	}
	parametersInitialed=true;
	return 1;
}



void KineticThread::run()
{
	if (!parametersInitialed)
	{
		return;
	}
	emit sendKineticsettingInfo(SetParametersOK);

	int status;
	int cout = 0;
	while(true)
	{
		
		if(KineticPrepareOk)                   //Kinetic  Ok
		{
			if(KineticAbortAcquisition)       //Kinetic Abort
			{		
				KineticAbortAcquisition=false;
				break;
			}


			errorValue=StartAcquisition();
			if(errorValue!=DRV_SUCCESS)
			{
				emit sendKineticsettingInfo(StartKineticImgError);
				AbortAcquisition();
			}
			else
			{
				while(true)
				{
					GetStatus(&status);
					if (status==DRV_ACQUISITION_ERRORS)
					{
						AbortAcquisition();
						break;
					}
					if (status==DRV_ACQUIRING)
					{
						continue;
					}
					if (status==DRV_IDLE)
					{
						emit sendKineticsettingInfo(AcquireImageDataOK); //Success
						KineticPrepareOk = false;
						break;
					}
				}
			}
		}

		if(setKineticNumber == -1)
		{
			sleep(setKineticCycleTime);
			cout++;
			if((setKineticCycleTime+setfExposure)*cout >= setKineticTotalTime)
			{
				break;
			}

		}

		if(setKineticTotalTime == -1)
		{
			sleep(setKineticCycleTime);
			cout++;
			if(cout >= setKineticNumber)
			{
				break;
			}

		}
	}
	parametersInitialed=false;
	AbortAcquisition();



}



//相机 Video
VideoThread::VideoThread()
{
	VideoparametersInitialed=false;
	errorValue=0;
	VideoAbortAcquisition=false;
	VedioPrepareOk=true;
	IntervalVideoTime=0;
}

void VideoThread::receiveVideoSignal(unsigned int sig)
{
	switch(sig)
	{

	case VideoDataOK:
		VedioPrepareOk=true;
		break;
	case VideoAbort:
		VideoAbortAcquisition = true;
		break;
	default:
		break;
	}
}


int VideoThread::getAndVideoSetParameters(int gblXPixels,int gblYPixels,float fExposure,int acquisitionMode,int readMode,int trig,int hBinning,int vBinning,int EMvalue)
{
	errorValue=-1;
	errorValue=SetAcquisitionMode(acquisitionMode);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendVideoSettingInfo(SetAcquisitionModeError);
		return 0;
	}
	errorValue=SetExposureTime(fExposure);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendVideoSettingInfo(SetExposureTimeError);
		return 0;
	}
	errorValue=SetReadMode(readMode);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendVideoSettingInfo(SetReadModeError);
		return 0;
	}
	errorValue=SetTriggerMode(trig);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendVideoSettingInfo(SetTriggerModeError);
		return 0;
	}
	errorValue=SetCoolerMode(0);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendVideoSettingInfo(TempModeSetError);
		return 0;
	}
	errorValue=SetImage(hBinning,vBinning,1,gblXPixels,1,gblYPixels);
	if(errorValue!=DRV_SUCCESS)
	{
		emit sendVideoSettingInfo(SetImageError);
		return 0;
	}
	int setEMvalue = EMvalue;
	if(setEMvalue == -1)
	{		
		;														//不作处理
	}
	else
	{
		errorValue=SetEMCCDGain(setEMvalue);
		if(errorValue!=DRV_SUCCESS)
		{
			emit sendVideoSettingInfo(SetEMError);
			return 0;
		}
	}
	VideoparametersInitialed=true;
	return 1;
}
	

void VideoThread::run()
{
	if (!VideoparametersInitialed)
	{
		return;
	}
	int status = 0;
	while(true)
	{
		
		if(VedioPrepareOk)                   //Video Ok
		{
			if(VideoAbortAcquisition)       //Video Abort
			{		
				VideoAbortAcquisition=false;
				break;
			}


			errorValue=StartAcquisition();
			if(errorValue!=DRV_SUCCESS)
			{
				emit sendVideoSettingInfo(StartAcquisitionError);
				AbortAcquisition();
			}
			else
			{
				while(true)
				{
					GetStatus(&status);
					if (status==DRV_ACQUISITION_ERRORS)
					{
						AbortAcquisition();
						break;
					}
					if (status==DRV_ACQUIRING)
					{
						continue;
					}
					if (status==DRV_IDLE)
					{
						emit sendVideoSettingInfo(VideoDataOK); //Success
						VedioPrepareOk = false;
						break;
					}
				}
			}
		}		
	}
	VideoparametersInitialed=false;
	AbortAcquisition();
}