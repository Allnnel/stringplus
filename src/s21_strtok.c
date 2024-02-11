#include "s21_string.h"

// strtok - разбивает строку str на ряд токенов, разделенных delim.
// str — содержимое этой строки изменяется и разбивается на более мелкие строки
// (токены). delim — это строка C, содержащая разделители. Они могут
// варьироваться от одного вызова к другому. Эта функция возвращает указатель на
// первый токен, найденный в строке. Нулевой указатель возвращается, если не
// осталось токенов для извлечения.
char *s21_strtok(char *str, const char *delim) {
  int flag = 0;
  static char *head = s21_NULL;
  if (str)
    head = str;
  else
    flag = 1;

  if (head && *head == '\0') flag = 1;  
  char *next = head;
  if (next && flag == 0)
    while (*next && s21_strchr(delim, *next)) next++; 
  if (next && *next == '\0') flag = 1; 

  char *result = next;

  if (next && flag == 0)  /
    while (s21_strchr(delim, *next) == s21_NULL) next++;  
  if (next && *next == '\0' && flag == 0) 
    head = next;
  else if (next && flag == 0) {  
    *next = '\0';
    head = next + 1;
  }

  return (flag == 1) ? s21_NULL : result;
}
