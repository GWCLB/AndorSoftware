#ifndef EMADVANCED_H
#define EMADVANCED_H

#include <QtWidgets/QDialog>
#include "ui_emadvanced.h"

#include <QFile>

class EMAdvanced : public QDialog
{
	Q_OBJECT

public:
	EMAdvanced(QWidget *parent = 0);
	~EMAdvanced();

private:
	Ui::EMAdvancedClass ui;

signals:

	void sendEMAdvanced(bool );

private slots:
	void on_checkBox_Advanced_EM_clicked();


};

#endif // EMADVANCED_H
