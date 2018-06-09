#include "stdafx.h"
#include "Rect.h"

extern vector<GraphicObject*> gRenderObjects;
void flushWindow();
extern unsigned gPlayingSpeed;

void Rectangle_Real::DrawRect()
{
	gRenderObjects.push_back(this);
	flushWindow();
	Sleep(gPlayingSpeed);
}

Point Rectangle_Real::get_rect_center()
{
	return rect_center;
}

float Rectangle_Real::get_width()
{
	return width;
}

float Rectangle_Real::get_higth()
{
	return higth;
}

Gdiplus::Color Rectangle_Real::get_color()
{
	return mColor;
}

float Rectangle_Real::get_line_width()
{
	return line_width;
}

void Rectangle_Real::Set_Rect(Point & p1, float m_width, float m_higth, float m_line_width, Gdiplus::Color color)
{
	rect_center = p1;
	width = m_width;
	higth = m_higth;
	line_width = m_line_width;
	mColor = color;
}

BOOL Rectangle_Real::IF_inrect(Point & p1)
{
	float line_x1, line_x2, line_y1, line_y2;
	line_x1 = rect_center.get_x() - width / 2;
	line_x2 = rect_center.get_x() + width / 2;
	line_y1 = rect_center.get_y() - higth / 2;
	line_y2 = rect_center.get_y() + higth / 2;
	if (p1.get_x() >= line_x1 && p1.get_x() <= line_x2 && p1.get_y() >= line_y1 && p1.get_y() <= line_y2)
		return true;//在圆内
	else
		return false;//在圆外
}

BOOL Rect_intersect(Rectangle_Real & r1, Rectangle_Real & r2)
{
	if (abs(r2.rect_center.mx - r1.rect_center.mx) < (r1.width + r2.width) / 2 &&
		abs(r2.rect_center.my - r1.rect_center.my) < (r1.higth + r2.higth) / 2)
		return true;//矩形相交
	return false;
}
