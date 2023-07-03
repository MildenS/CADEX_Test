#include "Helix.h"

Vector3D Helix::GetPoint(double t)
{
    double x = Radius * cos(t);
    double y = Radius * sin(t);
    double z = Step * t;
    return Vector3D(x,y,z);
}

Vector3D Helix::GetDerived(double t)
{
    double x = -Radius * sin(t);
    double y = Radius*cos(t);
    double z = Step;
    return Vector3D(x,y,z);
}

CurveType Helix::GetCurveType()
{
    return Type;
}

Helix::Helix(double Radius, double Step)
{
    if (Radius <= 0)
        throw std::invalid_argument("Not positive helix radius");
    this->Radius = Radius;
    this->Step = Step;
}

std::string Helix::ToString()
{
    std::string info = "Helix, radius = ";
    info += std::to_string(Radius) + ", step = ";
    info += std::to_string(Step);
    info = info.substr(0, info.find('.') + 4) + '\n';
    return info;
}

double Helix::GetRadius()
{
    return Radius;
}
