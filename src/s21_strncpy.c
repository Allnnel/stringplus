#include "s21_string.h"

// strncpy - копирует до n символов из строки, на которую указывает src , в dest
// .
//  В случае, когда длина src меньше длины n, оставшаяся часть dest будет
//  дополнена нулевыми байтами. dest — это указатель на целевой массив, в
//  который нужно скопировать содержимое. src — это строка, которую нужно
//  скопировать. n — количество символов, которые нужно скопировать из
//  источника. Эта функция возвращает указатель на скопированную строку.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  if (dest == s21_NULL)
    dest = s21_NULL;
  else if (!src)
    dest = s21_NULL;
  else {
    int i = 0;
    while (n-- && src[i] != '\0') {
      dest[i] = src[i];
      i++;
    }
    if (src[0] != '\0')
      while (dest[i] != '\0' && n--) i++;
    dest[i] = '\0';
  }
  return ptr;
};
