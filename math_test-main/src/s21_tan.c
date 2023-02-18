#include "s21_math.h"
long double s21_tan(double x) {
  long double res = 0;
  long double n = 1;
  long double i = 1;
  x = s21_fmod(x, s21_PI);
  if (x == s21_PI / 2 || x == -s21_PI / 2) {
    res = s21_INFINITY;
  } else {
    while (s21_fabs(n) > s21_eps) {
      n = 1 / ((1 - 2 * i) * (1 - 2 * i) * s21_PI * s21_PI - 4 * (x * x));
      res += n;
      i++;
    }
  }
  return 8 * x * res;
}
