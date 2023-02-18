#include "s21_math.h"
long double s21_sqrt(double x) {
  long double result = 0.0;
  if (is_nan(x)) {
    result = s21_NAN;
  }
  if (is_inf(x)) {
    if (x < 0) {
      result = s21_NAN;
    } else {
      result = s21_INFINITY;
    }
  } else if (is_fin(x)) {
    if (x == 0) {
      result = 0;
    } else if (x < 0) {
      result = s21_NAN;
    } else if (x > 0) {
      result = s21_exp(s21_log(x) / 2);
    }
  }
  return result;
}
