#pragma once
#include <opencv_all.h>
class MFastUDP;

class machineReader
{
public:
	machineReader();
	~machineReader();
	void currentPosition(float position);
	void Initialize();
	void run();
	void clear();
	int n_fCurrentPositionFlag();
	bool isOK();
private:
	float  m_fCurrentPosition;
	float  m_fOriginalPosition;
	float m_fSpeend;
	int m_fCurrentPositionFlag;
	
	int nLen;
	bool m_bIsOk;
	float m_fThreshold = 1000;
private:
	MFastUDP*				m_pUDP;
	
};




