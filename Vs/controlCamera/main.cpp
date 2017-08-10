#include "machineReader.h"
#include <opencv_all.h>
#include "deskMedia.h"
#include "PM_Hub.h"

int main()
{
	machineReader machineReader;
	deskMedia deskMedia;
	PM_Hub *g_PM_Hub = new PM_Hub("testPlayer");
	deskMedia.Initialize(g_PM_Hub, "..\\data\\playVideo.txt");//������Ƶֹͣ�ڵ�0֡
	//deskMedia.run();                                          //������Ƶ
	machineReader.Initialize();                               //��ת��������ʼ��
	while (1)
	{
		if (deskMedia.isOver() == false)                      //�ж�ӰƬ�Ƿ����
		{
			machineReader.run();                              //������ת����
			//�����µ�λ��
			if (machineReader.isOK() == true)
			{
				deskMedia.run(machineReader.n_fCurrentPositionFlag());
			}
		}
		cout << "isOk:" << machineReader.isOK() << endl;
		cout << "Flag:" << machineReader.n_fCurrentPositionFlag() << endl;
	}
	return 0;
}


