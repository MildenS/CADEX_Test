#pragma once
#include "CoreTypes.hpp"
#include <stdexcept>
#include<cmath>
#include<string>

class Curve
{
public:
	virtual Vector3D GetPoint(double t) = 0;
	virtual Vector3D GetDerived(double t) = 0;
	virtual CurveType GetCurveType() = 0;
	virtual std::string ToString() = 0;
	virtual double GetRadius() = 0;
	virtual ~Curve() {};
};
