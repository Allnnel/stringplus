#include "s21_string.h"
// strchr - ищет первое вхождение символа c (символ без знака) в строке, на
// которую указывает аргумент str . str — это строка C для сканирования. c — это
// символ, который нужно искать в ул. Это возвращает указатель на первое
// вхождение символа c в строку str или NULL, если символ не найден.

char *s21_strchr(const char *str, int c) {
  char *string = s21_NULL;
  if (str) {
    string = (char *)str;
    while (*string && *string != (char)c) string++;
    if (*string != (char)c) string = s21_NULL;
  }
  return string;
}
