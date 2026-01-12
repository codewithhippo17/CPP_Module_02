#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>
#include <ostream>

class Fixed {
public:
  Fixed();
  Fixed(const float);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

  Fixed(const int);

  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;

  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

private:
  int fixedpoint;
  static const int fraction = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif // FIXED_HPP
