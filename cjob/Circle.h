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
	int IF_incirle(Point& p1);//����1��Բ�⣬����0��Բ�ϣ�����-1��Բ��
	friend int Cirle_intersect(Circle& c1, Circle& c2);//����0�ཻ������1���У�����2���У�����3���룬����4�ں�
private:
	Point center;
	float radius;
	float width;
};