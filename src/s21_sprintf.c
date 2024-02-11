#include "s21_string.h"

struct SprinFlags {
  int flag[5];
  int length[3];
  int width;
  int precision;
  int point;
} flags;

int NumberCount(unsigned long long number) {
  int count = 0;
  do {
    number /= 10;
    count++;
  } while (number != 0);
  return count;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list variable;
  va_start(variable, format);

  int index_str = 0;
  char *point_format = (char *)format;

  while (*point_format && index_str != -1) {
    if (*point_format != '%') {
      str[index_str++] = *point_format++;
      continue;
    }
    point_format++;
    if (*point_format == '%') {
      str[index_str++] = *point_format++;
      continue;
    }
    CleanSruct();
    point_format = SprintfFlags(point_format);

    if ((*point_format >= '0' && *point_format <= '9') ||
        (*point_format == '*' || *point_format == '.'))
      point_format = WidthAndPrecision(point_format, variable);
    point_format = s21_Length(point_format);
    if (s21_strchr("difcsueEgGxXonp", *point_format) == s21_NULL) {
      index_str = -1;
      continue;
    }
    if (*point_format == 'n') {
      *va_arg(variable, int *) = (int)index_str;
    } else
      Specificator(str, point_format, &index_str, variable);
    point_format++;
  }
  str[index_str] = '\0';
  va_end(variable);
  return index_str;
}

void CleanSruct() {
  s21_memset(flags.flag, 0, sizeof(flags.flag));
  s21_memset(flags.length, 0, sizeof(flags.length));
  flags.point = 0;
  flags.precision = 0;
  flags.width = 0;
}

char *SprintfFlags(char *point_format) {
  int end = 0;
  while (end == 0 && (*point_format)) {
    if (*point_format == '0')
      flags.flag[0] = '0';
    else if (*point_format == ' ')
      flags.flag[1] = 1;
    else if (*point_format == '+')
      flags.flag[2] = '+';
    else if (*point_format == '-')
      flags.flag[3] = 1;
    else if (*point_format == '#')
      flags.flag[4] = 1;
    else
      end = 1;
    if (end == 0) point_format += 1;
  }
  if (flags.flag[0] != '0') flags.flag[0] = ' ';
  return point_format;
}

char *WidthAndPrecision(char *point_format, va_list variable) {
  int *Point = &flags.width;
  int count = 0;
  do {
    int res = 0;
    if ((*point_format == '0' || flags.point == 1)) flags.point = 2;

    while (*point_format && *point_format >= '0' && *point_format <= '9') {
      res = res * 10 + (*point_format - 48);
      point_format++;
    }
    if (*point_format == '*') {
      *Point = va_arg(variable, int);
      if (*Point < 0) {
        *Point = -*Point;
        flags.flag[3] = 1;
      }
      point_format++;
    } else
      *Point = res;
    if (*point_format == '.') {
      flags.point = 1;
      point_format++;
      if (*point_format != 42 && (*point_format < 48 || *point_format > 57))
        flags.flag[0] = 2;
    }
    if (flags.precision == 0 && flags.point > 0) flags.point += 2;
    Point = &flags.precision;
    count += 1;
  } while (flags.point > 1 && count < 2);
  return point_format;
}

char *s21_Length(char *point_format) {
  if (*point_format == 'h' && flags.length[0] != 1) {
    flags.length[0] = 1;
    point_format += 1;
  } else if (*point_format == 'L' && flags.length[1] != 1) {
    flags.length[1] = 1;
    point_format += 1;
  } else {
    while (*point_format == 'l' && flags.length[2] <= 2) {
      flags.length[2] += 1;
      point_format += 1;
    }
  }
  return point_format;
}

void Specificator(char *str, char *point_format, int *index_str,
                  va_list variable) {
  int tempindex = 0;
  char tempStr[1024] = "0";
  char spec = 0;
  if (*point_format == 'd' || *point_format == 'i') {
    NumberInt(*point_format, &tempindex, variable, tempStr);
  } else if (*point_format == 'f' || *point_format == 'e' ||
             *point_format == 'E' || *point_format == 'g' ||
             *point_format == 'G') {
    NumberFloat(*point_format, &tempindex, variable, tempStr);
    spec = 'f';
  } else if (*point_format == 'u') {
    NumberUint(*point_format, &tempindex, variable, tempStr);
  } else if (*point_format == 'x' || *point_format == 'X') {
    FuncX(*point_format, &tempindex, tempStr, variable);
  } else if (*point_format == 'o') {
    FuncO(&tempindex, tempStr, variable);
  } else if (*point_format == 'p') {
    NumbeP(&tempindex, variable, tempStr);
  } else if (*point_format == 'c') {
    Char(&tempindex, variable, tempStr);
  } else if (*point_format == 's') {
    String(&tempindex, variable, tempStr);
    spec = 's';
  }

  int sign = flags.flag[2] > 0 ? 1 : 0;
  flags.width -= sign;
  if (flags.precision < 0) flags.precision = 0;
  if (flags.flag[3] == 0 && flags.width > 0 && flags.flag[0] != '0')
    FunWriteIntlen(str, flags.width - flags.precision, index_str, ' ');
  if (sign > 0) MinusPlus(str, index_str);
  BuFilling(str, tempStr, index_str, tempindex, spec);
  if (flags.flag[3] == 1 && flags.width > 0)
    FunWriteIntlen(str, flags.width - flags.precision, index_str,
                   flags.flag[0]);
}

void Char(int *tempindex, va_list variable, char *tempStr) {
  flags.flag[0] = ' ';
  for (int i = 1; i < 3; i++) flags.flag[i] = 0;
  flags.precision = 0;
  tempStr[*tempindex] = (char)va_arg(variable, long int);
  *tempindex += 1;
  flags.width -= 1;
}
void String(int *tempindex, va_list variable, char *tempStr) {
  int size = 0;
  flags.flag[0] = ' ';
  for (int i = 1; i < 3; i++) flags.flag[i] = 0;
  if (flags.length[2] == 1) {
    wchar_t *string = 0;
    string = va_arg(variable, wchar_t *);
    for (; string[size] != '\0'; size++)
      ;
    if (flags.point > 0) size = flags.precision;
    for (int i = 0; i < size && string[i] != '\0'; i++) {
      tempStr[*tempindex] = string[i];
      *tempindex += 1;
    }
  } else {
    char *string = 0;
    string = va_arg(variable, char *);
    size = s21_strlen(string);
    if (flags.point > 0) size = flags.precision;
    for (int i = 0; i < size && string[i] != '\0'; i++) {
      tempStr[*tempindex] = string[i];
      *tempindex += 1;
    }
  }
  if (flags.precision > *tempindex)
    flags.precision = 0;
  else
    flags.precision -= *tempindex;
  flags.width -= *tempindex;
  tempStr[*tempindex] = '\0';
}
void FunWriteIntlen(char *str, int count, int *index_str, char ch) {
  for (int i = 0; i < count; i++) {
    str[*index_str] = ch;
    *index_str += 1;
  }
}

void MinusPlus(char *str, int *index_str) {
  str[*index_str] = flags.flag[2];
  *index_str += 1;
}

void BuFilling(char *str, char *tempStr, int *index_str, int tempindex,
               char spec) {
  int lent = flags.precision;
  if (flags.flag[0] == '0' && flags.width > 0) lent = flags.width;
  if (lent > 0)
    for (int i = 1; i <= lent; i++) {
      str[*index_str] = (spec == 's') ? ' ' : '0';
      *index_str += 1;
    }
  if (flags.point > 1 && tempindex == 1 && tempStr[0] == '0') tempStr[0] = '\0';
  int i = spec == 'f' && tempStr[0] == '0' ? 1 : 0;
  for (; tempStr[i] != '\0'; i++) {
    str[*index_str] = tempStr[i];
    *index_str += 1;
  }
}

void NumbeP(int *tempindex, va_list variable, char *tempStr) {
  unsigned long number = (unsigned long)va_arg(variable, void *);
  flags.flag[2] = 0;

  tempStr[*tempindex] = '0';
  *tempindex += 1;
  tempStr[*tempindex] = 'x';
  *tempindex += 1;

  char Nubertemp[254] = "";
  char spec = 'W';
  int i = 0;
  for (; number >= 16; i++) {
    unsigned remain = number % 16;
    number /= 16;
    Nubertemp[i] = remain > 9 ? remain + spec : '0' + remain;
  }
  if (number < 16) Nubertemp[i] = number > 9 ? number + spec : '0' + number;
  WriteNubertemp(tempStr, tempindex, Nubertemp, i);
}

void NumberInt(char spec, int *tempindex, va_list variable, char *tempStr) {
  if (spec == 'd' || spec == 'i') {
    long long int number = 0;
    if (flags.length[0])
      number = (short)va_arg(variable, int);
    else if (flags.length[2] == 1)
      number = va_arg(variable, long int);
    else if ((flags.length[1] && spec == 'i') || flags.length[2] == 2)
      number = va_arg(variable, long long int);
    else
      number = va_arg(variable, int);
    FuncIntUint(spec, tempindex, number, tempStr);
  }
}

void NumberUint(char spec, int *tempindex, va_list variable, char *tempStr) {
  if (spec == 'u') {
    unsigned long long int number = 0;
    if (flags.length[0])
      number = (unsigned short)va_arg(variable, int);
    else if (flags.length[2] == 1)
      number = va_arg(variable, unsigned long int);
    else if (flags.length[1] || flags.length[2] == 2)
      number = va_arg(variable, unsigned long long int);
    else
      number = va_arg(variable, unsigned int);
    FuncIntUint(spec, tempindex, number, tempStr);
  }
}
unsigned long int NumberX(va_list variable) {
  unsigned long int number = 0;
  if (flags.length[0] > 0)
    number = (unsigned short)va_arg(variable, int);
  else if (flags.length[2] > 0)
    number = va_arg(variable, unsigned long int);
  else
    number = (unsigned long int)va_arg(variable, unsigned int);
  return number;
}

void FuncO(int *tempindex, char *tenpStr, va_list variable) {
  unsigned long int number = NumberX(variable);
  flags.flag[2] = 0;
  if (flags.flag[4] > 0 && number > 0) {
    tenpStr[*tempindex] = '0';
    *tempindex += 1;
  }
  char Nubertemp[254] = "";
  int i = *tempindex;
  for (; number >= 8; i++) {
    int remain = number % 8;
    number /= 8;
    Nubertemp[i] = '0' + remain;
  }
  if (number < 8) Nubertemp[i] = '0' + number;
  WriteNubertemp(tenpStr, tempindex, Nubertemp, i);
  if (flags.flag[4] > 0 && number > 0) *tempindex -= 1;
}
void FuncX(char spec, int *tempindex, char *tenpStr, va_list variable) {
  unsigned long int number = NumberX(variable);
  flags.flag[2] = 0;
  if (flags.flag[4] > 0 && number > 0) {
    tenpStr[*tempindex] = '0';
    *tempindex += 1;
    tenpStr[*tempindex] = spec == 'x' ? 'x' : 'X';
    *tempindex += 1;
  }
  char Nubertemp[254] = "";
  spec = spec == 'x' ? 'W' : '7';
  int i = 0;
  for (; number >= 16; i++) {
    unsigned remain = number % 16;
    number /= 16;
    Nubertemp[i] = remain > 9 ? remain + spec : '0' + remain;
  }
  if (number < 16) Nubertemp[i] = number > 9 ? number + spec : '0' + number;
  WriteNubertemp(tenpStr, tempindex, Nubertemp, i);
}

void WriteNubertemp(char *tenpStr, int *tempindex, const char *Nubertemp,
                    int index) {
  int count = index + *tempindex + 1;
  if (flags.precision > index) count = flags.precision - *tempindex - index - 1;

  if (flags.flag[0] == '0' && flags.width > index + 1)
    count = flags.width - *tempindex - index - 1;

  if (count > index + *tempindex + 1)
    FunWriteIntlen(tenpStr, count, tempindex, '0');
  for (; index >= 0; index--) {
    tenpStr[*tempindex] = Nubertemp[index];
    *tempindex += 1;
  }
  flags.width -= *tempindex;
  flags.precision -= *tempindex;
}

void FuncIntUint(char spec, int *tempindex, long long int number,
                 char *tenpStr) {
  if (number < 0) {
    flags.flag[2] = '-';
    number = -number;
  }
  if (spec != 'u' && flags.flag[1] == 1 && flags.flag[2] == 0)
    flags.flag[2] = ' ';
  if (spec == 'u') flags.flag[2] = 0;
  for (unsigned long long int i = s21_pow(10, NumberCount(number) - 1); i > 0;
       i /= 10) {
    tenpStr[*tempindex] = '0' + (number / i % 10);
    *tempindex += 1;
  }
  flags.precision -= *tempindex;
  flags.width -= *tempindex;
  tenpStr[*tempindex] = '\0';
}

void nun(int *tempindex, char *tempStr) {
  tempStr[*tempindex] = 'n';
  *tempindex += 1;
  tempStr[*tempindex] = 'a';
  *tempindex += 1;
  tempStr[*tempindex] = 'n';
  *tempindex += 1;
}

void inf(int *tempindex, char *tempStr) {
  tempStr[*tempindex] = 'i';
  *tempindex += 1;
  tempStr[*tempindex] = 'n';
  *tempindex += 1;
  tempStr[*tempindex] = 'f';
  *tempindex += 1;
}

void NumberFloat(char spec, int *tempindex, va_list variable, char *tempStr) {
  long double number = 0;
  if (flags.length[1] == 1)
    number = va_arg(variable, long double);
  else
    number = va_arg(variable, double);
  if (isnan(number))
    nun(tempindex, tempStr);

  else if (number == INFINITY)
    inf(tempindex, tempStr);

  else {
    if (number < 0) {
      flags.flag[2] = '-';
      number = -number;
    }
    if (flags.flag[1] == 1 && flags.flag[2] == 0) flags.flag[2] = ' ';
    if (spec == 'g' || spec == 'G')
      NumberG(spec, tempindex, tempStr, number);
    else if (spec == 'e' || spec == 'E')
      NumberE(spec, tempindex, tempStr, number);
    else if (spec == 'f')
      NumberF(tempindex, tempStr, number);
  }
}

void NumberF(int *tempindex, char *tempStr, long double number) {
  if (flags.precision == 0 && flags.point == 0) flags.precision = 6;
  Writefloat(number, tempindex, tempStr);
  flags.width -= *tempindex - 1;
}
void NumberE(char spec, int *tempindex, char *tempStr, long double number) {
  int count_zero = 0;
  char sign;
  if (number == 0)
    sign = '+';
  else
    sign = SignExp(&number, &count_zero);
  if (flags.precision == 0 && flags.point == 0) flags.precision = 6;
  Writefloat(number, tempindex, tempStr);
  spec = spec == 'e' ? 'e' : 'E';
  Exponent(sign, spec, count_zero, tempindex, tempStr);
  flags.width -= *tempindex - 1;
}
void NumberG(char spec, int *tempindex, char *tempStr, long double number) {
  long double spar = number;
  char sign = 0;
  int count_zero = 0;
  if (number != 0) {
    sign = SignExp(&number, &count_zero);
  }
  if ((NumberCount((int)number) > flags.precision && flags.point != 0 &&
       flags.precision != 0) ||
      (sign == '-' && count_zero > 4) ||
      (sign == '+' && count_zero > 5 && count_zero >= flags.precision)) {
    flags.precision -= NumberCount((int)number);
  } else if (flags.precision == 0) {
    if ((int)spar == 0 && flags.point > 0)
      flags.precision = 1;
    else if ((int)spar == 0)
      flags.precision = 6;
    else
      flags.precision = 6 - NumberCount((int)spar);
    sign = 0;
  } else {
    flags.precision -= NumberCount((int)spar);
    sign = 0;
  }
  Writefloat(sign == 0 ? spar : number, tempindex, tempStr);
  if (flags.flag[4] == 0) Rounding(tempindex, tempStr);
  if (sign != 0) {
    *tempindex += 1;
    spec = spec == 'g' ? 'e' : 'E';
    Exponent(sign, spec, count_zero, tempindex, tempStr);
  }
  flags.width -= *tempindex - 1;
}

void Exponent(char sign, char spec, int count_zero, int *tempindex,
              char *tempStr) {
  tempStr[*tempindex] = spec;
  *tempindex += 1;
  tempStr[*tempindex] = sign;
  *tempindex += 1;
  if (count_zero < 10) {
    tempStr[*tempindex] = '0';
    *tempindex += 1;
  }
  for (unsigned int i = s21_pow(10, NumberCount(count_zero) - 1); i > 0;
       i /= 10) {
    tempStr[*tempindex] = '0' + (count_zero / i % 10);
    *tempindex += 1;
  }
  tempStr[*tempindex] = '\0';
}

void Writefloat(long double number, int *tempindex, char *tempStr) {
  long long unsigned int numberint = (long long unsigned int)number;
  long double numberfloat = number - (long double)numberint;
  *tempindex += 1;
  for (unsigned long long int i = s21_pow(10, NumberCount(numberint) - 1);
       i > 0; i /= 10) {
    tempStr[*tempindex] = '0' + (numberint / i % 10);
    *tempindex += 1;
  }
  if (flags.flag[4] > 0 || flags.precision > 0) {
    tempStr[*tempindex] = '.';
    *tempindex += 1;
  }
  for (; flags.precision > 0; flags.precision--, *tempindex += 1) {
    numberint = numberfloat * 10;
    numberfloat = numberfloat * 10 - numberint;
    tempStr[*tempindex] = '0' + numberint;
  }
  if (flags.precision == 0 && numberfloat * 10 >= 5) {
    int temp = *tempindex - 1;
    while (tempStr[temp] == '9' && temp >= 1) {
      tempStr[temp] = '0';
      temp -= 1;
      if (temp - 1 != 0)
        if (tempStr[temp - 1] == '.' && tempStr[temp] == '9') temp--;
    }
    tempStr[temp] = tempStr[temp] + 1;
  }
  tempStr[*tempindex] = '\0';
}

void Rounding(int *tempindex, char *tempStr) {
  int i = *tempindex - 1;
  int flag = 0;
  for (; (tempStr[i] == '0' || tempStr[i] == '.') && flag != 1; i--) {
    if (tempStr[i] == '.') {
      tempStr[i] = '\0';
      i--;
      flag = 1;
    } else
      tempStr[i] = '\0';
  }
  *tempindex = i;
}

char SignExp(long double *number, int *count_zero) {
  char sign = 0;
  if (*number < 1.0) {
    do {
      *number *= 10;
      *count_zero += 1;
    } while (*number < 1.0);
    sign = '-';
  } else {
    while (*number >= 10.0) {
      *number /= 10;
      *count_zero += 1;
    }
    sign = '+';
  }
  return sign;
}
