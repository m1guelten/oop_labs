#pragma once

class Shape
{
protected:
	long x1, y1, x2, y2;
	long xs1, ys1, xs2, ys2;
	
public:
	virtual ~Shape();
	//void Set(long x1, long y1, long x2, long y2);

	void SetStart(long x, long y);
	void SetEnd(long x, long y);
	long getX1(void);
	long getY1(void);
	long getX2(void);
	long getY2(void);
	virtual void Show(HDC) = 0;
};

class PointShape : virtual public Shape
{
public:
	void Show(HDC);
};

class LineShape : virtual public Shape
{
public:
	void Show(HDC);
};

class RectShape : virtual public Shape
{
public:
	void Show(HDC);
};

class EllipseShape : virtual public Shape
{
public:
	void Show(HDC);
};
