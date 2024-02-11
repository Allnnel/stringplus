#include "s21_string.h"

// strspn - вычисляет длину начального сегмента str1, который полностью состоит
// из символов str2. str1 — это основная строка C для сканирования. str2 — это
// строка, содержащая список символов для соответствия в str1. Эта функция
// возвращает количество символов в начальном сегменте строки str1, которые есть
// в строке str2.
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t num = 0;
  if (str1 && str2) {
    int flag = 1;
    for (int i = 0; str1[i] != '\0' && flag == 1; i++) {
      flag = 0;
      for (int ii = 0; str2[ii] != '\0' && flag == 0; ii++) {
        if (str2[ii] == str1[i]) {
          num++;
          flag = 1;
        }
      }
    }
  }
  return num;
}
