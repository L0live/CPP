#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed x;
    const Fixed y;

public:
    Point();

    Point(float const x_val, float const y_val);

    Point(Point const &other);

    Point &operator=(Point const &other);

    ~Point();

    Fixed getX() const;
    Fixed getY() const;
    static Point getPoint();

};

bool bsp(const Point &pt, const Point &v1, const Point &v2, const Point &v3);

#endif
