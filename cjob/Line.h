#pragma once
#include "Point.h"
#include <windows.h>
#include <string>
#include <vector>
#include "DSGraphic.h"
#include <math.h>
using namespace std;

class Line :public GraphicObject
{
public:
	Line() :GraphicObject(),p1(),p2(),width(0){}
	Line(Line& L1) :p1(L1.p1), p2(L1.p2), width(L1.width) { mColor = L1.mColor; }
	Line(float x1, float y1, float x2, float y2, float m_width, Gdiplus::Color color) :p1(x1, y1, m_width, color), p2(x2, y2, m_width, color), width(m_width) { mColor = color; }
	Line(Point tp_1, Point tp_2) :p1(tp_1), p2(tp_2), width(tp_1.get_size()) { mColor = tp_1.get_color(); }
	virtual ~Line() {}
	GraphicType getGraphicType() { return rLine; }
	void DrawLine();
	void Set_Line(float x1, float y1, float x2, float y2, float m_width, Gdiplus::Color color);
	Point& get_head();
	Point get_tail();
	float get_width();
	Gdiplus::Color get_color();
	float Length();
	int IF_inline(Point& c1);//判断点是否在线段上//返回>0不在线段上，=0端点重合，<0在线段上
	int IF_leftright(Point& c1);//判断点在线的左边还是右边,返回>0在右边，返回<0在左边,返回==0在延长线上
	friend Point Intersect(Line &L1,Line &L2);//判断本条线是否与L1相交
	friend int Valid_Intersect(Line &L1, Line &L2);//判断两条线是规范相交还是不规范相交//返回1规范相交，返回-1是不相交，返回0是不规范相交
private:
	Point p1;//第一个点
	Point p2;//终点的点
	float width;//线段的宽度
};