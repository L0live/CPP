#include "Point.hpp"

static Fixed sign(const Point &p1, const Point &p2, const Point &p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(const Point &pt, const Point &v1, const Point &v2, const Point &v3) {
    Fixed d1, d2, d3;
    bool hasNeg, hasPos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    // Debug infos
    // std::cout << "d1: " << d1 << std::endl;
    // std::cout << "d2: " << d2 << std::endl;
    // std::cout << "d3: " << d3 << std::endl;

    hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}