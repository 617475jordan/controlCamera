#include "machineReader.h"
#include "FastUDP\\MFastUDP.h"


machineReader::machineReader()
{
	m_fOriginalPosition = 0;
	m_bIsOk = false;
	m_pUDP = new MFastUDP;
	m_pUDP->Initialize("..\\data\\config\\network_config.ini");
}


machineReader::~machineReader()
{
	m_fOriginalPosition = 0;
}


void machineReader::currentPosition(int flag,float position)
{
	m_fCurrentPosition = position;
	cout << "m_fOriginalPosition:" << m_fOriginalPosition << endl;
	cout << "m_fCurrentPosition:" << m_fCurrentPosition << endl;
	if (flag == 1)
	{
		m_fAcceleration = m_fCurrentPosition - m_fOriginalPosition;
		if (m_fAcceleration < 0)
			m_fAcceleration = m_fAcceleration + 200;
		if (m_fAcceleration >= m_fThreshold)
		{
			m_bIsOk = true;
		}
		else
		{
			m_bIsOk = false;
		}
		m_fOriginalPosition = m_fCurrentPosition;
	}
	else if (flag == 0)
	{
		m_fDecleeration = m_fOriginalPosition - m_fCurrentPosition;
		if (m_fDecleeration < 0)
			m_fDecleeration = m_fDecleeration + 200;
		if (m_fDecleeration >= m_fThreshold)
		{
			m_bIsOk = true;
		}
		else
		{
			m_bIsOk = false;
		}
		m_fOriginalPosition = m_fCurrentPosition;

	}
}

struct rotateMsg
{
	unsigned char			head;
	unsigned char	len;
	unsigned char			data;
	unsigned char	flag;
	char			crc[2];
	char			tail;
};
void machineReader::Initialize()
{
	rotateMsg szMsg;
	nLen = m_pUDP->GetResultMessage((char*)&szMsg, sizeof(rotateMsg));
	m_fOriginalPosition = szMsg.data;
}

void machineReader::run()
{	
	rotateMsg szMsg;
	nLen = m_pUDP->GetResultMessage((char*)&szMsg, sizeof(rotateMsg));
	if(nLen)
	{
		m_fCurrentPositionFlag = szMsg.flag;
		m_fCurrentPosition = szMsg.data;
		currentPosition(m_fCurrentPositionFlag, m_fCurrentPosition);
	}
}
void machineReader::clear()
{
	nLen = 0;
}
int machineReader::n_fCurrentPositionFlag()
{
	return  m_fCurrentPositionFlag;
}

bool machineReader::isOK()
{
	return m_bIsOk;
}

