#include "deskMedia.h"


deskMedia::deskMedia()
{
	m_flag = false;
	m_runFlag = true;
	m_bQueueL = false;
	m_bQueueP = false;
}
deskMedia::~deskMedia()
{
	m_strMedia.clear();
	m_strMediaName.clear();

}
int deskMedia::help(string path)
{
	m_strMedia.clear();
	m_strMediaName.clear();
	ifstream infile;//定义文件变量  
	infile.open(path, ios::in);//打开txtPath为文件路径  
	if (!infile)
	{
		return -1;
	}
	string temp;
	int n_icount = 0;
	while (getline(infile, temp)) //读取一行，while循环，直到文件最后一行  
	{
		if (n_icount <= 4)
		{
			m_strMedia.push_back(temp);
		}
		else
		{
			m_strMediaName.push_back(temp);
		}
		n_icount++;
	}
	//for (int i = 0; i < m_strMedia.size(); i++)
	//{
	//	cout << m_strMediaName[i] << endl;
	//}
	//for (int i = 0; i < m_strMediaName.size(); i++)
	//{
	//	cout << m_strMediaName[i] << endl;
	//}
	infile.close();//关闭文件 
	clientID_1 = atoi(m_strMedia[0].c_str());
	clientID_2 = atoi(m_strMedia[1].c_str());
	RectWidth = atoi(m_strMedia[2].c_str());
	RectHeight = atoi(m_strMedia[3].c_str());
	fps = atoi(m_strMedia[4].c_str());

	m_iCount = -1;
	m_iMinVideoNum = 0;
	m_iMaxVideoNum = m_strMediaName.size()/2;
	return 0;
}
void deskMedia::Initialize(PM_Hub * g_PM_Hub, string path)
{
	help(path);
	m_PM_Hub = g_PM_Hub;
	m_PM_Hub->SetUpClient(clientID_1, 0, 0, RectWidth, RectHeight, 1);
	queue1 = new CQueue(m_PM_Hub);
	queue2 = new CQueue(m_PM_Hub);
	//m_PM_Hub->SendLoaded();//发送使能
	
}
int deskMedia::run(int flag)
{
	if (m_runFlag == true)//这个标志位表示可以进行上下切换
	{
		if (flag == 1)
		{
			m_iCount++;
			if (m_iCount >= m_iMaxVideoNum)
			{
				m_iCount = m_iMaxVideoNum-1;
			}
			
		}
		else if (flag == 0)
		{
			m_iCount--;
			if (m_iCount <= m_iMinVideoNum)
			{
				m_iCount = m_iMinVideoNum;
			}
		}
		else if (flag < 0)
		{
			return -1;
		}
		/*********旋转按钮过场*****************/
		if (m_iCount % 2 == 0)
		{
			queue2Q();
			return 0;
		}
		else if (m_iCount % 2 == 1)
		{
			queue1Q();
			return 0;
		}
	}
	else
	{
		return -1;
	}

}

///-------------------------------------------------------------------------------------------------
/// <summary>	/***************判断影片是否结束***************************. </summary>
///
/// <remarks>	Admin, 2017/8/11. </remarks>
///
/// <returns>	True if over, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool deskMedia::isOver()
{
	bool m_getQueueIdFlag = false;
	if (m_iCount % 2 == 0)
	{
		if (m_bQueueP == true) //判断偶数编号片子
		{
			int queue2Id = queue2->GetQueueID();
			m_getQueueIdFlag = m_PM_Hub->GetItemEndFeedback(queue2Id, m_strMediaName[m_iCount*2]);
			if (m_getQueueIdFlag == true)
			{
				if (m_flag == true)
				{
					deleteQueue();
					queue2L();			
				}
				if (m_flag==false&&m_flag==false)//表示一轮未过去
				{
					queue2L();
				}		
			}
		}
		if (m_bQueueL==true)
		{
			m_getQueueIdFlag = getQueueId(queue2);
		}
	}
	else if (m_iCount % 2 == 1)
	{
		if (m_bQueueP == true)
		{
			int queue1Id = queue1->GetQueueID();
			m_getQueueIdFlag = m_PM_Hub->GetItemEndFeedback(queue1Id, m_strMediaName[m_iCount*2]);
			if (m_getQueueIdFlag == true)
			{
				deleteQueue();		
				queue1L();
			}
		}
		if (m_bQueueL==true)
		{
			m_getQueueIdFlag = getQueueId(queue1);
		}
	}
	return m_getQueueIdFlag;
}

///-------------------------------------------------------------------------------------------------
/// <summary>	/**************获取片子结束标志位****************. </summary>
///
/// <remarks>	Admin, 2017/8/11. </remarks>
///
/// <param name="queue">	[in,out] If non-null, the queue. </param>
///
/// <returns>	True if it succeeds, false if it fails. </returns>
///-------------------------------------------------------------------------------------------------

bool deskMedia::getQueueId(CQueue *queue)
{
	int queueId = queue->GetQueueID();
	bool getQueueIdFlag;
	getQueueIdFlag = m_PM_Hub->GetItemEndFeedback(queueId, m_strMediaName[m_iCount*2+1]);
	if (getQueueIdFlag == true)
	{
		m_runFlag = true;
	}
	if (m_iCount == m_iMaxVideoNum-1)
	{
		m_iCount = m_iMinVideoNum;
		m_flag = true;
	}
	return getQueueIdFlag;
}
void deskMedia::clear()
{
	m_runFlag = true;
	m_bQueueP = true;
	m_bQueueL = false;
	queue1 = NULL;
	m_PM_Hub = NULL;
	g_vecQueue.clear();
}

///-------------------------------------------------------------------------------------------------
/// <summary>	/********过场***************. </summary>
///
/// <remarks>	Admin, 2017/8/11. </remarks>
///-------------------------------------------------------------------------------------------------

void deskMedia::queue1Q()
{	
	queue2->EraseQueue(1);
	m_PM_Hub->SendLoaded();//发送使能
	queue1->NewQueue(-1, 1, clientID_1, 0, 1);
	queue1->AppendQueue(m_strMediaName[m_iCount*2], "cmp", fps, 0, 0, 1, 1);
	queue1->SetCoords(RectWidth / 4, RectHeight / 4, 1, RectWidth / 4, RectHeight / 4, 1);
	queue1->SetStartTime(-1, 1);
	queue1->MediaSeek(0, 0, 1);
	m_PM_Hub->SendLoaded();

	m_runFlag = false;
	m_bQueueP = true;
	m_bQueueL = false;
}

/****************************/
void deskMedia::queue2Q()
{
	queue1->EraseQueue(1);
	m_PM_Hub->SendLoaded();//发送使能
	queue2->NewQueue(-1, 1, clientID_1, 0, 1);
	queue2->AppendQueue(m_strMediaName[m_iCount*2], "cmp", fps, 0, 0, 1, 1);
	queue2->SetCoords(RectWidth / 4, RectHeight / 4, 1, RectWidth / 4, RectHeight / 4, 1);
	queue2->SetStartTime(-1, 1);
	queue2->MediaSeek(0, 0, 1);

	m_runFlag = false;
	m_bQueueP = true;
	m_bQueueL = false;
}

///-------------------------------------------------------------------------------------------------
/// <summary>	/*********视频效果************. </summary>
///
/// <remarks>	Admin, 2017/8/11. </remarks>
///-------------------------------------------------------------------------------------------------

void deskMedia::queue1L()
{
	queue1->EraseQueue(1);
	m_PM_Hub->SendLoaded();//发送使能
	queue1->NewQueue(-1, 1, clientID_1, 0, 1);
	queue1->AppendQueue(m_strMediaName[m_iCount*2+1], "cmp", fps, 0, 0, 1, 1);
	queue1->SetCoords(RectWidth / 2, RectHeight / 2, 1, RectWidth / 4, RectHeight / 4, 1);
	queue1->SetStartTime(-1, 1);
	queue1->MediaSeek(0, 0, 1);
	m_PM_Hub->SendLoaded();

	m_bQueueP = false;
	m_bQueueL = true;
}
void deskMedia::queue2L()
{
	queue2->EraseQueue(1);
	m_PM_Hub->SendLoaded();//发送使能
	queue2->NewQueue(-1, 1, clientID_1, 0, 1);
	queue2->AppendQueue(m_strMediaName[m_iCount*2+1], "cmp", fps, 0, 0, 1, 1);
	queue2->SetCoords(RectWidth / 2, RectHeight / 2, 1, RectWidth / 4, RectHeight / 4, 1);
	queue2->SetStartTime(-1, 1);
	queue2->MediaSeek(0, 0, 1);
	m_PM_Hub->SendLoaded();

	m_bQueueP = false;
	m_bQueueL = true;
}

/******删除m_PM_Hub****************/
void deskMedia::deletePM()
{
	if (!g_vecQueue.empty())
	{
		for (int i = 0; i < g_vecQueue.size(); i++)
		{
			queue1 = g_vecQueue[i];
			queue2 = g_vecQueue[i];
			if (queue1 != NULL)
			{
				delete queue1;
				queue1 = NULL;
			}
			if (queue2 != NULL)
			{
				delete queue1;
				queue2 = NULL;
			}
		}
		g_vecQueue.clear();
	}
	if (m_PM_Hub != NULL)
	{
		delete m_PM_Hub;
		m_PM_Hub = NULL;
	}
}


/***********删除queue*************************/
void deskMedia::deleteQueue()
{
	if (m_flag == true && m_iCount % 2 == 0)
	{
		for (int i = 0; i < g_vecQueue.size(); i++)
		{
			queue1 = g_vecQueue[i];
			if (queue1 != NULL)
			{
				delete queue1;
				queue1 = NULL;
			}
		}
		g_vecQueue.clear();
	}
	if (m_flag == false && m_iCount != 0)
	{
		if (m_iCount % 2 == 0)
		{
			for (int i = 0; i < g_vecQueue.size(); i++)
			{
				queue1 = g_vecQueue[i];
				if (queue1 != NULL)
				{
					delete queue1;
					queue1 = NULL;
				}
			}
			g_vecQueue.clear();
		}
	}
	if (m_iCount % 2 == 1)
	{
		for (int i = 0; i < g_vecQueue.size(); i++)
		{
			queue2 = g_vecQueue[i];
			if (queue2 != NULL)
			{
				delete queue1;
				queue2 = NULL;
			}
		}
		g_vecQueue.clear();
	}
}