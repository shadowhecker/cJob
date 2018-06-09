#include "stdafx.h"
#include "Line.h"

extern vector<GraphicObject*> gRenderObjects;
void flushWindow();
extern unsigned gPlayingSpeed;

void Line::DrawLine()
{
	gRenderObjects.push_back(this);
	flushWindow();
	Sleep(gPlayingSpeed);
}

void Line::Set_Line(float x1, float y1, float x2, float y2, float m_width, Gdiplus::Color color)
{
	p1.set(x1, y1, m_width, color);
	p2.set(x2, y2, m_width, color);
	width = m_width;
	mColor = color;
}

Point& Line::get_head()
{
	return p1;
}

Point Line::get_tail()
{
	return p2;
}

float Line::get_width()
{
	return width;
}

Gdiplus::Color Line::get_color()
{
	return mColor;
}

float Line::Length()
{
	return (float)sqrt(pow(p2.get_x() - p1.get_x(), 2) + pow(p2.get_y() - p2.get_y(), 2));
}

int dblcmp(double a, double b)
{
	if (fabs(a - b) <= 1E-6)
		return 0;
	if (a>b)
		return 1;
	else
		return -1;
}

int Line::IF_inline(Point & c1)
{
	return dblcmp(scalar_product(p1 - c1, p2 - c1), 0);
}

BOOL Line::IF_leftright(Point & c1)
{
	return Outer_product(p2 - p1, c1 - p1);
}

Point Intersect(Line &L1,Line &L2)//��L1,L2�Ƿ��ཻ
{
	float line_x, line_y;//�����ߵ��ཻ��
	float s1, s2, s3, s4;
	int d1, d2, d3, d4;
	Point p;
	d1 = dblcmp(s1 = ab_cross_ac(L1.p1, L1.p2, L2.p1), 0);
	d2 = dblcmp(s2 = ab_cross_ac(L1.p1, L1.p2, L2.p2), 0);
	d3 = dblcmp(s3 = ab_cross_ac(L2.p1, L2.p2, L1.p1), 0);
	d4 = dblcmp(s4 = ab_cross_ac(L2.p1, L2.p2, L1.p2), 0);
	if ((d1^d2) == -2 && (d3^d4) == -2)//�淶�ཻ���ཻ�����߶���
	{
		p.set((L2.p1.mx*s2 - L2.p2.mx*s1) / (s2 - s1), (L2.p1.my*s2 - L2.p2.my*s1) / (s2 - s1));
		return p;
	}
	if (d1 == 0 && L1.IF_inline(L2.p1) <= 0)//�ཻ��L2�Ķ���
		return L2.p1;
	if (d2 == 0 && L1.IF_inline(L2.p2) <= 0)//�ཻ��L2��β��
		return L2.p2;
	if (d3 == 0 && L2.IF_inline(L1.p1) <= 0)//�ཻ��L1�Ķ���
		return L1.p1;
	if (d4 == 0 && L2.IF_inline(L1.p2) <= 0)//�ཻ��L2��β��
		return L1.p2;
	return p;//������ཻ���ؿյ㣻
}

BOOL Valid_Intersect(Line & L1, Line & L2)
{
	float line_x, line_y;//�����ߵ��ཻ��
	float s1, s2, s3, s4;
	int d1, d2, d3, d4;
	d1 = dblcmp(s1 = ab_cross_ac(L1.p1, L1.p2, L2.p1), 0);
	d2 = dblcmp(s2 = ab_cross_ac(L1.p1, L1.p2, L2.p2), 0);
	d3 = dblcmp(s3 = ab_cross_ac(L2.p1, L2.p2, L1.p1), 0);
	d4 = dblcmp(s4 = ab_cross_ac(L2.p1, L2.p2, L1.p2), 0);
	if ((d1^d2) == -2 && (d3^d4) == -2)//�淶�ཻ���ཻ�����߶���
	{
		return 1;
	}
	if (d1 == 0 && L1.IF_inline(L2.p1) <= 0)//�ཻ��L2�Ķ���
		return 0;
	if (d2 == 0 && L1.IF_inline(L2.p2) <= 0)//�ཻ��L2��β��
		return 0;
	if (d3 == 0 && L2.IF_inline(L1.p1) <= 0)//�ཻ��L1�Ķ���
		return 0;
	if (d4 == 0 && L2.IF_inline(L1.p2) <= 0)//�ཻ��L2��β��
		return 0;
	return -1;//������ཻ���ؿյ㣻
}



