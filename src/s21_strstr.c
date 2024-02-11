#include "s21_string.h"

// strstr - находит первое вхождение подстроки needle в строку haystack .
// haystack −  это основная строка C для сканирования.
// needle −  это небольшая строка для поиска в строке стога сена.
// Завершающие символы '\0' не сравниваются.
// Эта функция возвращает указатель на первое вхождение в haystack из всей
// последовательности символов, указанной в параметре  needle, или нулевой
// указатель, если последовательности нет в haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack && needle) {
    int flag = 0;
    const char *head = haystack;
    while (flag == 0 && *haystack) {
      if (*haystack == *needle) {
        const char *needle_head = needle;
        const char *haystack_double = haystack;
        while (flag == 0 && *haystack_double++ == *needle_head++)
          if (*needle_head == '\0') flag = 1;
      }
      if (flag == 0) haystack++;
    }
    if (needle[0] == '\0') haystack = head;
    if (flag != 1 && needle[0] != '\0') haystack = s21_NULL;
  }
  return (char *)haystack;
}
