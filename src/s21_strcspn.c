#include "s21_string.h"
// strcspn - вычисляет длину начального сегмента строки str1 ,
// который полностью состоит из символов, не входящих в строку str2 .
// str1 — это основная строка C для сканирования.
// str2 — это строка, содержащая список символов для соответствия в str1.
// Эта функция возвращает количество символов
// в начальном сегменте строки str1, которых нет в строке str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t num = 0;
  if (*str1 && *str2) {
    int err = 0;
    for (int i = 0; err == 0 && str1[i] != '\0'; i++) {
      for (int ii = 0; err == 0 && str2[ii] != '\0'; ii++)
        if (str1[i] == str2[ii]) err = 1;
      if (err == 0) num++;
    }
  }
  return num;
}
