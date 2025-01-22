#include "Point.hpp"


int main() {

    // // get the points of the triangle
    // std::cout << "Enter the coordinates of the first point of the triangle:" << std::endl;
    // Point a = Point::getPoint();
    // std::cout << "Enter the coordinates of the second point of the triangle:" << std::endl;
    // Point b = Point::getPoint();
    // std::cout << "Enter the coordinates of the third point of the triangle:" << std::endl;
    // Point c = Point::getPoint();

    // // get the point to check
    // std::cout << "Enter the coordinates of the point to check:" << std::endl;
    // Point p = Point::getPoint();

    // Manual test
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 4);
    Point p(2, 2); // inside
    // Point p(234, 749); // outside

    if (bsp(p, a, b, c)) {
        std::cout << "Le point est dans le triangle." << std::endl;
    } else {
        std::cout << "Le point est hors du triangle." << std::endl;
    }

    return 0;
}
