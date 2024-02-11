#include "test_string.h"

START_TEST(s21_strtok_test1) {
  char str[100] = "Hello hello Hello";
  char str1[100] = "hello";
  ck_assert_pstr_eq(strtok(str, str1), strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test2) {
  char str[100] = "Hello hello Hello";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test3) {
  char str[100] = "helloHellohelloHello";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test4) {
  char str[100] = "Hello, world!";
  char str1[100] = "\0";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test5) {
  char str[100] = "Hello, world!";
  char str1[100] = "l";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test6) {
  char str[100] = "Hello, world!";
  char str1[100] = "A";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test7) {
  char str[100] = "12341234124";
  char str1[100] = "12";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test8) {
  char str[100] = "69917020";
  char str1[100] = "6998";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test9) {
  char str[100] = "Hello, what is   your name?";
  char str1[100] = " ";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test10) {
  char str[100] = "H  ello ";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test11) {
  char str[100] = "Hello, world! ";
  char str1[100] = "Hello, world!";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

Suite *s21_test_strtok(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("s21_strtok_test");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strtok_test1);
  tcase_add_test(tc, s21_strtok_test2);
  tcase_add_test(tc, s21_strtok_test3);
  tcase_add_test(tc, s21_strtok_test4);
  tcase_add_test(tc, s21_strtok_test5);
  tcase_add_test(tc, s21_strtok_test6);
  tcase_add_test(tc, s21_strtok_test7);
  tcase_add_test(tc, s21_strtok_test8);
  tcase_add_test(tc, s21_strtok_test9);
  tcase_add_test(tc, s21_strtok_test10);
  tcase_add_test(tc, s21_strtok_test11);

  suite_add_tcase(s, tc);
  return s;
}