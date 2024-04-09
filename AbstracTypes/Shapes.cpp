#include "Shapes.hpp"

#include <vector>
#include <iostream>

void rotate_all(std::vector<Shape*>& v, int angle)
{
    for (auto p: v)
        p-> rotate(angle);
}

Point Circle::center() const
{
    return x;
}

void Circle::move(Point to)
{
    x = to;
}

void Circle::rotate(int theta) {
    r += theta;
}



//void Smiley::draw() const
//{
//    Circle::draw();
//    for(auto p : eyes)
//        p->draw();
//    if (mouth) {
//        mouth->draw();
//    }
//}
