#pragma once
#include "Curve.h"
class Ellipse :
    public Curve
{
public:
    virtual Vector3D GetPoint(double t) override;
    virtual Vector3D GetDerived(double t) override;
    virtual CurveType GetCurveType() override;
    Ellipse(double a, double b);
    virtual std::string ToString() override;
    virtual double GetRadius();
    ~Ellipse() override {}

private:
    double a, b;
    static const CurveType Type = CurveType::Ellipse;

};

