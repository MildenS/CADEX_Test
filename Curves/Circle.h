#pragma once
#include "Curve.h"


class Circle :
    public Curve
{
public:

    virtual Vector3D GetPoint(double t) override;
    virtual Vector3D GetDerived(double t) override;
    virtual CurveType GetCurveType() override;
    Circle(double Radius);
    virtual std::string ToString() override;
    virtual double GetRadius();
    ~Circle() override {}

private:
    double Radius;
    static const CurveType Type = CurveType::Circle;
};

