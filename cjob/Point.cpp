#include "stdafx.h"
#include "Point.h"
extern vector<GraphicObject*> gRenderObjects;
void flushWindow();
extern unsigned gPlayingSpeed;
void Point::DrawPoint()
{
	gRenderObjects.push_back(this);
	flushWindow();
	Sleep(gPlayingSpeed);
}

void Point::set(float x, float y, float size, Gdiplus::Color m_color)
{
	mx = x;
	my = y;
	mSize = size;
	mColor = m_color;
}

float Point::get_x()
{
	return mx;
}

float Point::get_y()
{
	return my;
}

float Point::get_size()
{
	return mSize;
}

Gdiplus::Color Point::get_color()
{
	return mColor;
}

BOOL Point::operator==(const Point & b)
{
	if (mx == b.mx&&my == b.my&&mSize == b.mSize)
		return true;
	else
		return false;
}

Point & Point::operator=(const Point & b)
{
	mx = b.mx;
	my = b.my;
	mSize = b.mSize;
	mColor = b.mColor;
	return *this;
}

float Point::vector_module()
{
	return sqrt(pow(mx, 2) + pow(my, 2));
}

float Point::Distance(Point & p2)
{
	return (float)sqrt(pow(p2.get_x()-mx,2)+pow(p2.get_y()-my,2));
}

float Distance_P(Point & p1, Point & p2)
{
	return (float)sqrt(pow(p2.mx - p1.mx, 2) + pow(p2.my - p1.my, 2));
}

float scalar_product(Point &p1,Point &p2)
{
	return p1.mx*p2.mx+p1.my*p2.my;
}

float Outer_product(Point &p1,Point & p2)
{
	return p1.mx*p2.my-p1.my*p2.mx;
}

Point operator-(Point & a, Point & b)
{
	Point tmp(b.mx - a.mx,b.my - a.my,a.mSize,a.mColor);
	return tmp;
}

float ab_cross_ac(Point a, Point b, Point c)
{
	return Outer_product(b - a, c - a);
}


