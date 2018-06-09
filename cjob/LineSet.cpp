#include "stdafx.h"
#include "LineSet.h"

extern vector<GraphicObject*> gRenderObjects;
void flushWindow();
extern unsigned gPlayingSpeed;

LineSet::LineSet(vector<Point> t_p, float t_line_width, Gdiplus::Color color)
{
	for (auto i = t_p.begin(); i != t_p.end(); ++i)
		p.push_back(*i);
	line_width = t_line_width;
	mColor = color;
}

LineSet::LineSet(LineSet & l1)
{
	for (auto i = l1.p.begin(); i != l1.p.end(); ++i)
		p.push_back(*i);
	line_width = l1.line_width;
	mColor = l1.mColor;
}

void LineSet::DrawLineSet()
{
	gRenderObjects.push_back(this);
	flushWindow();
	Sleep(gPlayingSpeed);
}

float LineSet::get_line_width()
{
	return line_width;
}

Gdiplus::Color LineSet::get_color()
{
	return mColor;
}

vector<Point>& LineSet::get_point()
{
	return p;
}

float LineSet::Length()
{
	float sum=0;
	for (auto i = p.begin(); i != p.end() - 1; ++i)
		sum += Distance_P(*i, *(i + 1));
	return sum;
}

BOOL LineSet::IF_Selfing()
{
	vector<Line> new_line;
	for (auto i = p.begin(); i != p.end() - 1; ++i)
		new_line.push_back(Line(*i, *(i + 1)));//将折线的所有线段都放入容器中
	for (auto i = new_line.begin(); i != new_line.end() - 1; ++i)
	{
		if (Valid_Intersect(*i, *(i + 1)))
			return true;
	}
	if (Valid_Intersect(*(new_line.end() - 1), *new_line.begin()))
		return true;
	else
		return false;
}
