#include "test_string.h"

char test17[20] = "Teststring\0";
char test27[20] = "Test\n\0";
char test37[10] = "Test\n";
char test47[10] = "\n\0";
char test57[10] = "\0";

START_TEST(s21_strcpy_test1) {
  char stringmain[] = "Teststring\0";
  char stringmainres[] = "Teststring\0";
  ck_assert_str_eq(s21_strcpy(stringmain, test17),
                   strcpy(stringmainres, test17));
}
END_TEST

START_TEST(s21_strcpy_test2) {
  char stringmain2[] = "Teststring\n\0";
  char stringmainres2[] = "Teststring\n\0";
  ck_assert_str_eq(s21_strcpy(stringmain2, test27),
                   strcpy(stringmainres2, test27));
}
END_TEST

START_TEST(s21_strcpy_test3) {
  char stringmain3[] = "str\n\0";
  char stringmainres3[] = "str\n\0";
  ck_assert_str_eq(s21_strcpy(stringmain3, test37),
                   strcpy(stringmainres3, test37));
}
END_TEST

START_TEST(s21_strcpy_test4) {
  char stringmain4[] = " \n\0";
  char stringmainres4[] = " \n\0";
  ck_assert_str_eq(s21_strcpy(stringmain4, test47),
                   strcpy(stringmainres4, test47));
}
END_TEST

START_TEST(s21_strcpy_test5) {
  char stringmain5[] = " \0";
  char stringmainres5[] = " \0";
  ck_assert_str_eq(s21_strcpy(stringmain5, test57),
                   strcpy(stringmainres5, test57));
}
END_TEST

START_TEST(s21_strcpy_test6) {
  char str[100] = "Hello";
  char str1[100] = "world";
  ck_assert_str_eq(strcpy(str, str1), strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test7) {
  char str[100] = "Hello, world!";
  char str1[100] = "not helloworld((";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test8) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, world!";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test9) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world\0";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test10) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello,\n world";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test11) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, Harry!";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test12) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, Harry";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test13) {
  char str[100] = "69917020";
  char str1[100] = "69917020";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test14) {
  char str[100] = "69917020";
  char str1[100] = "69917020";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test15) {
  char str[100] = "Hello";
  char str1[100] = "Hello";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

START_TEST(s21_strcpy_test16) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world!\0";
  ck_assert_str_eq(strcpy(str, str1), s21_strcpy(str, str1));
}
END_TEST

Suite *s21_test_strcpy(void) {
  Suite *s = suite_create("s21_strcpy");
  TCase *tc = tcase_create("strcpy_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strcpy_test1);
  tcase_add_test(tc, s21_strcpy_test2);
  tcase_add_test(tc, s21_strcpy_test3);
  tcase_add_test(tc, s21_strcpy_test4);
  tcase_add_test(tc, s21_strcpy_test5);
  tcase_add_test(tc, s21_strcpy_test6);
  tcase_add_test(tc, s21_strcpy_test7);
  tcase_add_test(tc, s21_strcpy_test8);
  tcase_add_test(tc, s21_strcpy_test9);
  tcase_add_test(tc, s21_strcpy_test10);
  tcase_add_test(tc, s21_strcpy_test11);
  tcase_add_test(tc, s21_strcpy_test12);
  tcase_add_test(tc, s21_strcpy_test13);
  tcase_add_test(tc, s21_strcpy_test14);
  tcase_add_test(tc, s21_strcpy_test15);
  tcase_add_test(tc, s21_strcpy_test16);

  suite_add_tcase(s, tc);
  return s;
}