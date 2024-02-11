#include "s21_string.h"

// memchr - ищет первое вхождение символа.
// str — это указатель на блок памяти, в котором выполняется поиск.
// c — это значение, которое должно быть передано как целое число.
// n — это количество байтов для анализа.
// Эта функция возвращает указатель на соответствующий байт или NULL, если
// символ не встречается в данной области памяти.

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *string = s21_NULL;
  if (n == 0)
    string = s21_NULL;
  else if (str) {
    string = (char *)str;
    n -= 1;
    while (n-- && *string && *string != (char)c) string++;
    if (*string != (char)c) string = s21_NULL;
  }

  return string;
}
