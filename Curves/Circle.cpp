#include "Circle.h"

Vector3D Circle::GetPoint(double t)
{
	double x = Radius * cos(t);
	double y = Radius * sin(t);
	return Vector3D(x,y,0);
}

Vector3D Circle::GetDerived(double t)
{
	double x = -Radius * sin(t);
	double y = Radius * cos(t);
	return Vector3D(x, y, 0);
}

CurveType Circle::GetCurveType()
{
	return Type;
}

Circle::Circle(double Radius)
{
	if (Radius <= 0)
		throw std::invalid_argument("Not positive circle radius");
	this->Radius = Radius;
}

std::string Circle::ToString()
{
	std::string info = "Circle, radius = ";
	info += std::to_string(Radius);
	info += '\n';
	return info;
}

double Circle::GetRadius()
{
	return Radius;
}


