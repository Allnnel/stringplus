#include "s21_string.h"

const char *forchar(const char *ptr_str, va_list list, Length *length) {
  if (length->star != 1) *(char *)va_arg(list, char *) = *ptr_str;
  if (*ptr_str) length->it++;
  if (length->wight != 0) {
    ptr_str = ptr_str + length->wight;
  } else {
    ptr_str++;
  }
  if (*ptr_str == ' ') ptr_str = space(ptr_str);
  return ptr_str;
}

const char *forstr(const char *ptr_str, va_list list, Length *length) {
  if (length->star == 1) {
    ptr_str = star(ptr_str, length);
  } else {
    char *temp_ptr = (char *)va_arg(list, char *);
    if (*temp_ptr) length->it++;
    if (length->wight > 0) {
      while (strValidScan(*ptr_str) && length->wight > 0) {
        *temp_ptr = *ptr_str;
        temp_ptr++;
        ptr_str++;
        length->wight--;
      }
    } else if (length->wight == 0) {
      while (strValidScan(*ptr_str)) {
        *temp_ptr = *ptr_str;
        temp_ptr++;
        ptr_str++;
      }
    }
    *temp_ptr = '\0';
    if (*ptr_str == ' ') ptr_str = space(ptr_str);
  }
  return ptr_str;
}

const char *forint(const char *ptr_str, va_list list, Length *length) {
  if (length->star == 1) {
    ptr_str = star(ptr_str, length);
  } else {
    long long value = 0;
    ptr_str = countvalue(ptr_str, length, &value);
    if (length->minus == 1) value *= -1;
    length->it++;
    if (length->specifier == 'd') {
      if (length->l == 1) {
        *va_arg(list, long int *) = (long)value;
      } else if (length->L == 1 || length->ll == 1) {
        *va_arg(list, long long int *) = value;
      } else if (length->h == 1) {
        *va_arg(list, short *) = (short)value;
      } else {
        *va_arg(list, int *) = (int)value;
      }
    } else if (length->specifier == 'u') {
      if (length->l == 1) {
        *va_arg(list, long unsigned *) = (long)value;
      } else if (length->L == 1 || length->ll == 1) {
        *va_arg(list, long long unsigned *) = value;
      } else if (length->h == 1) {
        *va_arg(list, unsigned short *) = (short)value;
      } else {
        *va_arg(list, unsigned int *) = (int)value;
      }
    }
  }
  return ptr_str;
}

const char *forfloat(const char *ptr_str, va_list list, Length *length) {
  if (length->star == 1) {
    ptr_str = star(ptr_str, length);
  } else {
    long long value = 0;
    ptr_str = countvalue(ptr_str, length, &value);
    float value_float = value;
    int num = 1;
    for (int i = 0; i != length->f; i++) num *= 10;
    value_float = value_float / num;
    if (length->minus == 1) value_float *= -1;
    length->it++;
    if (length->l == 1) {
      *va_arg(list, double *) = (double)value_float;
    } else if (length->L == 1) {
      *va_arg(list, long double *) = (long double)value_float;
    } else {
      *va_arg(list, float *) = (float)value_float;
    }
  }
  return ptr_str;
}

const char *forOct(const char *ptr_str, va_list list, Length *length) {
  if (length->star == 1) {
    ptr_str = star(ptr_str, length);
  } else {
    long long value = 0;
    long long res = 0;
    ptr_str = countvalue(ptr_str, length, &value);
    for (int i = 0; value != 0; i++) {
      res = res + (value % 10) * s21_pow(8, i);
      value = value / 10;
    }
    if (length->minus == 1) res *= -1;
    length->it++;
    if (length->l == 1) {
      *va_arg(list, long unsigned *) = (long)res;
    } else if (length->h == 1) {
      *va_arg(list, unsigned short *) = (short)res;
    } else {
      *va_arg(list, unsigned int *) = (int)res;
    }
  }
  return ptr_str;
}

const char *forHex(const char *ptr_str, va_list list, Length *length) {
  if (length->star == 1) {
    ptr_str = star(ptr_str, length);
  } else {
    long long res = 0;
    char buf[1000];
    int i = 0, pow = 0;
    if (*ptr_str == '-' && ptr_str++) {
      length->minus = 1;
    }
    if (*ptr_str == '+') {
      ptr_str++;
    }
    if (length->wight > 0) {
      while (strValidScan(*ptr_str) && length->wight > 0) {
        buf[i] = *ptr_str;
        i++;
        ptr_str++;
        length->wight--;
      }
    } else if (length->wight == 0) {
      while (strValidScan(*ptr_str)) {
        buf[i] = *ptr_str;
        i++;
        ptr_str++;
      }
    }
    if (*ptr_str == ' ') ptr_str = space(ptr_str);
    for (int count = i - 1; count >= 0; count--) {
      buf[count] = convert(buf[count]);
      res = res + buf[count] * s21_pow(16, pow);
      pow++;
    }
    if (length->minus == 1) res *= -1;
    length->it++;
    if (length->l == 1) {
      *va_arg(list, long unsigned *) = (long)res;
    } else if (length->h == 1) {
      *va_arg(list, unsigned short *) = (short)res;
    } else {
      *va_arg(list, unsigned int *) = (int)res;
    }
  }
  return ptr_str;
}

const char *forIndex(const char *ptr_str, va_list list, Length *length) {
  if (*ptr_str == '0') {
    ptr_str++;
    if (*ptr_str == 'x' || *ptr_str == 'X') {
      ptr_str--;
      ptr_str = forHex(ptr_str, list, length);
    } else {
      ptr_str--;
      ptr_str = forOct(ptr_str, list, length);
    }
  } else {
    length->specifier = 'd';
    ptr_str = forint(ptr_str, list, length);
  }
  if (*ptr_str == ' ') ptr_str = space(ptr_str);
  return ptr_str;
}
const char *forpointer(const char *ptr_str, va_list list, Length *length) {
  if (length->star == 1) {
    ptr_str = star(ptr_str, length);
  }
  void **value = va_arg(list, void **);
  length->it++;
  long address = 0;
  if (Scan(ptr_str)) {
    if (length->wight > 0) {
      while (Scan(ptr_str) && length->wight > 0) {
        address = address * 16 + convert(*ptr_str);
        ptr_str++;
        length->wight--;
      }
    } else if (length->wight == 0) {
      while (Scan(ptr_str)) {
        address = address * 16 + convert(*ptr_str);
        ptr_str++;
      }
    }
  }
  *value = (void *)address;
  if (*ptr_str == ' ') ptr_str = space(ptr_str);
  return ptr_str;
}
