#include "machineReader.h"
#include <opencv_all.h>
#include "deskMedia.h"
#include "PM_Hub.h"

int main()
{
	machineReader machineReader;
	deskMedia deskMedia;
	PM_Hub *g_PM_Hub = new PM_Hub("testPlayer");
	deskMedia.Initialize(g_PM_Hub, "..\\data\\playVideo.txt");//运行视频停止于第0帧
	//deskMedia.run();                                          //运行视频
	machineReader.Initialize();                               //旋转编码器初始化
	while (1)
	{
		if (deskMedia.isOver() == false)                      //判断影片是否结束
		{
			machineReader.run();                              //运行旋转编码
			//更新新的位置
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


