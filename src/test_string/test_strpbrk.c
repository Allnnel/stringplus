#include "test_string.h"

START_TEST(s21_strpbrk_test1) {
  char str[100] = "Hello, world!";
  char str1[100] = "world";
  ck_assert_pstr_eq(strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test2) {
  char str[100] = "Hello, world!";
  char str1[100] = "not helloworld((";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test3) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, world!";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test4) {
  char str[100] = "Hello, world!";
  char str1[100] = "abc";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test5) {
  char str[100] = "Hello, world!";
  char str1[100] = "";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test6) {
  char str[100] = "Hello, world!";
  char str1[100] = "\0";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test7) {
  char str[100] = "1234347";
  char str1[100] = "89";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test8) {
  char str[100] = "1234347";
  char str1[100] = "123";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test9) {
  char str[100] = "1234347";
  char str1[100] = "321";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test10) {
  char str[100] = "";
  char str1[100] = "";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test11) {
  char str[100] = "";
  char str1[100] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

Suite *s21_test_strpbrk(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("s21_strpbrk_test");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strpbrk_test1);
  tcase_add_test(tc, s21_strpbrk_test2);
  tcase_add_test(tc, s21_strpbrk_test3);
  tcase_add_test(tc, s21_strpbrk_test4);
  tcase_add_test(tc, s21_strpbrk_test5);
  tcase_add_test(tc, s21_strpbrk_test6);
  tcase_add_test(tc, s21_strpbrk_test7);
  tcase_add_test(tc, s21_strpbrk_test8);
  tcase_add_test(tc, s21_strpbrk_test9);
  tcase_add_test(tc, s21_strpbrk_test10);
  tcase_add_test(tc, s21_strpbrk_test11);

  suite_add_tcase(s, tc);
  return s;
}