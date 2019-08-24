#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H
#include <cmath>

template<typename T> bool equals(T one, T two) {
  return one == two;
};

template<typename T> double scalar_difference(T one, T two) {
  return abs(one.getScalarValue() - two.getScalarValue());
};

#endif
