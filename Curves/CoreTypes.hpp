#pragma once
#include<iostream>


enum class CurveType
{
	Circle =0,
	Ellipse,
	Helix
};

struct Vector3D
{
	Vector3D(double x = 0, double y = 0, double z = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
		
	double X() { return x; }
	double Y() { return y; }
	double Z() { return z; }

	friend std::ostream& operator<<(std::ostream& os, const Vector3D vec)
	{
		os << "x = "<<vec.x << ", y = " << vec.y << ", z = " << vec.z;
		return os;
	}
private:
	double x, y, z;
};