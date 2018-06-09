#include "stdafx.h"
#include "Circle.h"

extern vector<GraphicObject*> gRenderObjects;
void flushWindow();
extern unsigned gPlayingSpeed;


void Circle::DrawCircle()
{
	gRenderObjects.push_back(this);
	flushWindow();
	Sleep(gPlayingSpeed);
}

Point Circle::get_center()
{
	return center;
}

float Circle::get_radius()
{
	return radius;
}

float Circle::get_width()
{
	return width;
}

Gdiplus::Color Circle::get_color()
{
	return mColor;
}

void Circle::Set_Circle(Point p1, float l,float t_width, Gdiplus::Color color)
{
	center = p1;
	radius = l;
	width = t_width;
	mColor = color;
}

float Circle::Acreage()
{
	return PI*radius*radius;
}

int Circle::IF_incirle(Point & p1)
{
	if (p1.Distance(center) > radius)
		return 1;
	else if (p1.Distance(center) == radius)
		return 0;
	else
		return -1;
}

int Cirle_intersect(Circle & c1, Circle & c2)
{
	if (c1.center.Distance(c2.center) < (c1.radius + c2.radius))
		return 0;//相交
	if (c1.center.Distance(c2.center) == (c1.radius + c2.radius))
		return 1;//外切
	if (c1.center.Distance(c2.center) == abs(c1.radius - c2.radius))
		return 2;//内切
	if (c1.center.Distance(c2.center) > (c1.radius + c2.radius))
		return 3;//外离
	if (c1.center.Distance(c2.center) < (c1.radius + c2.radius))
		return 4;//内含
	return 0;
}
