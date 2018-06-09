#include "stdafx.h"
#include "Triangle.h"
#include "Line.h"

extern vector<GraphicObject*> gRenderObjects;
void flushWindow();
extern unsigned gPlayingSpeed;

void Triangle_Real::DrawTriangle()
{
	gRenderObjects.push_back(this);
	flushWindow();
	Sleep(gPlayingSpeed);
}

Point Triangle_Real::get_A()
{
	return A;
}

Point Triangle_Real::get_B()
{
	return B;
}

Point Triangle_Real::get_C()
{
	return C;
}

float Triangle_Real::get_line_width()
{
	return line_width;
}

void Triangle_Real::Set_A(Point & p1)
{
	A = p1;
}

void Triangle_Real::Set_B(Point & p2)
{
	B = p2;
}

void Triangle_Real::Set_C(Point & p3)
{
	C = p3;
}

void Triangle_Real::Set_line_width(float t_line_width)
{
	line_width = t_line_width;
}

Gdiplus::Color Triangle_Real::get_color()
{
	return mColor;
}

BOOL Triangle_Real::IF_intriangle(Point & p1)
{
	int a1, a2, a3;
	Line *line1 = new Line(A, B);
	Line *line2 = new Line(B, C);
	Line *line3 = new Line(C, A);
	a1 = line1->IF_leftright(p1);
	a2 = line2->IF_leftright(p1);
	a3 = line3->IF_leftright(p1);
	if (a1 > 0 && a2 > 0 && a3 > 0)
		return true;
	else
		return false;
}

float Triangle_Real::Acreage_Triangle()
{
	float l1, l2, l3 ,l4;
	l1 = A.Distance(B);
	l2 = B.Distance(C);
	l3 = C.Distance(A);//计算三个边长
	l4 = (l1 + l2 + l3) / 2;
	return sqrt(l4*(l4 - l1)*(l4 - l2)*(l4 - l3));
}

BOOL Triangle_Real::C_Anti_Clock()
{
	Line *line1 = new Line(A, B);
	if (line1->IF_leftright(C) > 0)
		return true;//顺时针
	else
		return false;//逆时针
}
