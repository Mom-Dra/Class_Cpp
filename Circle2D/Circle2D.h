#pragma once
class Circle2D
{
private:
	double x;
	double y;
	double radius;

public:
	Circle2D();
	Circle2D(double x, double y, double radius);

	double GetX() const;
	double GetY() const;
	double GetRadius() const;

	double GetArea() const;
	double GetPerimeter() const;

	bool Contains(double x, double y) const;
	bool Contains(const Circle2D& other) const;
	bool Overlaps(const Circle2D& circle) const;
};

