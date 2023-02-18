#include "s21_math.h"

long double s21_pow(double base, double num) {
  long double result = s21_NAN;
  int num_int = (long)num;
  if (is_nan(base) || is_nan(num) || (is_inf(base) && num == 0) ||
      (base < 0 && num != num_int)) {
    result = s21_NAN;
  } else if ((is_inf(base) && num > 0) || (base == 0 && num < 0)) {
    result = s21_INFINITY;
  } else if ((is_inf(base) && num < 0) || (base == 0 && num > 0)) {
    result = 0;
  } else if ((base == 0 && num == 0) || (base == 1)) {
    result = 1;
  } else if (base > 0) {
    result = s21_exp(num * s21_log(base));
  } else if (base < 0 && num == num_int && num_int % 2 == 0) {
    result = s21_exp(num * s21_log(-base));
  } else if (base < 0 && num == num_int && num_int % 2 != 0) {
    result = -s21_exp(num * s21_log(-base));
  }
  return result;
}
