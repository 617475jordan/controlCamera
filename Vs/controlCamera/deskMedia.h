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
	void deleteQueue();
	void deletePM();
	void queue1Q();
	void queue2Q();
	void queue1L();
	void queue2L();
	int help(string path);
	bool getQueueId(CQueue *queue);
private:
	CQueue *queue1, *queue2;
	PM_Hub * m_PM_Hub;

	int clientID_1, clientID_2, RectWidth, RectHeight, fps;
	int m_iCount;
	int m_iMaxVideoNum;
	int m_iMinVideoNum;
	bool m_flag;
	bool m_runFlag;
	vector<string> m_strMedia;
	vector<string> m_strMediaName;
	vector<CQueue*> g_vecQueue;
	int m_iMedia = 4;
	bool m_bQueueL;
	bool m_bQueueP;

};

