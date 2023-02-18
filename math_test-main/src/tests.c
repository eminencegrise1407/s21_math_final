#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"
START_TEST(s21_abs_test) {
  int num = 23;
  ck_assert_int_eq(s21_abs(num), abs(num));

  int num2 = 200000;
  ck_assert_int_eq(s21_abs(num2), abs(num2));

  int num3 = -200000;
  ck_assert_int_eq(s21_abs(num3), abs(num3));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(s21_acos_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
  x = 4.5;
  ck_assert_ldouble_nan(s21_acos(x));
  x = -200000.567;
  ck_assert_ldouble_nan(s21_acos(x));
  x = 0.7;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);
  x = -0.5;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);
  x = 0.5;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);
  x = 1;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);
  x = -1;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);
  x = -1.5;
  ck_assert_ldouble_nan(s21_acos(x));
  x = 1.5;
  ck_assert_ldouble_nan(s21_acos(x));
  x = 0.21;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);
  x = 0.789123;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);
}
END_TEST

START_TEST(s21_asin_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
  x = 0.5;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
  x = -0.5;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
  x = 1;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
  x = -1;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
  x = 4.5;
  ck_assert_ldouble_nan(s21_asin(x));
  x = -200000.567;
  ck_assert_ldouble_nan(s21_asin(x));
  x = 0.7;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), 1e-6);
  x = -0.99;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), 1e-6);
}
END_TEST

START_TEST(s21_atan_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  x = 0.5;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  x = -0.5;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  x = 1;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  x = -1;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  x = 0.21;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  x = 3200;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  x = 10;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  x = 4.5;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  x = -200000.567;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  x = 0.7;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  x = -0.99;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  x = 1.0 / 0.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  x = -1.0 / 0.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  x = 0.0 / 0.0;
  ck_assert_ldouble_nan(s21_atan(x));
}
END_TEST

START_TEST(s21_ceil_test) {
  double num = 23.34;
  ck_assert_ldouble_eq_tol(s21_ceil(num), ceil(num), 1e-6);

  double num2 = 200000.567;
  ck_assert_ldouble_eq_tol(s21_ceil(num2), ceil(num2), 1e-6);

  double num3 = -200000.456784;
  ck_assert_ldouble_eq_tol(s21_ceil(num3), ceil(num3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceil(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(3.213), ceil(3.213), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-3.213), ceil(-3.213), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-1.0), ceil(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(1.0), ceil(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-11.0), ceil(-11.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(12.0), ceil(12.0), 1e-6);
}
END_TEST

START_TEST(s21_cos_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
  x = 5.15;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
  x = -1.14;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
  x = 1;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
  x = -1;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
  x = 15000;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
  x = 42;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
  x = -21;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
  x = 23.34;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 1e-6);
  x = 200000.567;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 1e-6);
  x = -200000.456784;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 1e-6);
}
END_TEST

START_TEST(s21_exp_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
  x = 2;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = -2;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = 4.5;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = -4.5;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = 7.21;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = 20.567;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = 0.7;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = 0.99;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = 1.0 / 0.0;
  ck_assert_ldouble_infinite(s21_exp(x));
  x = -1.0 / 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = 0.0 / 0.0;
  ck_assert_ldouble_nan(s21_exp(x));
  x = 800.5878;
  ck_assert_ldouble_infinite(s21_exp(x));
  x = -318;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = -746;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  x = 7001234.12;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
  ck_assert_ldouble_eq_tol(s21_exp(-700123.12), exp(-700123.12), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-71101234.12), exp(-71101234.12), 1e-6);
}
END_TEST

START_TEST(s21_fabs_test) {
  double num = 23.34;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
  ck_assert_ldouble_eq(s21_fabs(-23.34), fabs(-23.34));
  ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0));
  ck_assert_ldouble_eq(s21_fabs(1.0), fabs(1.0));
  ck_assert_ldouble_eq(s21_fabs(-1.0), fabs(-1.0));

  double num2 = 200000.567;
  ck_assert_ldouble_eq(s21_fabs(num2), fabs(num2));

  double num3 = -200000.456784;
  ck_assert_ldouble_eq(s21_fabs(num3), fabs(num3));
}
END_TEST

START_TEST(s21_floor_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = 2.5;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = -2.5;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = -2.3;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = 2.3;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = -2.7;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = 2.7;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = 4.4;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = 1;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = 251215125125243.6;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
  x = 23.34;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 1e-6);
  x = 200000.567;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 1e-6);
  x = -200000.456784;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 1e-6);
  ck_assert_double_nan(s21_floor(s21_NAN));
}
END_TEST

START_TEST(s21_fmod_test) {
  double x = 0.0;
  double y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 4.5;
  y = 2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = -200000.567;
  y = 2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = 0.7;
  y = -2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = -4.0;
  y = 2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = 21;
  y = 2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = 42.0;
  y = -21.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = -0.99;
  y = 2.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = 1.0;
  y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = -1.0;
  y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 1.0 / 0.0;
  y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 0.0;
  y = 1.0 / 0.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  x = -1.0 / 0.0;
  y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  x = 0.0;
  y = -1.0 / 0.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  ck_assert_double_eq_tol(s21_fmod(1232.5, 0.5), fmod(1232.5, 0.5), 1e-6);
  ck_assert_double_eq_tol(s21_fmod(1232.5, -0.25), fmod(1232.5, -0.25), 1e-6);
  ck_assert_double_eq_tol(s21_fmod(-1232.5, 0.25), fmod(-1232.5, 0.25), 1e-6);
  ck_assert_double_eq_tol(s21_fmod(-1232.5, -0.25), fmod(-1232.5, -0.25), 1e-6);
}
END_TEST

START_TEST(s21_log_test) {
  double x = 0.0;
  ck_assert_ldouble_infinite(s21_log(x));
  x = 4.5;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  x = 200000.567;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  x = 0.7;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  x = 1021;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  x = 0.021;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  x = -0.99;
  ck_assert_ldouble_nan(s21_log(x));
  x = 23;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.1), s21_log(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.00001), s21_log(0.00001), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.4), s21_log(0.4), 1e-6);
  ck_assert_ldouble_eq_tol(log(100), s21_log(100), 1e-6);
  ck_assert_ldouble_eq_tol(log(100000), s21_log(100000), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.001), s21_log(0.001), 1e-6);
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_infinite(s21_log(s21_INFINITY));
  ck_assert_ldouble_nan(s21_log(-s21_INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
  ck_assert_ldouble_nan(s21_log(s21_NAN));
  ck_assert_ldouble_eq_tol(s21_log(0.000001), log(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.1), log(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(15.7865), log(15.7865), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(280.8854), log(280.8854), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(3200.6734), log(3200.6734), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1e+37), log(1e+37), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1e+38), log(1e+38), 1e-6);
}
END_TEST

START_TEST(s21_pow_test_1) {
  double num = 4;
  ck_assert_ldouble_eq_tol(s21_pow(num, 0.5), pow(num, 0.5), 1e-6);
  double num2 = -1;
  ck_assert_ldouble_eq_tol(s21_pow(num2, 10.0), pow(num2, 10.0), 1e-6);
  double num3 = 4;
  ck_assert_ldouble_eq_tol(s21_pow(num3, 6), pow(num3, 6), 1e-6);
  double num4 = 4.345666;
  ck_assert_ldouble_eq_tol(s21_pow(num4, 0.5), pow(num4, 0.5), 1e-6);
  double num5 = 2.6;
  ck_assert_ldouble_eq_tol(s21_pow(num5, 3.2), pow(num5, 3.2), 1e-6);
  double num6 = 4;
  ck_assert_ldouble_eq_tol(s21_pow(num6, -6), pow(num6, -6), 1e-6);
  double base = 4, exp = 0.5;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), 1e-6);
  base = 0.0;
  exp = 100.0;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), 1e-6);
  base = 0.0;
  exp = 0.0;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-1.0, 10.1));
  base = 25;
  exp = 3.4576;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
  base = 5.587;
  exp = 7.2134;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
  ck_assert_ldouble_nan(s21_pow(s21_NAN, 2));
}
END_TEST

START_TEST(s21_pow_test_2) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 3), pow(2, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 123), pow(0, 123), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-5, 2.2));
  ck_assert_double_eq_tol(s21_pow(8.2, 8.1), pow(8.2, 8.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(13.21313, 2.2), pow(13.21313, 2.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(123.3, 0), pow(123.3, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(123.3, -2), pow(123.3, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(123.3, -2.2), pow(123.3, -2.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(13.3, -123), pow(13.3, -123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(4, 0.5), pow(4, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(123, 0.00001), pow(123, 0.00001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-1, 123), pow(-1, 123), 1e-6);
}
END_TEST

START_TEST(s21_sin_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
  x = 5.15;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
  x = -1.14;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
  x = 1;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
  x = -1;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
  x = 15000;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
  x = 42;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
  x = -21;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
  x = 23.34;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 1e-6);
  x = 200000.567;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 1e-6);
  x = -200000.456784;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test) {
  ck_assert_ldouble_eq_tol(s21_sqrt(5), sqrt(5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(4), sqrt(4), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(-4));

  double num2 = 234;
  ck_assert_ldouble_eq_tol(s21_sqrt(num2), sqrt(num2), 1e-6);

  double num3 = 578.35673;
  ck_assert_ldouble_eq_tol(s21_sqrt(num3), sqrt(num3), 1e-6);

  double num4 = 6789990;
  ck_assert_ldouble_eq_tol(s21_sqrt(num4), sqrt(num4), 1e-6);

  double num5 = -578;
  ck_assert_ldouble_nan(s21_sqrt(num5));

  double num6 = 0;
  ck_assert_ldouble_eq(s21_sqrt(num6), sqrt(num6));
  ck_assert_ldouble_nan(s21_sqrt(s21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-s21_INFINITY));
  ck_assert_double_eq_tol(s21_sqrt(1234567899.123456), sqrt(1234567899.123456),
                          1e-6);
  ck_assert_double_eq_tol(s21_sqrt(0.01234213), sqrt(0.01234213), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(0.00003), sqrt(0.00003), 1e-6);
}
END_TEST

START_TEST(s21_tan_test) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = 1;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = -1;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = 12325435.55643674;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = -1232543546.5464654;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = 1232543546.5464654;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = -123564562.546;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = 1e+9;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = -1e+9;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = 0.0001;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = -0.0001;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = 1.01;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = s21_PI / 2;
  ck_assert_ldouble_infinite(s21_tan(x));
  x = s21_PI / 2 + s21_PI;
  ck_assert_ldouble_infinite(s21_tan(x));
  x = -s21_PI / 2 - s21_PI;
  ck_assert_ldouble_infinite(s21_tan(x));
  x = s21_PI / 4;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  x = s21_PI / 4 + s21_PI;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
  ck_assert_ldouble_nan(s21_tan(s21_INFINITY));
  ck_assert_ldouble_nan(s21_tan(-s21_INFINITY));
  ck_assert_ldouble_nan(s21_tan(s21_NAN));
}
END_TEST

int main(void) {
  Suite *s = suite_create("s21_math");
  TCase *tc = tcase_create("s21_math");
  SRunner *sr = srunner_create(s);
  int nf;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_abs_test);
  tcase_add_test(tc, s21_acos_test);
  tcase_add_test(tc, s21_asin_test);
  tcase_add_test(tc, s21_atan_test);
  tcase_add_test(tc, s21_ceil_test);
  tcase_add_test(tc, s21_cos_test);
  tcase_add_test(tc, s21_exp_test);
  tcase_add_test(tc, s21_fabs_test);
  tcase_add_test(tc, s21_floor_test);
  tcase_add_test(tc, s21_fmod_test);
  tcase_add_test(tc, s21_log_test);
  tcase_add_test(tc, s21_pow_test_1);
  tcase_add_test(tc, s21_pow_test_2);
  tcase_add_test(tc, s21_sin_test);
  tcase_add_test(tc, s21_sqrt_test);
  tcase_add_test(tc, s21_tan_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}