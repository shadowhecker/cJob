#pragma once
#include "Point.h"
#include <windows.h>
#include <string>
#include <vector>
#include "DSGraphic.h"
#include <math.h>
using namespace std;

class Line :public GraphicObject
{
public:
	Line() :GraphicObject(),p1(),p2(),width(0){}
	Line(Line& L1) :p1(L1.p1), p2(L1.p2), width(L1.width) { mColor = L1.mColor; }
	Line(float x1, float y1, float x2, float y2, float m_width, Gdiplus::Color color) :p1(x1, y1, m_width, color), p2(x2, y2, m_width, color), width(m_width) { mColor = color; }
	Line(Point tp_1, Point tp_2) :p1(tp_1), p2(tp_2), width(tp_1.get_size()) { mColor = tp_1.get_color(); }
	virtual ~Line() {}
	GraphicType getGraphicType() { return rLine; }
	void DrawLine();
	void Set_Line(float x1, float y1, float x2, float y2, float m_width, Gdiplus::Color color);
	Point& get_head();
	Point get_tail();
	float get_width();
	Gdiplus::Color get_color();
	float Length();
	int IF_inline(Point& c1);//�жϵ��Ƿ����߶���//����>0�����߶��ϣ�=0�˵��غϣ�<0���߶���
	int IF_leftright(Point& c1);//�жϵ����ߵ���߻����ұ�,����>0���ұߣ�����<0�����,����==0���ӳ�����
	friend Point Intersect(Line &L1,Line &L2);//�жϱ������Ƿ���L1�ཻ
	friend int Valid_Intersect(Line &L1, Line &L2);//�ж��������ǹ淶�ཻ���ǲ��淶�ཻ//����1�淶�ཻ������-1�ǲ��ཻ������0�ǲ��淶�ཻ
private:
	Point p1;//��һ����
	Point p2;//�յ�ĵ�
	float width;//�߶εĿ��
};