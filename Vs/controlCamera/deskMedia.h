#pragma once
#include "PM_Hub.h"
#include <iostream>
#include<sstream>     
#include<iostream>    
#include<fstream>     
#include<string>
#ifdef _DEBUG
#pragma comment(lib, "CommuDll30D.lib")
#pragma comment(lib, "CommonUtil31D.lib")
#pragma comment(lib, "PlayerManager31D.lib")
#pragma comment(lib, "GlobalSyncTimeManager31D.lib")
#else

#pragma comment(lib, "CommuDll30.lib")
#pragma comment(lib, "CommonUtil31.lib")
#pragma comment(lib, "PlayerManager31.lib")
#pragma comment(lib, "GlobalSyncTimeManager31.lib")
#endif

class deskMedia
{
public:
	deskMedia();
	~deskMedia();
	void clear();
	int run(int flag);
	void Initialize(PM_Hub * g_PM_Hub, string path);
	bool  isOver();
	void endVideoPlay();
	int help(string path);
private:
	CQueue *queue1;
	PM_Hub * m_PM_Hub;

	int clientID, RectWidth, RectHeight;

	int fps;
	int m_iVideoNum;
	int m_iMaxVideoNum;
	int m_iMinVideoNum;
	bool m_flag;
	bool getQueueIdFlag = false;
	bool m_runFlag;
	string VideoName;
	vector<string> fileName;
};

