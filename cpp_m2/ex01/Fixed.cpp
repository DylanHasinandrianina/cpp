#include "Fixed.hpp"

Fixed::Fixed() : _value(0){
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called\n";
    _value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called\n";
    if (this != &other){
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called\n";
    return (_value);
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called\n";
    _value = raw;
}

Fixed::Fixed(const int value){
    std::cout << "Int constructor called\n";
    _value = value * 256;
}

Fixed::Fixed(const float value){
    std::cout << "Float constructor called\n";
    _value = roundf(value * 256);
}

float Fixed::toFloat(void) const{
    float fvalue;

    fvalue = _value / 256.0f;
    return (fvalue);
}
//use of float literal (256.Of) keeps the fractional part, because '/' delete it.

int Fixed::toInt(void) const{
    int ivalue;

    ivalue = _value / 256;
    return (ivalue);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
    out << fixed.toFloat();
    return (out);
}
//we return out to allow chaining multiple <<

