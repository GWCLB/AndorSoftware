#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H
#include <QThread>
#include <QMutex>

#define SetExposureTimeError 1989
#define SetAcquisitionModeError 1990
#define SetReadModeError 1991
#define SetTriggerModeError 1992
#define SetImageError 1993
#define StartAcquisitionError 1994
#define AcquisitionErrors 1995
#define AcuisitionCompleted 1996
#define SetParametersOK 1997

#define TempModeSetError 1998
#define TempNotStable 1999
#define TempStable 2000

#define SetKineticCycleTimeError 2001
#define StartKineticImgError 2002
#define SetNumberKineticsError 2003
#define AcquireImageDataOK   2005
#define GetParameters 2006


#define KineticDataOK 2999
#define KineticAbort  3000
#define VideoDataOK   3001
#define VideoAbort	  3002
#define SingleAbort	  3003
#define SingleAbortError 3004
#define SingleAbortOK 3005

#define SetEMError    3006

//temperature QThread
class tempratureThread:public QThread
{
	Q_OBJECT
public:
	tempratureThread();
	int getAndSetTemperature(int temperature);
	void run();
private:
	QMutex mutex;
	bool temperatureInitialed,coolerIsOn;
	int errorValue;
	int currentTemp,settingTemp;
	QString tempInfoStr;
signals:
	void sentTempatureSettingInfo(QString str);

private slots:
	void recieveTemperatureSetting(int temp,bool coolerOnOff);
};
//Single Scan QThread
class acqThread:public QThread
{
	Q_OBJECT
public:
	acqThread();
	int getAndSetParameters(int gblXPixcels,int gblYPixels, float fExposure,int acquisitionMode,int readMode,int trig,int hBinning,int vBinning,int EMvalue);
	void run();

private:
	bool parametersInitialed;
	int errorValue;
	bool SingleAbortAcquisition;
signals:
	void sendAquisitionSettingInfo(unsigned int);

private slots:
	void receiveSingleSignal(unsigned int);
};
// Kinetic Series QThread
class KineticThread:public QThread
{
	Q_OBJECT
public:
	KineticThread();
	int getAndorkineticParameters(int acquisitionMode,int readMode,float fExposure,int gblXPixcels,int gblYPixels,int noScans,float kineticCycleTime,int KineticNumber,int EMvalue);
	void run();

	bool KineticPrepareOk;
	bool KineticAbortAcquisition;

private:
	bool parametersInitialed;
	bool AcquireImageData(void);
	int errorValue;
	float setfExposure;
	float setKineticTotalTime;
	float setKineticCycleTime;
	int setKineticNumber;

signals:

	void sendKineticsettingInfo(unsigned int);

private slots:
	void receiveKineticSignal(unsigned int);

};


//Video QThread 
class VideoThread:public QThread
{
	Q_OBJECT
public:
	VideoThread();
	int getAndVideoSetParameters(int gblXPixcels,int gblYPixels,float fExposure,int acquisitionMode,int readMode,int trig,int hBinning,int vBinning,int EMvalue);
	void run();
	int errorValue;
	int IntervalVideoTime;

	bool VideoAbortAcquisition;
	bool VedioPrepareOk;

private:
	bool VideoparametersInitialed;
signals:
	void sendVideoSettingInfo(unsigned int);

private slots:
	void receiveVideoSignal(unsigned int);

};

#endif