#include "s21_string.h"

// strrchr - ищет последнее вхождение символа c (unsigned char) в строке,
// на которую указывает аргумент str .
// str — это строка C.
// c — это элемент, который нужно найти. Он передается как продвижение int, но
// внутренне преобразуется обратно в char. Эта функция возвращает указатель на
// последнее вхождение символа в str. Если значение не найдено, функция
// возвращает нулевой указатель.
char *s21_strrchr(const char *str, int c) {
  char *string = s21_NULL;
  if (str) {
    while (*str) {
      if (*str == (char)c) string = (char *)str;
      str++;
    }
    if ((char)c == '\0') {
      string = (char *)str;
    }
  }
  return string;
}