#include "deskMedia.h"


deskMedia::deskMedia()
{
	m_flag = false;
	m_runFlag = false;
}


deskMedia::~deskMedia()
{
	fileName.clear();
}
int deskMedia::help(string path)
{
	fileName.clear();
	ifstream infile;//定义文件变量  
	infile.open(path, ios::in);//打开txtPath为文件路径  
	if (!infile)
	{
		return -1;
	}
	string temp;
	while (getline(infile, temp)) //读取一行，while循环，直到文件最后一行  
	{
		fileName.push_back(temp);
	}
	for (int i = 0; i < fileName.size(); i++)
	{
		cout << fileName[i] << endl;
	}
	infile.close();//关闭文件 
	clientID = atoi(fileName[0].c_str());
	RectWidth = atoi(fileName[1].c_str());
	RectHeight = atoi(fileName[2].c_str());
	fps = atoi(fileName[3].c_str());

	m_iVideoNum = 3;
	m_iMinVideoNum = 3;
	m_iMaxVideoNum = fileName.size();
	return 0;
}
void deskMedia::Initialize(PM_Hub * g_PM_Hub, string path)
{
	help(path);
	m_PM_Hub = g_PM_Hub;
	m_PM_Hub->SetUpClient(clientID, 0, 0, RectWidth, RectHeight, 1);

	//m_PM_Hub->SendLoaded();//发送使能

}
int deskMedia::run(int flag)
{
	if (flag == 1)
	{
		m_iVideoNum++;
		if (m_iVideoNum >= m_iMaxVideoNum)
		{
			m_iVideoNum = m_iMaxVideoNum - 1;
		}
		VideoName = fileName[m_iVideoNum];
	}
	else if (flag == 0)
	{
		m_iVideoNum--;
		if (m_iVideoNum <= m_iMinVideoNum)
		{
			m_iVideoNum = m_iMinVideoNum - 1;
		}
		VideoName = fileName[m_iVideoNum];
	}
	else if (flag < 0)
	{
		return -1;
	}
	if (m_flag == false)
	{
		queue1 = new CQueue(m_PM_Hub);
		queue1->NewQueue(-1, 1, clientID, 0, 1);
		queue1->AppendQueue(VideoName, "cmp", fps, 0, 0, 1, 1);
		queue1->SetCoords(RectWidth / 2, RectHeight / 2, 1, RectWidth, RectHeight, 1);
		queue1->SetStartTime(-1, 1);
		queue1->MediaSeek(0, 0, 1);
		m_PM_Hub->SendLoaded();
		m_flag = true;
		m_runFlag = true;
		return 0;
	}
	else if (m_flag == true && m_iVideoNum == m_iMinVideoNum)
	{
		return -1;
	}
	else if (m_flag == true && m_iVideoNum == m_iMaxVideoNum)
	{
		return -1;
	}
	else if (m_flag == true && m_iVideoNum <m_iMaxVideoNum&& m_iVideoNum>m_iMinVideoNum)
	{
		endVideoPlay();

		queue1 = new CQueue(m_PM_Hub);
		queue1->NewQueue(-1, 1, clientID, 0, 1);
		queue1->AppendQueue(VideoName, "cmp", fps, 0, 0, 1, 1);
		queue1->SetCoords(RectWidth / 2, RectHeight / 2, 1, RectWidth, RectHeight, 1);
		queue1->SetStartTime(-1, 1);
		queue1->MediaSeek(0, 0, 1);
		m_PM_Hub->SendLoaded();
		m_flag = true;
		m_runFlag = true;
		return 0;
	}

}

void deskMedia::endVideoPlay()
{
	queue1->EraseQueue(1);
	m_PM_Hub->SendLoaded();//发送使能
	m_runFlag = false;
}

bool deskMedia::isOver()
{
	bool getQueueIdFlag = false;
	if (m_runFlag == true)
	{
		int queue1Id = queue1->GetQueueID();
		getQueueIdFlag = m_PM_Hub->GetItemEndFeedback(queue1Id, VideoName);
		if (getQueueIdFlag == true)
		{
			endVideoPlay();
			if (m_iVideoNum == m_iMaxVideoNum - 1)
			{
				m_iVideoNum = m_iMinVideoNum;
			}
		}
	}
	return getQueueIdFlag;
}
void deskMedia::clear()
{
	m_runFlag = false;
	fileName.clear();
	queue1 = NULL;
	m_PM_Hub = NULL;
}
