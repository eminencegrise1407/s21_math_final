#include "s21_math.h"
long double s21_exp(double x) {
  long double result = 1;
  long double n = 1;
  int i = 1;
  if (is_nan(x)) {
    result = s21_NAN;
  }
  if (is_inf(x)) {
    if (x < 0) {
      result = 0;
    } else {
      result = s21_INFINITY;
    }
  } else if (is_fin(x)) {
    if (x == 0) {
      result = 1;
    } else if (x > s21_MAX_EXP) {
      result = s21_INFINITY;
    } else if (x < s21_MIN_EXP) {
      result = 0;
    } else if (x > 0) {
      do {
        n *= x / i;
        result += n;
        i++;
      } while (s21_fabs(n) > s21_eps);
    } else if (x < 0) {
      result = 1 / s21_exp(-x);
    }
  }
  return result;
}
