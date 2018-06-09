#pragma once
#include "Point.h"
#include <windows.h>
#include <string>
#include <vector>
#include "DSGraphic.h"
#include <math.h>
#include"Point.h"
#include"Line.h"
using namespace std;

class LineSet :public GraphicObject
{
public:
	LineSet() {}
	LineSet(vector<Point> t_p, float t_line_width = 5.0, Gdiplus::Color color = Gdiplus::Color::Red);
	LineSet(LineSet& l1);
	virtual ~LineSet() {}
	GraphicType getGraphicType() { return rLineSet; }
	void DrawLineSet();
	virtual float get_line_width();
	virtual Gdiplus::Color get_color();
	virtual vector<Point>& get_point();
	float Length();
	BOOL IF_Selfing();//����1��ʾ�Խ�,����0��ʾ���Խ�
protected:
	vector<Point> p;
	float line_width;
};