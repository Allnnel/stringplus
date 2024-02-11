#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list list;
  va_start(list, format);
  int it = pars(str, format, list);
  va_end(list);
  return it;
}

int pars(const char *str, const char *format, va_list list) {
  const char *ptr_str = str;
  const char *ptr_format = format;
  int it = *ptr_str ? 0 : -1;
  while (*ptr_format != '\0') {
    Length length = {0};
    length.it = it;
    if (*ptr_format == '%') {
      ptr_format++;
      if (*ptr_format == '%') {
        ptr_format++;
      }
      ptr_format = findlength(ptr_format, &length);
      if (length.specifier == 'n') {
        *va_arg(list, int *) = (int)(ptr_str - str);
        ptr_format++;
      } else {
        ptr_str = findspecifier(ptr_str, ptr_format, list, &length);
      }
      while (*ptr_format == ' ') ptr_format++;
      it = length.it;
    }
    ptr_format++;
  }
  return it;
}

const char *findwight(const char *format, Length *length) {
  if (*format == '*') {
    length->star = 1;
    format++;
  }
  int res = 0;
  while (*format && *format >= '0' && *format <= '9') {
    res = res * 10 + (*format - 48);
    format++;
  }
  length->wight = res;
  return format;
}

const char *findlength(const char *format, Length *length) {
  while (*format != '%') {
    if (*format == 'l') {
      if (length->l == 1)
        length->ll = 1;
      else if (length->l == 0 && length->L == 0 && length->h == 0)
        length->l = 1;
      format++;
    } else if (*format == 'L' &&
               (length->l == 0 && length->L == 0 && length->h == 0)) {
      length->L = 1;
      format++;
    } else if (*format == 'h' &&
               (length->l == 0 && length->L == 0 && length->h == 0)) {
      length->h = 1;
      format++;
    } else if ((*format >= '0' && *format <= '9') || (*format == '*')) {
      format = findwight(format, length);
    } else if (s21_strchr("difcsueEgGxXonp%", *format) != s21_NULL) {
      length->specifier = *format;
      break;
    }
  }
  return format;
}

const char *findspecifier(const char *ptr_str, const char *ptr_format,
                          va_list list, Length *length) {
  length->specifier = *ptr_format;
  if (*ptr_format == 'd' || *ptr_format == 'u')
    ptr_str = forint(ptr_str, list, length);
  else if (*ptr_format == 'i')
    ptr_str = forIndex(ptr_str, list, length);
  else if (*ptr_format == 'f' || *ptr_format == 'e' || *ptr_format == 'E' ||
           *ptr_format == 'g' || *ptr_format == 'G') {
    length->f = 1;
    ptr_str = forfloat(ptr_str, list, length);
  } else if (*ptr_format == 'c')
    ptr_str = forchar(ptr_str, list, length);
  else if (*ptr_format == 's')
    ptr_str = forstr(ptr_str, list, length);
  else if (*ptr_format == 'o')
    ptr_str = forOct(ptr_str, list, length);
  else if (*ptr_format == 'x' || *ptr_format == 'X')
    ptr_str = forHex(ptr_str, list, length);
  else if (*ptr_format == 'p')
    ptr_str = forpointer(ptr_str, list, length);

  return ptr_str;
}
