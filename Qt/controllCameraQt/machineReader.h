#pragma once
#include <opencv_all.h>
class MFastUDP;

class machineReader
{
public:
	machineReader();
	~machineReader();
	void currentPosition(int flag,float position);
	void Initialize();
	void run();
	void clear();
	int n_fCurrentPositionFlag();
	bool isOK();
private:
	float  m_fCurrentPosition;
	float  m_fOriginalPosition;
	int m_fCurrentPositionFlag;
	float m_fAcceleration;
	float m_fDecleeration;
	int nLen;
	bool m_bIsOk;
	float m_fThreshold = 5;
private:
	MFastUDP*				m_pUDP;
	
};




