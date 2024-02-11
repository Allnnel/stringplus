#include "s21_string.h"

// trim - возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL

void *s21_trim(const char *src, const char *trim_chars) {
  char *result_str = s21_NULL;

  if (src && trim_chars) {     
    int len = s21_strlen(src); 
    result_str =
        (char *)calloc((len + 1), sizeof(char)); 
    int i = 0, j = 0; 

    for (; i < len && s21_strchr(trim_chars, src[i]); ++i)
      ;  
    for (; i < len; ++j) 
      result_str[j] = src[i++]; 
                               

    for (; j != 0 && s21_strchr(trim_chars, result_str[--j]) &&
           j < len;)  
      result_str[j] = '\0'; 
  }
  return result_str;
}
