#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x_val, float const y_val) : x(x_val), y(y_val) {}

Point::Point(Point const &other) : x(other.x), y(other.y) {}

Fixed Point::getX() const {return x;}

Fixed Point::getY() const {return y;}

Point &Point::operator=(Point const &other) {
	if (this != &other) {
		// Comme x et y sont constants, ils ne peuvent pas être réaffectés.
		// Cependant, l'opérateur est défini pour satisfaire la forme canonique.
	}
	return *this;
}

Point Point::getPoint() {
	float x, y;

	std::cout << "Enter the x coordinate: ";
	std::cin >> x;

	std::cout << "Enter the y coordinate: ";
	std::cin >> y;
	return Point(x, y);
}

Point::~Point() {}
