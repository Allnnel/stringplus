#include "s21_string.h"
// insert - возвращает новую строку, в которой указанная строка (str) вставлена
// в указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *str2 = s21_NULL;
  if (start_index > s21_strlen(src) || (int)start_index < 0)
    str2 = s21_NULL;
  else if (src && str) {
    int sizestr2 = s21_strlen(src) + s21_strlen(str);
    str2 = (char *)malloc(sizeof(char) * sizestr2 + 1);
    int i = 0;
    int y = 0;
    int size = start_index;
    while (i < size) {
      str2[i] = src[i];
      i++;
      y++;
    }
    int k = 0;
    while (str[k] != '\0') {
      str2[i] = str[k];
      k++;
      i++;
    }
    while (src[y] != '\0') {
      str2[i] = src[y];
      y++;
      i++;
    }
    str2[i] = '\0';
  }

  return str2;
}