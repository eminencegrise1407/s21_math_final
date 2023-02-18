#include "s21_math.h"

long double s21_floor(double x) {
  long double y = 0.0;
  if (is_nan(x) || is_inf(x)) {
    y = s21_NAN;
  } else if (is_fin(x)) {
    if (x < 0) {
      y = (long long int)x - 1;
    } else {
      y = (long long int)x;
    }
  }
  return y;
}
