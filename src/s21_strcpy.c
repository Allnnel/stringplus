#include "s21_string.h"
// strcpy - копирует строку, на которую указывает src , в dest.
// dest — это указатель на целевой массив, в который нужно скопировать
// содержимое. src — это строка, которую нужно скопировать. Возвращает указатель
// на целевую строку dest.
char *s21_strcpy(char *dest, const char *src) {
  if (dest && src) {
    int i = 0;
    for (i = 0; src[i] != '\0'; i++) dest[i] = src[i];
    dest[i++] = '\0';
  }
  return dest;
}
