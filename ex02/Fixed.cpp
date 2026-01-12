#include "Fixed.hpp"

Fixed::Fixed() : fixedpoint(0) {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    this->fixedpoint = other.fixedpoint;
  }
  return (*this);
}

Fixed::~Fixed() {}

Fixed::Fixed(const int intiger) { fixedpoint = (intiger << fraction); }

Fixed::Fixed(const float floating_point) {
  fixedpoint = roundf(floating_point * (1 << fraction));
}

int Fixed::getRawBits(void) const { return this->fixedpoint; }

float Fixed::toFloat(void) const {
  return ((float)fixedpoint / (1 << fraction));
}
int Fixed::toInt(void) const { return (fixedpoint >> fraction); }

void Fixed::setRawBits(int const raw) { this->fixedpoint = raw; }

std::ostream &operator<<(std::ostream &os, const Fixed &other) {
  os << other.toFloat();
  return (os);
}

Fixed Fixed::operator+(const Fixed &other) const {
  Fixed result;
  result.fixedpoint = this->fixedpoint + other.fixedpoint;
  return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed result;
  result.fixedpoint = this->fixedpoint - other.fixedpoint;
  return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed result;
  result.fixedpoint = (this->fixedpoint * other.fixedpoint) >> fraction;
  return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed result;
  result.fixedpoint = (this->fixedpoint << fraction) / other.fixedpoint;
  return result;
}

bool Fixed::operator==(const Fixed &other) const {
  return this->fixedpoint == other.fixedpoint;
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->fixedpoint != other.fixedpoint;
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->fixedpoint >= other.fixedpoint;
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->fixedpoint <= other.fixedpoint;
}

bool Fixed::operator>(const Fixed &other) const {
  return this->fixedpoint > other.fixedpoint;
}

bool Fixed::operator<(const Fixed &other) const {
  return this->fixedpoint < other.fixedpoint;
}

Fixed &Fixed::operator++() {
  ++this->fixedpoint;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  ++this->fixedpoint;
  return temp;
}

Fixed &Fixed::operator--() {
  --this->fixedpoint;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  --this->fixedpoint;
  return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return (a.fixedpoint < b.fixedpoint) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a.fixedpoint < b.fixedpoint) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return (a.fixedpoint > b.fixedpoint) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a.fixedpoint > b.fixedpoint) ? a : b;
}
