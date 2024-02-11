#include "s21_string.h"

const char *space(const char *ptr_str) {
  while (*ptr_str == ' ') {
    ptr_str++;
  }
  return ptr_str;
}

const char *star(const char *ptr_str, Length *length) {
  if (length->wight != 0) {
    while (*ptr_str != ' ' && length->wight > 0) {
      ptr_str++;
      length->wight--;
    }
  } else {
    while (*ptr_str != ' ') {
      ptr_str++;
    }
  }
  if (*ptr_str == ' ') ptr_str = space(ptr_str);
  return ptr_str;
}

const char *countvalue(const char *ptr_str, Length *length, long long *value) {
  int wight = length->wight;
  if (*ptr_str == '-') {
    if (length->wight != 0) length->wight--;
    ptr_str++;
    length->minus = 1;
  } else if (*ptr_str == '+') {
    ptr_str++;
  }
  if (length->wight > 0) {
    while (*ptr_str >= '0' && *ptr_str <= '9' && length->wight > 0) {
      *value = *value * 10 + (*ptr_str - 48);
      ptr_str++;
      length->wight--;
    }
  } else if (length->wight == 0) {
    while (*ptr_str >= '0' && *ptr_str <= '9') {
      *value = *value * 10 + (*ptr_str - 48);
      ptr_str++;
    }
  }
  if (length->f == 1)
    ptr_str = count_value_for_f(ptr_str, length, &value, wight);
  if (*ptr_str == ' ') ptr_str = space(ptr_str);
  return ptr_str;
}

const char *count_value_for_f(const char *ptr_str, Length *length,
                              long long **value, int wight) {
  if (*ptr_str != '.' || (wight != 0 && length->wight == 0))
    length->f = 0;
  else {
    int flag = 6;
    length->f = 0;
    ptr_str++;
    if (length->wight != 0) length->wight--;
    if (wight == 0) {
      while (*ptr_str >= '0' && *ptr_str <= '9' && flag--) {
        **value = **value * 10 + (*ptr_str - 48);
        ptr_str++;
        length->f += 1;
      }
    } else if (length->wight != wight) {
      while (*ptr_str >= '0' && *ptr_str <= '9' && length->wight != 0 &&
             flag--) {
        **value = **value * 10 + (*ptr_str - 48);
        length->f += 1;
        ptr_str++;

        length->wight--;
      }
    }
  }
  return ptr_str;
}

int strValidScan(char c) {
  int res = 1;
  switch (c) {
    case '\0':
    case '\n':
    case '\t':
    case '\v':
    case '\f':
    case '\r':
    case ' ':
      res = 0;
      break;
  }
  return res;
}
int convert(int value) {
  if (value >= '0' && value <= '9')
    value -= '0';
  else if (value == 'x')
    value = 0;
  else if (value == 'a' || value == 'A')
    value = 10;
  else if (value == 'b' || value == 'B')
    value = 11;
  else if (value == 'c' || value == 'C')
    value = 12;
  else if (value == 'd' || value == 'D')
    value = 13;
  else if (value == 'e' || value == 'E')
    value = 14;
  else if (value == 'f' || value == 'F')
    value = 15;
  return value;
}

int Scan(const char *ptr_str) {
  int res = 0;
  if ((*ptr_str >= '0' && *ptr_str <= '9') ||
      (*ptr_str >= 'a' && *ptr_str <= 'f') ||
      (*ptr_str >= 'A' && *ptr_str <= 'F') ||
      (*ptr_str == 'x' || *ptr_str == 'X'))
    res = 1;
  return res;
}
