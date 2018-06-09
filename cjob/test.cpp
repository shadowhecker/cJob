// example.cpp : 定义控制台应用程序的入口点。
//

#include "DSGraphic.h"


void main()
{
	showWindow();//创建并显示窗口
	setPlayingSpeed(500);//设置动画播放速度(间隔，以毫秒为单位）
	
	//drawPoint(100, 100, 3, Gdiplus::Color::Red);
	//drawPoint(200, 200, 4);
	void* pL = drawLine(250, 120, 500, 400, 2, Gdiplus::Color::Blue);
	drawLine(560, 380, 120, 154);
	string s = "地信1503 张三";
	drawText("地信1503 张三", 10, 10, 24, Gdiplus::Color::BlueViolet);
	
	clearObject(pL);
	//clearWindow();
	void* p1 = 0, *p2 = 0;
	for (int i = 1; i < 100; ++i)
	{
		p2 = p1;
		p1 = drawPoint(10*i, 10*i, 3, Gdiplus::Color::Red);
		if (i > 3)
		{
			clearObject(p2);
		}
	}
	system("pause");
}

