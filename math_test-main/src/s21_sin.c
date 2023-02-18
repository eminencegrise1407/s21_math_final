#include "s21_math.h"
long double s21_sin(double x) {
  long double n = 1;
  long double i = 1;
  x = s21_fmod(x, 2 * s21_PI);
  long double res = x;
  while (s21_fabs(n) > s21_eps) {
    n = (x * x / ((i * i) * s21_PI * s21_PI));
    res *= (1 - n);
    i++;
  }
  return res;
}
