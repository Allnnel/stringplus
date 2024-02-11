#ifndef STR_H
#define STR_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
#define prec 0.00000000000000000000001
#define defnan 0.0 / 0.0
typedef long unsigned s21_size_t;

// MATH
long int s21_pow(long int x, unsigned int n);
// ВЫЧИСЛЕНИЯ
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);
// КОПИРОВАНИЯ
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
// ПОИСКА
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strrchr(const char *str, int c);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
// СРАВНЕНИЯ
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
// ВСПОМОГАТЕЛЬНЫЕ
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
// СПЕЦИАЛЬНЫЕ
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
// ВЫВОД
int s21_sprintf(char *str, const char *format, ...);
int NumberCount(unsigned long long number);
char *WidthAndPrecision(char *point_format, va_list variable);
char *SprintfFlags(char *point_format);
char *s21_Length(char *point_format);
void Specificator(char *str, char *point_format, int *index_str,
                  va_list variable);
void NumberInt(char spec, int *index_str, va_list variable, char *tempBuf);
void NumberUint(char spec, int *tempindex, va_list variable, char *tempStr);
void FuncIntUint(char spec, int *tempindex, long long int number,
                 char *tenpStr);
void BuFilling(char *str, char *tempStr, int *index_str, int tempindex,
               char spec);
void FunWriteIntlen(char *str, int count, int *index_str, char ch);
void CleanSruct();
void MinusPlus(char *str, int *index_str);
unsigned long int NumberX(va_list variable);
void FuncX(char spec, int *tempindex, char *tenpStr, va_list variable);
void WriteNubertemp(char *tenpStr, int *tempindex, const char *Nubertemp,
                    int index);
void FuncO(int *tempindex, char *tenpStr, va_list variable);
char SignExp(long double *number, int *count_zero);
void NumberG(char spec, int *tempindex, char *tempStr, long double number);
void NumberFloat(char spec, int *tempindex, va_list variable, char *tempStr);
void inf(int *tempindex, char *tempStr);
void nun(int *tempindex, char *tempStr);
void Rounding(int *tempindex, char *tempStr);
void Exponent(char sign, char spec, int count_zero, int *tempindex,
              char *tempStr);
void Writefloat(long double number, int *tempindex, char *tempStr);
void NumberE(char spec, int *tempindex, char *tempStr, long double number);
void NumberF(int *tempindex, char *tempStr, long double number);
void NumbeP(int *tempindex, va_list variable, char *tempStr);
void Char(int *tempindex, va_list variable, char *tempStr);
void String(int *tempindex, va_list variable, char *tempStr);

// ВВОД
typedef struct {
  char specifier;
  int wight;
  int h;
  int l;
  int L;
  int star;
  int f;
  int ll;
  int it;
  int minus;
} Length;
int s21_sscanf(const char *str, const char *format, ...);
const char *space(const char *ptr_str);
const char *star(const char *ptr_str, Length *length);
const char *countvalue(const char *ptr_str, Length *length, long long *value);
const char *count_value_for_f(const char *ptr_str, Length *length,
                              long long **value, int wight);
int pars(const char *str, const char *format, va_list list);
const char *findwight(const char *format, Length *length);
const char *findlength(const char *format, Length *length);
const char *findspecifier(const char *ptr_str, const char *ptr_format,
                          va_list list, Length *length);
const char *forchar(const char *ptr_str, va_list list, Length *length);
const char *forstr(const char *ptr_str, va_list list, Length *length);
const char *forint(const char *ptr_str, va_list list, Length *length);
const char *forfloat(const char *ptr_str, va_list list, Length *length);
const char *forOct(const char *ptr_str, va_list list, Length *length);
const char *forHex(const char *ptr_str, va_list list, Length *length);
const char *forIndex(const char *ptr_str, va_list list, Length *length);
const char *forpointer(const char *ptr_str, va_list list, Length *length);
int Scan(const char *ptr_str);
int convert(int value);
int strValidScan(char c);
#endif
