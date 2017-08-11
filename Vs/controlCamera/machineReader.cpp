#include "machineReader.h"
#include "FastUDP\\MFastUDP.h"


machineReader::machineReader()
{
	m_fOriginalPosition = 0;
	m_fSpeend = 0;
	m_bIsOk = false;
	m_pUDP = new MFastUDP;
	m_pUDP->Initialize("..\\data\\config\\network_config.ini");
}


machineReader::~machineReader()
{
	m_fOriginalPosition = 0;
}


void machineReader::currentPosition(float position)
{
	m_fCurrentPosition = position;
	cout << "m_fOriginalPosition:" << m_fOriginalPosition << endl;
	cout << "m_fCurrentPosition:" << m_fCurrentPosition << endl;

	m_fSpeend = m_fCurrentPosition - m_fOriginalPosition;
	if (m_fSpeend > 0)
	{
		m_fCurrentPositionFlag = 1;
	}
	else if (m_fSpeend<0)
	{
		m_fCurrentPositionFlag = 0;
	}
	else
	{
		m_fCurrentPositionFlag = -1;
	}
	if (abs(m_fSpeend) >= m_fThreshold)
	{
		m_bIsOk = true;
	}
	else
	{
		m_bIsOk = false;
	}
	m_fOriginalPosition = m_fCurrentPosition;

}

struct rotateMsg
{
	unsigned char			head[16];
	unsigned int            len;
	unsigned int            msgtype;
	int                     data;
	unsigned char			tail[8];
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
	if (nLen)
	{
		m_fCurrentPosition = szMsg.data;

		currentPosition(m_fCurrentPosition);
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

