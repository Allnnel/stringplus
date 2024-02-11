#include "test_string.h"

char test19[20] = "Teststring\0";
char test29[20] = "Test\n\0";
char test39[10] = "Test\n";
char test49[10] = "\n\0";
char test59[10] = "\0";

START_TEST(s21_strchr_test1) {
  ck_assert_str_eq(s21_strchr(test19, 's'), strchr(test19, 's'));
}
END_TEST
START_TEST(s21_strchr_test2) {
  ck_assert_str_eq(s21_strchr(test29, 't'), strchr(test29, 't'));
}
END_TEST
START_TEST(s21_strchr_test3) {
  ck_assert_ptr_eq(s21_strchr(test39, 'e'), strchr(test39, 'e'));
}
END_TEST
START_TEST(s21_strchr_test4) {
  ck_assert_ptr_eq(s21_strchr(test49, '\0'), strchr(test49, '\0'));
}
END_TEST
START_TEST(s21_strchr_test5) {
  ck_assert_ptr_eq(s21_strchr(test59, 's'), strchr(test59, 's'));
}
END_TEST

START_TEST(s21_strchr_test6) {
  char str[100] = "Hello";
  char c = 'e';
  ck_assert_pstr_eq(strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test7) {
  char str[100] = "Hello, world!";
  char c = 'o';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test8) {
  char str[100] = "Hello, world!";
  char c = 'h';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test9) {
  char str[100] = "Hello, world!";
  char c = 'H';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test10) {
  char str[100] = "Hello, world!";
  char c = 69;
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test11) {
  char str[100] = "Hello, world!";
  char c = 68;
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test12) {
  char str[100] = "Hello, world!";
  char c = 0;
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test13) {
  char str[100] = "69917020";
  char c = '\0';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test14) {
  char str[100] = "69917020";
  char c = '0';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

Suite *s21_test_strchr(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("strchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strchr_test1);
  tcase_add_test(tc, s21_strchr_test2);
  tcase_add_test(tc, s21_strchr_test3);
  tcase_add_test(tc, s21_strchr_test4);
  tcase_add_test(tc, s21_strchr_test5);
  tcase_add_test(tc, s21_strchr_test6);
  tcase_add_test(tc, s21_strchr_test7);
  tcase_add_test(tc, s21_strchr_test8);
  tcase_add_test(tc, s21_strchr_test9);
  tcase_add_test(tc, s21_strchr_test10);
  tcase_add_test(tc, s21_strchr_test11);
  tcase_add_test(tc, s21_strchr_test12);
  tcase_add_test(tc, s21_strchr_test13);
  tcase_add_test(tc, s21_strchr_test14);

  suite_add_tcase(s, tc);
  return s;
}