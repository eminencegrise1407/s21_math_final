#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0.0;
  int sign = 1;
  if (is_inf(x)) {
    res = s21_NAN;
  } else if (is_fin(y)) {
    y = s21_fabs(y);
    if (x < 0) {
      sign = -1;
      x = s21_fabs(x);
    }
    if (y == 0) {
      res = s21_NAN;
    } else {
      long long int n = x / y;
      res = (long double)x - n * (long double)y;
    }
  } else if (is_inf(y)) {
    res = x;
  }
  return res * sign;
}
