#include "s21_string.h"

// strpbrk - находит первый символ в строке str1 , который соответствует любому
// символу, указанному в str2 . Это не включает завершающие нулевые символы.
// str1 — это строка C для сканирования.
// str2 — это строка C, содержащая символы для сопоставления.
// Эта функция возвращает указатель на символ в строке str1,
// который соответствует одному из символов строки str2, или NULL, если такой
// символ не найден.
char *s21_strpbrk(const char *str1, const char *str2) {
  char *string = s21_NULL;
  if (str1 && str2) {
    string = (char *)str1;
    int flag = 0;
    for (int i = 0; str1[i] != '\0' && flag == 0; i++) {
      for (int ii = 0; str2[ii] != '\0' && flag == 0; ii++)
        if (str1[i] == str2[ii]) flag = 1;
      if (flag == 0) string++;
    }
    if (flag == 0) string = s21_NULL;
  }
  return string;
}
