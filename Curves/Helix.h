#pragma once
#include "Curve.h"
class Helix :
    public Curve
{
public:
    virtual Vector3D GetPoint(double t) override;
    virtual Vector3D GetDerived(double t) override;
    virtual CurveType GetCurveType() override;
    Helix(double Radius, double Step);
    virtual std::string ToString() override;
    virtual double GetRadius();
    ~Helix() override {}

private:
    double Radius, Step;
    static const CurveType Type = CurveType::Helix;
};

