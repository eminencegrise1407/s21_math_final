#include "s21_math.h"

long double s21_ceil(double x) {
  long double y = s21_floor(x);
  return y == x ? y : y + 1;
}