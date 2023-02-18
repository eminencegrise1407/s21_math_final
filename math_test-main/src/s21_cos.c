#include "s21_math.h"
long double s21_cos(double x) {
  long double n = 1;
  long double i = 1;
  long double res = 1;
  x = s21_fmod(x, 2 * s21_PI);
  while (s21_fabs(n) > s21_eps) {
    n = ((4 * (x * x) / (((2 * i - 1) * (2 * i - 1)) * (s21_PI * s21_PI))));
    res *= (1 - n);
    i++;
  }
  return res;
}
