#include "s21_math.h"

long double s21_asin(double x) {
  long double result = s21_NAN;
  if (-1 <= x && x <= 1) {
    long double y = x / (s21_sqrt(1 - x * x));
    result = s21_atan(y);
  }
  return result;
}
