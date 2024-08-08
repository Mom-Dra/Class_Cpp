#include <numbers>
#include "Circle2D.h"

Circle2D::Circle2D() : Circle2D{0, 0, 1}
{
}

Circle2D::Circle2D(double x, double y, double radius) : x{ x }, y{ y }, radius{ radius }
{
}

double Circle2D::GetX() const
{
	return x;
}

double Circle2D::GetY() const
{
	return y;
}

double Circle2D::GetRadius() const
{
	return radius;
}

double Circle2D::GetArea() const
{
	return std::numbers::pi * radius * radius;
}

double Circle2D::GetPerimeter() const
{
	return 2 * std::numbers::pi * radius;
}

bool Circle2D::Contains(double x, double y) const
{
	return (this->x - x) * (this->x - x) + (this->y - y) * (this->y - y) <= radius * radius;
}

bool Circle2D::Contains(const Circle2D& other) const
{
	if (radius < other.radius) return false;

	return (this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y) <= (radius - other.radius) * (radius - other.radius);
}

bool Circle2D::Overlaps(const Circle2D& other) const
{
	return (this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y) <= (radius + other.radius) * (radius + other.radius);
}
