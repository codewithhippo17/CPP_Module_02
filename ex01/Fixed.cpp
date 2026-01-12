#include "Fixed.hpp"

Fixed::Fixed() : fixedpoint(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->fixedpoint = other.fixedpoint;
  }
  return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const int intiger) {
  std::cout << "Int constructor called" << std::endl;
  fixedpoint = (intiger << fraction);
}

Fixed::Fixed(const float floating_point) {
  std::cout << "Float constructor called" << std::endl;
  fixedpoint = roundf(floating_point * (1 << fraction));
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedpoint;
}

float Fixed::toFloat(void) const {
  return ((float)fixedpoint / (1 << fraction));
}
int Fixed::toInt(void) const { return (fixedpoint >> fraction); }

void Fixed::setRawBits(int const raw) { this->fixedpoint = raw; }

std::ostream &operator<<(std::ostream &os, const Fixed &other) {
  os << other.toFloat();
  return (os);
}
