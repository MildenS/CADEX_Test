#include "Ellipse.h"

Vector3D Ellipse::GetPoint(double t)
{
    double x = a * cos(t);
    double y = b * sin(t);
    return Vector3D(x,y,0);
}

Vector3D Ellipse::GetDerived(double t)
{
    double x = -a * sin(t);
    double y = b * cos(t);
    return Vector3D(x,y,0);
}

CurveType Ellipse::GetCurveType()
{
    return Type;
}

Ellipse::Ellipse(double a, double b)
{
    if (a <= 0 || b <= 0)
        throw std::invalid_argument("Not positive ellipse constructor argument");
    this->a = a;
    this->b = b;

}

std::string Ellipse::ToString()
{
    std::string info = "Ellipse, a = ";
    info += std::to_string(a) + ", b = ";;
    info += std::to_string(b) + '\n';
    info = info.substr(0, info.find('.') + 4) + '\n';
    return info;
}

double Ellipse::GetRadius()
{
    //нарушает SOLID:(
    return a;
}
