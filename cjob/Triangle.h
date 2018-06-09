#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include "DSGraphic.h"
#include <math.h>
#include "Point.h"

using namespace std;

class Triangle_Real :public GraphicObject
{
public:
	Triangle_Real() {}
	Triangle_Real(Point t_A, Point t_B, Point t_C, float t_line_width = 5.0, Gdiplus::Color color = Gdiplus::Color::Red) :
		A(t_A), B(t_B), C(t_C), line_width(t_line_width) {mColor = color;}
	Triangle_Real(Triangle_Real& t_triangle) :A(t_triangle.A), B(t_triangle.B), C(t_triangle.C),
		line_width(t_triangle.line_width) {mColor = t_triangle.mColor;}
	virtual ~Triangle_Real() {}
	void DrawTriangle();
	GraphicType getGraphicType() { return rTriangle; }
	Point get_A();
	Point get_B();
	Point get_C();
	float get_line_width();
	void Set_A(Point& p1);
	void Set_B(Point& p2);
	void Set_C(Point& p3);
	void Set_line_width(float t_line_width);
	Gdiplus::Color get_color();
	BOOL IF_intriangle(Point& p1);//返回>0在三角形内
	float Acreage_Triangle();
	BOOL C_Anti_Clock();//返回>0顺时针,返回<0逆时针
private:
	Point A;
	Point B;
	Point C;
	float line_width;
};