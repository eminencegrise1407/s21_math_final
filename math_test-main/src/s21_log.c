#include "s21_math.h"
// от 0 до 1 и большие числа
long double s21_log(double x) {
  long double result = 0.0;
  double n = 0;
  int i = 1;
  int counter = 0;
  int sign = 1;

  if (x < 0 || is_nan(x) || (is_inf(x) && x < 0)) {
    result = s21_NAN;
  }

  if (x == 0) {
    result = -s21_INFINITY;
  }

  if (is_inf(x) && x > 0) {
    result = s21_INFINITY;
  }

  if (x == 1) {
    result = 0;
  }

  while (is_fin(x) && x >= 2) {
    x /= 10;
    counter++;
  }

  double y = x - 1;
  if (is_fin(x) && x > 0 && x != 1) {
    do {
      n = y / i;
      result += sign * n;
      sign *= -1;
      y *= (x - 1);
      i++;
    } while (s21_fabs(n) > s21_eps);
  }
  return result + counter * s21_LN10;
}