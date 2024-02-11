#include "s21_string.h"
// to_lower - озвращает копию строки (str), преобразованной в нижний регистр. В
// случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str) {
  char *string = s21_NULL;
  if (str) {
    int size = s21_strlen(str);
    string = (char *)malloc(size + 1);
    if (string != s21_NULL) {
      int i = 0;
      while (i <= size) {
        if (str[i] >= 65 && str[i] <= 90)
          string[i] = str[i] + 32;
        else
          string[i] = str[i];
        i++;
      }
    }
  }
  return string;
}