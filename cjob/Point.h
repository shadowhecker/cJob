#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include "DSGraphic.h"
#include <math.h>
using namespace std;

class Point : public DSPoint//�̳���DSPoint
{
public:
	Point():DSPoint(0,0,0,0) {}
	Point(Point& tmp) :DSPoint(tmp.mx, tmp.my, tmp.mSize, tmp.mColor) {}
	explicit Point(const Point& tmp1) :DSPoint(tmp1.mx, tmp1.my, tmp1.mSize, tmp1.mColor) {}
	Point(float x, float y, float size=5.0, Gdiplus::Color m_color= Gdiplus::Color::Red) :DSPoint(x, y, size=5.0, m_color) {}
	virtual ~Point() {}
	void DrawPoint();
	void set(float x, float y, float size=5.0, Gdiplus::Color m_color= Gdiplus::Color::Red);
	float get_x();
	float get_y();
	float get_size();
	Gdiplus::Color get_color();
	BOOL operator==(const Point& b); 
	Point& operator=(const Point& b);
	float vector_module();//��ȡ������ģ
	float Distance(Point& p2);//������֮�����
	friend float Distance_P(Point& p1, Point& p2);
	friend float scalar_product(Point &p1,Point &p2);//���������ڻ�
	friend float Outer_product(Point &p1,Point &p2);//�����������
	friend Point operator-(Point& a,Point& b);
	friend float ab_cross_ac(Point a, Point b, Point c);//��ab��ac�Ĳ��
};