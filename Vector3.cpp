#include <cmath>
#include <numbers>
#include "Vector3.h"

void Vector3::Set_mag()
{
	mag = std::sqrt(x * x + y * y + z * z);
}

Vector3::Vector3() : Vector3{ 0.0, 0.0, 0.0 }
{
}

Vector3::Vector3(double n1, double n2, double n3) : x{ n1 }, y{ n2 }, z{ n3 }
{
	Set_mag();
}

void Vector3::Reset(double n1, double n2, double n3)
{
	x = n1;
	y = n2;
	z = n3;

	Set_mag();
}

Vector3::~Vector3()
{
}

double Vector3::Xval() const
{
	return x;
}

double Vector3::Yval() const
{
	return y;
}

double Vector3::Magval() const
{
	return mag;
}

Vector3 Vector3::Normalize() const
{
	return *this / mag;
}

double Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

double Vector3::Angle(const Vector3& a, const Vector3& b)
{
	double cosTheta = Vector3::Dot(a, b) / a.mag / b.mag;

	cosTheta = std::max(-1.0, std::min(1.0, cosTheta));

	return std::acos(cosTheta) / std::numbers::pi * 180.0;
}

Vector3 operator+(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3 operator-(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector3 operator*(const Vector3& a, double n)
{
	return Vector3(a.x * n, a.y * n, a.z * n);
}

Vector3 operator*(double n, const Vector3& a)
{
	return a * n;
}

Vector3 operator/(const Vector3& a, double n)
{
	return Vector3(a.x / n, a.y / n, a.z / n);
}

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
	os << v.x << ' ' << v.y << ' ' << v.z;
	
	return os;
}
