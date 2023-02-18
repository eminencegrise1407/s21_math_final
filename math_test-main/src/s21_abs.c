#include "s21_math.h"
int s21_abs(int x) {
  if (x < 0) {
    return x * (-1);
  } else {
    return x;
  }
}
