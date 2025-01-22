#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const int value) :_rawBits(value << this->_fractionalBits) {}

Fixed::Fixed(const float value) :_rawBits(roundf(value * (1 << this->_fractionalBits))) {}


Fixed::Fixed(const Fixed &fixed) {*this = fixed;}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &fixed) {
    if (this != &fixed)
        this->_rawBits = fixed.getRawBits();
    return *this;
}

Fixed Fixed::operator+(const Fixed &fixed) const {return Fixed(this->toFloat() + fixed.toFloat());}

Fixed Fixed::operator-(const Fixed &fixed) const {return Fixed(this->toFloat() - fixed.toFloat());}

Fixed Fixed::operator*(const Fixed &fixed) const {return Fixed(this->toFloat() * fixed.toFloat());}

Fixed Fixed::operator/(const Fixed &fixed) const {return Fixed(this->toFloat() / fixed.toFloat());}

Fixed &Fixed::operator++(void) {
    this->_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void) {
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

bool Fixed::operator>(const Fixed &fixed) const {return this->toFloat() > fixed.toFloat();}

bool Fixed::operator<(const Fixed &fixed) const {return this->toFloat() < fixed.toFloat();}

bool Fixed::operator>=(const Fixed &fixed) const {return this->toFloat() >= fixed.toFloat();}

bool Fixed::operator<=(const Fixed &fixed) const {return this->toFloat() <= fixed.toFloat();}

bool Fixed::operator==(const Fixed &fixed) const {return this->toFloat() == fixed.toFloat();}

bool Fixed::operator!=(const Fixed &fixed) const {return this->toFloat() != fixed.toFloat();}

Fixed &Fixed::min(Fixed &a, Fixed &b) {return a < b ? a : b;}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {return a < b ? a : b;}

Fixed &Fixed::max(Fixed &a, Fixed &b) {return a > b ? a : b;}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {return a > b ? a : b;}

float Fixed::toFloat(void) const {return (float)this->_rawBits / (1 << this->_fractionalBits);}

int Fixed::toInt(void) const {return this->_rawBits >> this->_fractionalBits;}

int Fixed::getRawBits(void) const {return this->_rawBits;}

void Fixed::setRawBits(int const raw) {this->_rawBits = raw;}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}