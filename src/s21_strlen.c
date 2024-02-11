#include "s21_string.h"

// strlen - вычисляет длину строки str до, но не включая завершающий нулевой
// символ.
//  str — это строка, длину которой нужно найти.
//  Эта функция возвращает длину строки.

s21_size_t s21_strlen(const char *str) {
  s21_size_t str_size = 0;
  if (str)
    for (int i = 0; str[i] != '\0'; i++) str_size++;
  return str_size;
}
