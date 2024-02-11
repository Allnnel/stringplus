#include "s21_string.h"

long int s21_pow(long int x, unsigned int n) {
  long int a = x, res = 1;
  while (n > 0) {
    if ((n & 1) != 0) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}