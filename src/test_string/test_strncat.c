#include "test_string.h"

char stringmain4[50] = "Test string";
char test11[20] = "Teststring\0";
char test21[20] = "Test\n\0";
char test31[10] = "Test\n";

START_TEST(s21_strncat_test1) {
  ck_assert_str_eq(strncat(stringmain4, test11, 3),
                   s21_strncat(stringmain4, test11, 3));
}
END_TEST
START_TEST(s21_strncat_test2) {
  ck_assert_str_eq(strncat(stringmain4, test11, 5),
                   s21_strncat(stringmain4, test11, 5));
}
END_TEST
START_TEST(s21_strncat_test3) {
  ck_assert_str_eq(strncat(stringmain4, test21, 1),
                   s21_strncat(stringmain4, test21, 1));
}
END_TEST
START_TEST(s21_strncat_test4) {
  ck_assert_str_eq(strncat(stringmain4, test31, 1),
                   s21_strncat(stringmain4, test31, 1));
}
END_TEST

START_TEST(s21_strncat_test5) {
  char str[100] = "Hello";
  char str1[100] = "world";
  ck_assert_str_eq(strncat(str, str1, 3), strncat(str, str1, 3));
}
END_TEST

START_TEST(s21_strncat_test6) {
  char str[100] = "Hello, world!";
  char str1[100] = "not helloworld((";
  ck_assert_str_eq(strncat(str, str1, strlen(str1)),
                   s21_strncat(str, str1, strlen(str1)));
}
END_TEST

START_TEST(s21_strncat_test7) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, world!";
  ck_assert_str_eq(strncat(str, str1, 13), s21_strncat(str, str1, 13));
}
END_TEST

START_TEST(s21_strncat_test8) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world\0";
  ck_assert_str_eq(strncat(str, str1, 0), s21_strncat(str, str1, 0));
}
END_TEST

START_TEST(s21_strncat_test9) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello,\n world";
  ck_assert_str_eq(strncat(str, str1, 10), s21_strncat(str, str1, 10));
}
END_TEST

START_TEST(s21_strncat_test10) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, Harry!";
  ck_assert_str_eq(strncat(str, str1, 1), s21_strncat(str, str1, 1));
}
END_TEST

START_TEST(s21_strncat_test11) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, Harry";
  ck_assert_str_eq(strncat(str, str1, 5), s21_strncat(str, str1, 5));
}
END_TEST

START_TEST(s21_strncat_test12) {
  char str[100] = "69917020";
  char str1[100] = "69917020";
  ck_assert_str_eq(strncat(str, str1, 8), s21_strncat(str, str1, 8));
}
END_TEST

START_TEST(s21_strncat_test13) {
  char str[100] = "69917020";
  char str1[100] = "69917020";
  ck_assert_str_eq(strncat(str, str1, 4), s21_strncat(str, str1, 4));
}
END_TEST

START_TEST(s21_strncat_test14) {
  char str[100] = "Hello";
  char str1[100] = "Hello";
  ck_assert_str_eq(strncat(str, str1, 6), s21_strncat(str, str1, 6));
}
END_TEST

START_TEST(s21_strncat_test15) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world!\0";
  ck_assert_str_eq(strncat(str, str1, 90), s21_strncat(str, str1, 90));
}
END_TEST

Suite *s21_test_strncat(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("strncat_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strncat_test1);
  tcase_add_test(tc, s21_strncat_test2);
  tcase_add_test(tc, s21_strncat_test3);
  tcase_add_test(tc, s21_strncat_test4);
  tcase_add_test(tc, s21_strncat_test5);
  tcase_add_test(tc, s21_strncat_test6);
  tcase_add_test(tc, s21_strncat_test7);
  tcase_add_test(tc, s21_strncat_test8);
  tcase_add_test(tc, s21_strncat_test9);
  tcase_add_test(tc, s21_strncat_test10);
  tcase_add_test(tc, s21_strncat_test11);
  tcase_add_test(tc, s21_strncat_test12);
  tcase_add_test(tc, s21_strncat_test13);
  tcase_add_test(tc, s21_strncat_test14);
  tcase_add_test(tc, s21_strncat_test15);

  suite_add_tcase(s, tc);
  return s;
}