#ifndef CONTROLLCAMERAQT_H
#define CONTROLLCAMERAQT_H

#include <QtWidgets/QMainWindow>
#include <qt_all.h>
#include <opencv_all.h>
#include <iostream>
#include "ui_controllcameraqt.h"
#include "deskMedia.h"
#include "PM_Hub.h"
#include "machineReader.h"
class controllCameraQt : public QMainWindow
{
	Q_OBJECT

public:
	controllCameraQt(QWidget *parent = 0);
	~controllCameraQt();
	void progressBarClicked();
	void progressBarAcceleration();
	void progressBarDecelerateion();
public:
	machineReader machineReader;
	deskMedia deskMedia;
	PM_Hub *g_PM_Hub;
	int m_iButtonFlag = -1;
	bool videoFlag = false;
	bool m_initialFlag = false;
	int m_iNewPlay=0;
private:
	Ui::controllCameraQtClass ui;	
	QTimer    *timer;

private slots:
void Initialize();
void openClicked();
void closeClicked();
void currentTime();
void pushButton_3();
void pushButton_4();
};

#endif // CONTROLLCAMERAQT_H
