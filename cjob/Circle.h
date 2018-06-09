#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include "DSGraphic.h"
#include <math.h>
#include "Point.h"
using namespace std;
#define PI 3.141592 
class Circle :public GraphicObject
{
public:
	Circle() :GraphicObject(),center(), radius(0) {}
	Circle(Point p1, float length = 20.0, float t_width=5.0,Gdiplus::Color color = Gdiplus::Color::Red) :center(p1), radius(length),width(t_width) { mColor = color; }
	Circle(float x, float y, float length = 20, float t_width = 5.0, Gdiplus::Color color = Gdiplus::Color::Red) :center(x, y), radius(length), width(t_width) { mColor = color; }
	Circle(Circle& c1) :center(c1.center), radius(c1.radius),width(c1.width) { mColor = c1.mColor; }
	virtual ~Circle() {}
	GraphicType getGraphicType() { return rCircle; }
	void DrawCircle();
	Point get_center();
	float get_radius();
	float get_width();
	Gdiplus::Color get_color();
	void Set_Circle(Point p1, float l, float t_width = 5.0, Gdiplus::Color color = Gdiplus::Color::Red);
	float Acreage();
	int IF_incirle(Point& p1);//返回1在圆外，返回0在圆上，返回-1在圆外
	friend int Cirle_intersect(Circle& c1, Circle& c2);//返回0相交，返回1外切，返回2内切，返回3外离，返回4内含
private:
	Point center;
	float radius;
	float width;
};