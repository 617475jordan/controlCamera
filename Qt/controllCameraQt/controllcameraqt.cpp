#include "controllcameraqt.h"

controllCameraQt::controllCameraQt(QWidget *parent)
	: QMainWindow(parent)
{
	timer = new QTimer(this);


	ui.setupUi(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(openClicked())); 

	
}

controllCameraQt::~controllCameraQt()
{

}

void controllCameraQt::currentTime()
{

}
void controllCameraQt::progressBarAcceleration()
{
	ui.progressBar_3->setValue(0);

}
void controllCameraQt::progressBarDecelerateion()
{
	ui.progressBar_2->setValue(0);

}
void controllCameraQt::pushButton_3()
{
	if (m_initialFlag == true)
	{
		m_iButtonFlag = 1;
		videoFlag = true;
		m_iNewPlay = 0;
	}
	
}
void controllCameraQt::pushButton_4()
{
	if (m_initialFlag == true)
	{
		m_iButtonFlag = 0;
		m_iNewPlay = 0;
	}
	
}
void controllCameraQt::Initialize()
{
	ui.progressBar->setValue(0);
	ui.progressBar_2->setValue(0);
	ui.progressBar_3->setValue(0);
	g_PM_Hub = new PM_Hub("testPlayer");
	deskMedia.Initialize(g_PM_Hub, "..\\data\\playVideo.txt");
	//deskMedia.run();
	//machineReader.Initialize();
	timer->start(5);
	ui.label_3->setText("start");
	m_initialFlag = true;
	
}
void controllCameraQt::openClicked()
{
	if (deskMedia.isOver() == false)                      //ÅÐ¶ÏÓ°Æ¬ÊÇ·ñ½áÊø
	{
		if (m_iNewPlay == 0)
		{
			deskMedia.run(m_iButtonFlag);
		}
	}
	++m_iNewPlay;
}
void controllCameraQt::closeClicked()
{
	if (videoFlag == true && m_initialFlag==true)
	{
		timer->stop();
		deskMedia.deletePM();
		videoFlag = false;
		ui.label_3->setText("over");
	}

}