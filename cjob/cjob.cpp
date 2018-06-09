// cjob.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DSGraphic.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "Triangle.h"
#include "LineSet.h"
#include "Polygon.h"
extern vector<GraphicObject*> gRenderObjects;
int _tmain(int argc, _TCHAR* argv[])
{
	showWindow();//��������ʾ����
	setPlayingSpeed(500);//���ö��������ٶ�(������Ժ���Ϊ��λ��
	
	//drawPoint(100, 100, 3, Gdiplus::Color::Red);
	//drawPoint(200, 200, 4);
	//#void* pL = drawLine(250, 120, 500, 400, 2, Gdiplus::Color::Blue);
	//#drawLine(560, 380, 120, 154);
	string s = "����1503 ����";
	drawText("����1503 ����", 10, 10, 24, Gdiplus::Color::BlueViolet);
	
	//#clearObject(pL);
	//#clearWindow();
	//#void* p1 = 0, *p2 = 0;
	//#for (int i = 1; i < 100; ++i)
	//#{
	//#	p2 = p1;
	//#	p1 = drawPoint(10*i, 10*i, 3, Gdiplus::Color::Red);
	//#	if (i > 3)
	//#	{
	//#		clearObject(p2);
	//#	}
	//#}
	Point *cpoint = new Point(300, 220, 3, Gdiplus::Color::Red);
	cpoint->DrawPoint();
	drawText("��1", cpoint->get_x() - 30 - cpoint->get_size(), cpoint->get_y() - 30 - cpoint->get_size());
	float module = cpoint->vector_module();//��ȡ��1������
	string s1 = "��1��ģ=" + to_string(module);
	drawText(s1, 700, 10);
	Point *cpoint2 = new Point(600, 490, 4, Gdiplus::Color::Yellow);
	cpoint2->DrawPoint();
	drawText("��2", cpoint2->get_x() - 30 - cpoint2->get_size(), cpoint2->get_y() - 30 - cpoint2->get_size());
	float distance = cpoint->Distance(*cpoint2);
	string s2 = "��1�͵�2�ľ���=" + to_string(distance);
	drawText(s2, 700, 30);
	float scalar = scalar_product(*cpoint,*cpoint2);
	string s3 = "��1�͵�2���ڻ�=" + to_string(scalar);
	drawText(s3, 700, 50);
	float Outer = Outer_product(*cpoint,*cpoint2);
	string s4 = "��1�͵�2�����=" + to_string(Outer);
	drawText(s4, 700, 70);
	Point *phead_1 = new Point(480, 540);
	Point *ptail_1 = new Point(410, 134);
	Line *cLine = new Line(*phead_1, *ptail_1);
	cLine->DrawLine();
	int result1 = cLine->IF_leftright(*cpoint);
	int result2 = cLine->IF_leftright(*cpoint2);
	if (result1 > 0)
		drawText("��1���ұ�", 700, 90);
	else
		drawText("��1�����", 700, 90);
	if (result2 > 0)
		drawText("��2���ұ�", 700, 110);
	else
		drawText("��2�����", 700, 110);
	Point *phead_2 = new Point(680, 340);
	Point *ptail_2 = new Point(210, 234);
	Line *cLine2 = new Line(*phead_2, *ptail_2);
	cLine2->DrawLine();
	Point t_p = Intersect(*cLine, *cLine2);
	drawText("�����ཻ��:("+to_string((float)t_p.get_x())+","+to_string((float)t_p.get_y())+")", 600, 130);
	gRenderObjects.clear();
	Point *pCenter = new Point(210, 234);
	Circle *circle = new Circle(*pCenter,87);
	Point *pCenter2 = new Point(510, 156);
	Circle *circle2 = new Circle(*pCenter2,214,5,Gdiplus::Color::Blue);
	circle->DrawCircle();
	circle2->DrawCircle();
	Point *pPoint = new Point(111, 278);
	pPoint->DrawPoint();
	drawText("Բ1���:"+to_string(circle->Acreage()), 700, 10);
	drawText("Բ2���:" + to_string(circle2->Acreage()), 700, 30);
	if (circle->IF_incirle(*pPoint) == 1)
		drawText("����Բ��", 700, 50);
	else if (circle->IF_incirle(*pPoint) == 0)
		drawText("����Բ��",700,50);
	else
		drawText("����Բ��",700,50);
	if (Cirle_intersect(*circle, *circle2) == 0)
		drawText("��Բ�ཻ", 700, 70);
	else if (Cirle_intersect(*circle, *circle2) == 1)
		drawText("��Բ����", 700, 70);
	else if (Cirle_intersect(*circle, *circle2) == 2)
		drawText("��Բ����", 700, 70);
	else if (Cirle_intersect(*circle, *circle2) == 3)
		drawText("��Բ����", 700, 70);
	else
		drawText("��Բ�ں�", 700, 70);
	gRenderObjects.clear();
	Rectangle_Real *rect1 = new Rectangle_Real(205, 311, 100, 50);
	Rectangle_Real *rect2 = new Rectangle_Real(300, 267, 200, 150,2,Gdiplus::Color::Yellow);
	rect1->DrawRect();
	rect2->DrawRect();
	Point *p1 = new Point(194, 314);
	p1->DrawPoint();
	if (rect1->IF_inrect(*p1) > 0)
		drawText("���ھ�����", 700, 10);
	else
		drawText("���ھ�����", 700, 10);
	if (Rect_intersect(*rect1, *rect2))
		drawText("�������ཻ", 700, 30);
	else
		drawText("����������", 700, 30);
	gRenderObjects.clear();
	Point *pA = new Point(194, 121);
	pA->DrawPoint();
	Point *pB = new Point(294, 421);
	pB->DrawPoint();
	Point *pC = new Point(411, 287);
	pC->DrawPoint();
	Triangle_Real *pTriangle = new Triangle_Real(*pA, *pB, *pC);
	pTriangle->DrawTriangle();
	Point *pD = new Point(111, 111);
	pD->DrawPoint();
	if(pTriangle->IF_intriangle(*pD)>0)
		drawText("������������", 700, 10);
	else
		drawText("������������", 700, 10);
	drawText("���������:" + to_string(pTriangle->Acreage_Triangle()), 700, 30);
	if (pTriangle->C_Anti_Clock() > 0)
		drawText("˳ʱ��", 700, 50);
	else
		drawText("��ʱ��", 700, 50);
	gRenderObjects.clear();
	Point *point1 = new Point(480, 540);
	Point *point2 = new Point(410, 134);
	Point *point3 = new Point(300, 220);
	//Point *point4 = new Point(600, 490);
	//Point *point5 = new Point(680, 340);
	//Point *point6 = new Point(210, 234);
	vector<Point> Point_Sum;
	Point_Sum.push_back(*point1);
	Point_Sum.push_back(*point2);
	Point_Sum.push_back(*point3);
	//Point_Sum.push_back(*point4);
	//Point_Sum.push_back(*point5);
	//Point_Sum.push_back(*point6);
	LineSet *lineset = new LineSet(Point_Sum);
	lineset->DrawLineSet();
	if (lineset->IF_Selfing())
		drawText("�������Խ�", 700, 10);
	else
		drawText("�����߲��Խ�", 700, 10);
	drawText("�����ܳ�=" + to_string(lineset->Length()), 700, 30);
	gRenderObjects.clear();
	Point *point11 = new Point(480, 540);
	Point *point12 = new Point(410, 334);
	Point *point13 = new Point(300, 420);
	Point *point14 = new Point(370, 490);
	Point *point15 = new Point(388, 467);
	vector<Point> Point_Sum1;
	Point_Sum1.push_back(*point11);
	Point_Sum1.push_back(*point12);
	Point_Sum1.push_back(*point13);
	Point_Sum1.push_back(*point14);
	Point_Sum1.push_back(*point15);
	Polygon_Real *polygon = new Polygon_Real(Point_Sum1);
	polygon->DrawPolygon();
	if (polygon->IF_Convex())
		drawText("͹�����", 700, 10);
	else
		drawText("�������", 700, 30);
	system("pause");
	return 0;
}

