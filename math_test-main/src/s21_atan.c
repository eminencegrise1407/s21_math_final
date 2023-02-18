#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  long double n = 1;
  long double y = 1;
  int i = 1;
  int sign = 1;
  if (!is_nan(x)) {
    y = x;
    if (s21_fabs(x) < 1) {
      do {
        n = y / i;
        res += sign * n;
        sign *= -1;
        y *= x * x;
        i += 2;
      } while (s21_fabs(n) > s21_eps);
    } else if (x > 1) {
      res = s21_PI_2 - s21_atan(1 / x);
    } else if (x < -1) {
      res = -s21_PI_2 - s21_atan(1 / x);
    } else if (x == 1) {
      res = s21_PI / 4;
    } else if (x == -1) {
      res = -s21_PI / 4;
    }
  } else {
    res = s21_NAN;
  }
  return res;
}