// example.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "DSGraphic.h"


void main()
{
	showWindow();//��������ʾ����
	setPlayingSpeed(500);//���ö��������ٶ�(������Ժ���Ϊ��λ��
	
	//drawPoint(100, 100, 3, Gdiplus::Color::Red);
	//drawPoint(200, 200, 4);
	void* pL = drawLine(250, 120, 500, 400, 2, Gdiplus::Color::Blue);
	drawLine(560, 380, 120, 154);
	string s = "����1503 ����";
	drawText("����1503 ����", 10, 10, 24, Gdiplus::Color::BlueViolet);
	
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

