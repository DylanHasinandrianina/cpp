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

bool Fixed::operator>(const Fixed& other) const{
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const{
    return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const{
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const{
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const{
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const{
    return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) const{
    Fixed result;
    result._value = this->_value + other._value;
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const{
    Fixed result;
    result._value = this->_value - other._value;
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed result;
    result._value = (this->_value * other._value) >> frac_bits ;
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const{
    Fixed result;
    result._value = (this->_value << frac_bits) / other._value;
    return (result);
}
//for multiplication/division, we need to correct the scale manually

Fixed& Fixed::operator++(){
    _value++;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed tmp (*this);
    _value++;
    return(tmp);
}

Fixed& Fixed::operator--(){
    _value--;
    return (*this);
}

Fixed Fixed::operator--(int){
    Fixed tmp (*this);
    _value--;
    return(tmp);
}
//the smallest representable epsilon for fixed point is (1/256)


Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a < b)
        return(a);
    else
        return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if (a < b)
        return(a);
    else
        return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a > b)
        return(a);
    else
        return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if (a > b)
        return(a);
    else
        return (b);
}