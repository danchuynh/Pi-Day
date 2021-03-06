#include "Polygon.h"
#include <vector>


Polygon::Polygon(unsigned int size)
{
    for(int i = 0; i < size; i++)
        pointsVector.push_back(Point());
}
Polygon::Polygon(const Polygon& other)
{
    copy(other);

}
Polygon& Polygon::operator=(const Polygon& other)
{
    if(this != &other)
    {
        pointsVector.clear();
        copy(other);
    }
    return *this;
}

Point Polygon::Element(unsigned int position) const
{
    if(position>pointsVector.size())
        exit(1);
    else
        return pointsVector[position];
}

unsigned int Polygon::Size() const
{
     return pointsVector.size();
}

Point& Polygon::element(unsigned int position)
{
    return pointsVector[position];
}

void Polygon::copy(const Polygon &other)
{
    for(int i=0;i<other.pointsVector.size();i++)
        pointsVector.push_back(other.pointsVector.at(i));
}

void Polygon::Translate(double X, double Y)
{
    for(int i = 0; i < Size(); i++)
    {
        pointsVector[i].X += X;
        pointsVector[i].Y += Y;
    }
}
