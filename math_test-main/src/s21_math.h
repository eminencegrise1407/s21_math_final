#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#define s21_eps 1e-16
#define s21_PI 3.14159265358979323846264338327950288
#define s21_PI_2 1.57079632679489661923132169163975144
#define s21_LN2 \
  0.693147180559945309417232121458176568
#define s21_LN10 \
  2.30258509299404568401799145468436421
#define s21_MAX_EXP 709.782712893384
#define s21_MIN_EXP -745.133219101941
#define s21_INFINITY __builtin_inf()
#define s21_NAN __builtin_nanf("0x7fc00000")
#define is_fin(x) __builtin_isfinite(x)
#define is_inf(x) __builtin_isinf(x)
#define is_nan(x) __builtin_isnan(x)
#define is_norm(x) __builtin_isnormal(x)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
