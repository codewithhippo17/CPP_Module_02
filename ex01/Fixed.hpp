#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>
#include <ostream>
#include <string.h>

class Fixed {
public:
  Fixed();
  Fixed(const int);
  Fixed(const float);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

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
