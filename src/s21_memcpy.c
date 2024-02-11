#include "s21_string.h"

// memcpy - копирует n символов из области памяти src в область памяти dest.
//  dest — это указатель на целевой массив, в который должно быть скопировано
//  содержимое. src — это указатель на источник копируемых данных. n — это
//  количество копируемых байтов. Эта функция возвращает указатель на место
//  назначения, которым является dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest && src) {
    char *str1 = (char *)dest;
    char *str2 = (char *)src;
    for (int i = 0; i != (int)n; i++) str1[i] = str2[i];
  }
  return dest;
}
