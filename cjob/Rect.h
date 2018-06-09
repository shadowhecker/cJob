#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include "DSGraphic.h"
#include <math.h>
#include "Point.h"
using namespace std;

class Rectangle_Real :public GraphicObject
{
public:
	Rectangle_Real(){}
	Rectangle_Real(float x, float y, float m_width, float m_higth, float m_line_width = 2.0, Gdiplus::Color color = Gdiplus::Color::Red) :
		rect_center(x, y), width(m_width), higth(m_higth), line_width(m_line_width) {mColor = color;}
	Rectangle_Real(Rectangle_Real& t_rect):rect_center(t_rect.rect_center), width(t_rect.width), higth(t_rect.higth), line_width(t_rect.line_width) { mColor = t_rect.mColor; }
	virtual ~Rectangle_Real() {}
	void DrawRect();
	GraphicType getGraphicType() { return rRect; }
	Point get_rect_center();
	float get_width();
	float get_higth();
	Gdiplus::Color get_color();
	float get_line_width();
	void Set_Rect(Point& p1, float m_width, float m_higth, float m_line_width, Gdiplus::Color color);
	BOOL IF_inrect(Point& p1);//判断点是否在矩形范围内
	friend BOOL Rect_intersect(Rectangle_Real& r1, Rectangle_Real& r2);//判断两个矩形是不是相交
private:
	Point rect_center;
	float width;//长
	float higth;//宽
	float line_width;//线条宽度
};