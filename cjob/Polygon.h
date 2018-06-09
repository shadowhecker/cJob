#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include "DSGraphic.h"
#include <math.h>
#include "Point.h"
#include "LineSet.h"
#include "Triangle.h"
using namespace std;

class Polygon_Real :public LineSet
{
public:
	Polygon_Real() :LineSet() {}
	Polygon_Real(vector<Point> t_p, float t_line_width = 5.0, Gdiplus::Color color = Gdiplus::Color::Red) :
		LineSet(t_p, t_line_width, color) {}
	Polygon_Real(Polygon_Real& tmp) :LineSet(tmp.p, tmp.line_width, tmp.mColor) {}
	virtual ~Polygon_Real() {}
	GraphicType getGraphicType() { return rPolygon; }
	void DrawPolygon();
	BOOL IF_Convex();//返回1凸多边形//返回0非凸多边形
};