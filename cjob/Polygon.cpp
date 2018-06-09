#include "stdafx.h"
#include "Polygon.h"

extern vector<GraphicObject*> gRenderObjects;
void flushWindow();
extern unsigned gPlayingSpeed;

void Polygon_Real::DrawPolygon()
{
	gRenderObjects.push_back(this);
	flushWindow();
	Sleep(gPlayingSpeed);
}

BOOL Polygon_Real::IF_Convex()
{
	vector<Triangle_Real> Triangle_Sum;
	for (auto i = p.begin(); i != p.end() - 3; ++i)
		Triangle_Sum.push_back(Triangle_Real(*i, *(i + 1), *(i + 2)));
	Triangle_Sum.push_back(Triangle_Real(*(p.end() - 2), *(p.end() - 1), *(p.begin())));
	Triangle_Sum.push_back(Triangle_Real(*(p.end() - 1), *(p.begin()), *(p.begin() + 1)));
	int index;
	index = (*Triangle_Sum.begin()).C_Anti_Clock();
	for (auto i = Triangle_Sum.begin() + 1; i != Triangle_Sum.end(); ++i)
	{
		if ((*i).C_Anti_Clock() != index)
			return 0;
	}
	return 1;
}
