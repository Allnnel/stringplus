#ifndef SRC_TEST_STRING_H
#define SRC_TEST_STRING_H

#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *s21_test_insert(void);
Suite *s21_test_memchr(void);
Suite *s21_test_memcmp(void);
Suite *s21_test__memcpy(void);
Suite *s21_test_memmove(void);
Suite *s21_test_memmset(void);
Suite *scanf_func_test(void);
Suite *sprinf_func_test(void);
Suite *s21_test_strcat(void);
Suite *s21_test_strchr(void);
Suite *s21_test_strcmp(void);
Suite *s21_test_strcpy(void);
Suite *s21_test_strcspn(void);
Suite *s21_test_strerror(void);
Suite *s21_test_strlen(void);
Suite *s21_test_strncat(void);
Suite *s21_test_strncmp(void);
Suite *s21_test_strncpy(void);
Suite *s21_test_strtok(void);
Suite *s21_test_strpbrk(void);
Suite *s21_test_strrchr(void);
Suite *s21_test_strspn(void);
Suite *s21_test_strstr(void);
Suite *s21_test_up_low_trim(void);

#endif  // SRC_TEST_STRING_H