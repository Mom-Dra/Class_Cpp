#pragma once
#include <iostream>

class Vector3
{

private:
	double x;
	double y;
	double z;
	double mag;

	void Set_mag();

public:
	Vector3();
	Vector3(double n1, double n2, double n3);
	void Reset(double n1, double n2, double n3);
	~Vector3();
	double Xval() const;
	double Yval() const;
	double Magval() const;
	Vector3 Normalize() const;

	static double Dot(const Vector3& a, const Vector3& b);
	static Vector3 Cross(const Vector3& a, const Vector3& b);
	static double Angle(const Vector3& a, const Vector3& b);

	friend Vector3 operator+(const Vector3& a, const Vector3& b);
	friend Vector3 operator-(const Vector3& a, const Vector3& b);
	friend Vector3 operator*(const Vector3& a, double n);
	friend Vector3 operator*(double n, const Vector3& a);
	friend Vector3 operator/(const Vector3& a, double n);

	friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
};