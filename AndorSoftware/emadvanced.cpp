#include "emadvanced.h"


EMAdvanced::EMAdvanced(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.label_Dispaly->adjustSize();
	ui.label_Dispaly->setGeometry(QRect(10, 10, 400, 27*4));  //ËÄ±¶ÐÐ¾à
	ui.label_Dispaly->setWordWrap(true);
	ui.label_Dispaly->setAlignment(Qt::AlignTop);

	ui.label_Dispaly->setText("<html><font color=red>Typically, optimal signal to noise ratio and dynamic range is achieved between x1 to x300\nEM Gain. Higher gains of > x300 are recommended for single photon counting only. Before using higher levels, you should ensure  that  light  levels  do  not  exceed  the  regime  of tens of photons per pixel, otherwise accelerated ageing of the sensor can occur.");
}

void EMAdvanced::on_checkBox_Advanced_EM_clicked()
{
	if(Qt::Checked == ui.checkBox_Advanced_EM->checkState())
	{
//		ui.label_Dispaly->setText("111");
		emit sendEMAdvanced(true);
	
	}
	if(Qt::Unchecked == ui.checkBox_Advanced_EM->checkState())
	{
//		ui.label_Dispaly->setText("2222");
		emit sendEMAdvanced(false);
	}

}

EMAdvanced::~EMAdvanced()
{

}
