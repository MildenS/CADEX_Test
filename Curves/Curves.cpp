#include <iostream>
#include <random>
#include <vector>
#include <memory>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

//Количество генерируемых кривых и их максимальный радиус
#define CurvesNum 100
#define MaxRadius 500

# define M_PI     3.14159265358979323846

//2
void FillVector(std::vector<std::shared_ptr<Curve>>& vec);
std::shared_ptr<Curve> Generate_Curve(int type, std::mt19937 gen_rand);

//3
void DisplayCurves(const std::vector<std::shared_ptr<Curve>>& vec, double t);

//4
void GetCircles(std::vector<std::shared_ptr<Curve>>& vec_from, std::vector<std::shared_ptr<Curve>>& vec_where);

//5
bool CompareTo(std::shared_ptr<Curve> ptr1, std::shared_ptr<Curve> ptr2);

//6
int RadiiSum(const std::vector<std::shared_ptr<Curve>>& vec);

//for tests
void DisplayCurves(const std::vector<std::shared_ptr<Curve>>& vec);


int main()
{
    
    std::vector<std::shared_ptr<Curve>> vec1;
    std::vector<std::shared_ptr<Curve>> vec2; 

    std::cout.precision(3);

    //Проверка 2 задания
    try
    {
        FillVector(vec1);
    }
    catch (std::invalid_argument& error)
    {
        std::cout << error.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cout << "Something wrong with curve generation\n";
        return 1;
    }

    //DisplayCurves(vec1);

    //Проверка 3 задания
    DisplayCurves(vec1, M_PI / 4);

    //Проверка 4 задания
    GetCircles(vec1, vec2);
    DisplayCurves(vec2);

    //Проверка 5 задания
    std::sort(vec2.begin(),vec2.end(), CompareTo);
    DisplayCurves(vec2);

    //Проверка 6 задания
    std::cout << "Sum of radii in second container = " << RadiiSum(vec2) << '\n';
}


void FillVector(std::vector<std::shared_ptr<Curve>>& vec)
{
    std::random_device rnd;
    std::mt19937 gen_rand(rnd());
    std::uniform_int_distribution<int> types_dist(0, 2);
    for (size_t i = 0; i < CurvesNum; i++)
    {
        int type = types_dist(gen_rand);
        vec.push_back(Generate_Curve(type, gen_rand));
    }
}

std::shared_ptr<Curve> Generate_Curve(int type, std::mt19937 gen_rand)
{
    CurveType curve_type = static_cast<CurveType>(type);
    switch (curve_type)
    {
    case CurveType::Circle:
    {
        unsigned int Radius = gen_rand()%MaxRadius;
        return std::shared_ptr<Curve>(new Circle(Radius));
        break;
    }
    case CurveType::Ellipse:
    {
        unsigned int a = gen_rand()% MaxRadius;
        unsigned int b = gen_rand() % MaxRadius;
        return std::shared_ptr<Curve>(new Ellipse(a, b));
        break;
    }
    case CurveType::Helix:
    {
        unsigned int Rad = gen_rand() % MaxRadius;
        unsigned int Step = gen_rand() % MaxRadius;
        return std::shared_ptr<Curve>(new Helix(Rad, Step));
        break;
    }
    default:
    {
        throw std::invalid_argument("Incorrect curve type");
        break;
    }
    }
}

void DisplayCurves(const std::vector<std::shared_ptr<Curve>>& vec, double t)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        Vector3D point = vec[i]->GetPoint(t);
        Vector3D derived = vec[i]->GetDerived(t);
        std::cout <<std::fixed<<'\t'<< i + 1 << " Curve:\nPoint: " << point << "\nDerived: " << derived << '\n';
    }
}

void GetCircles(std::vector<std::shared_ptr<Curve>>& vec_from, std::vector<std::shared_ptr<Curve>>& vec_where)
{
    for (size_t i = 0; i < vec_from.size(); i++)
    {
        if (vec_from[i]->GetCurveType() == CurveType::Circle)
        {
            vec_where.push_back(vec_from[i]);
        }
    }
}

bool CompareTo(std::shared_ptr<Curve> ptr1, std::shared_ptr<Curve> ptr2)
{
    return ptr1->GetRadius()<ptr2->GetRadius();
}

int RadiiSum(const std::vector<std::shared_ptr<Curve>>& vec)
{
    int radii_sum = 0;
    for (size_t i = 0; i < vec.size(); i++)
        radii_sum += vec[i]->GetRadius();
    return radii_sum;
}

void DisplayCurves(const std::vector<std::shared_ptr<Curve>>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << i + 1 << " curve: " << vec[i]->ToString();
    }
}
