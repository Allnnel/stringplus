#include "s21_string.h"

// memmove - копирует n символов из src в dest.
// dest — это указатель на целевой массив, в который следует скопировать
// содержимое src — это указатель на источник копируемых данных n — это
// количество копируемых байтов. Эта функция возвращает указатель на место
// назначения, которым является dest.
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  if (dest && src) {
    char *str1 = (char *)dest;
    char *str2 = (char *)src;
    for (s21_size_t i = 0; i != n; i++) str1[i] = str2[i];
  }
  return dest;
}
