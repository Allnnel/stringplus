#include "test_string.h"

START_TEST(s21_strcat_test1) {
  char str[50] = "Teststring\0";
  char str1[20] = "Teststring\0";

  ck_assert_str_eq(s21_strcat(str, str1), strcat(str, str1));
}
END_TEST
START_TEST(s21_strcat_test2) {
  char str[50] = "Teststring\n\0";
  char str1[20] = "Test\n\0";

  ck_assert_str_eq(s21_strcat(str, str1), strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test3) {
  char str[50] = "str\n\0";
  char str1[10] = "Test\n";

  ck_assert_str_eq(s21_strcat(str, str1), strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test4) {
  char str[50] = " \n\0";
  char str1[10] = "\n\0";

  ck_assert_str_eq(s21_strcat(str, str1), strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test5) {
  char str[50] = " \0";
  char str1[10] = "\0";
  ck_assert_str_eq(s21_strcat(str, str1), strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test6) {
  char str[100] = "Hello";
  char str1[100] = "world";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test7) {
  char str[100] = "Hello, world!";
  char str1[100] = "not helloworld((";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test8) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, world!";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test9) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world\0";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test10) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello,\n world";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test11) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, Harry!";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test12) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, Harry";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test13) {
  char str[100] = "69917020";
  char str1[100] = "69917020";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test14) {
  char str[100] = "69917020";
  char str1[100] = "69917020";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test15) {
  char str[100] = "Hello";
  char str1[100] = "Hello";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_test16) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world!\0";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

Suite *s21_test_strcat(void) {
  Suite *s = suite_create("s21_strcat");
  TCase *tc = tcase_create("strcat_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strcat_test1);
  tcase_add_test(tc, s21_strcat_test2);
  tcase_add_test(tc, s21_strcat_test3);
  tcase_add_test(tc, s21_strcat_test4);
  tcase_add_test(tc, s21_strcat_test5);
  tcase_add_test(tc, s21_strcat_test6);
  tcase_add_test(tc, s21_strcat_test7);
  tcase_add_test(tc, s21_strcat_test8);
  tcase_add_test(tc, s21_strcat_test9);
  tcase_add_test(tc, s21_strcat_test10);
  tcase_add_test(tc, s21_strcat_test11);
  tcase_add_test(tc, s21_strcat_test12);
  tcase_add_test(tc, s21_strcat_test13);
  tcase_add_test(tc, s21_strcat_test14);
  tcase_add_test(tc, s21_strcat_test15);
  tcase_add_test(tc, s21_strcat_test16);

  suite_add_tcase(s, tc);
  return s;
}