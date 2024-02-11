#include "test_string.h"

START_TEST(s21_strrchr_test1) {
  char str[100] = "Hello";
  char c = 'e';
  ck_assert_pstr_eq(strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_test2) {
  char str[100] = "Hello, world!";
  char c = 'o';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_test3) {
  char str[100] = "Hello, world!";
  char c = 'h';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_test4) {
  char str[100] = "Hello, world!";
  char c = 'H';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_test5) {
  char str[100] = "Hello, world!";
  char c = 69;
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_test6) {
  char str[100] = "Hello, world!";
  char c = 68;
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_test7) {
  char str[100] = "Hello, world!";
  char c = 0;
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_test8) {
  char str[100] = "69917020";
  char c = '\0';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_test9) {
  char str[100] = "69917020";
  char c = '0';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

Suite *s21_test_strrchr(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("s21_strrchr_test");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strrchr_test1);
  tcase_add_test(tc, s21_strrchr_test2);
  tcase_add_test(tc, s21_strrchr_test3);
  tcase_add_test(tc, s21_strrchr_test4);
  tcase_add_test(tc, s21_strrchr_test5);
  tcase_add_test(tc, s21_strrchr_test6);
  tcase_add_test(tc, s21_strrchr_test7);
  tcase_add_test(tc, s21_strrchr_test8);
  tcase_add_test(tc, s21_strrchr_test9);

  suite_add_tcase(s, tc);
  return s;
}
