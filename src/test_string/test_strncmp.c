#include "test_string.h"

char stringmain[50] = "Test string";
char test100[20] = "Teststring\0";
char test200[20] = "Test\n\0";
char test300[10] = "Test\n";
char test400[10] = "\n\0";
char test500[10] = "\0";

START_TEST(s21_strncmp_test1) {
  ck_assert_uint_eq(s21_strncmp(test100, stringmain, 5) > 0,
                    strncmp(test100, stringmain, 5) > 0);
}
END_TEST

START_TEST(s21_strncmp_test2) {
  ck_assert_uint_eq(s21_strncmp(test200, stringmain, 2) > 0,
                    strncmp(test200, stringmain, 2) > 0);
}
END_TEST

START_TEST(s21_strncmp_test3) {
  ck_assert_uint_eq(s21_strncmp(test300, stringmain, 4) > 0,
                    strncmp(test300, stringmain, 4) > 0);
}
END_TEST

START_TEST(s21_strncmp_test4) {
  ck_assert_uint_eq(s21_strncmp(test400, stringmain, 4) > 0,
                    strncmp(test400, stringmain, 4) > 0);
}
END_TEST

START_TEST(s21_strncmp_test5) {
  ck_assert_uint_eq(s21_strncmp(test500, stringmain, 3) > 0,
                    strncmp(test500, stringmain, 3) > 0);
}
END_TEST

START_TEST(strncmp_1) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world!";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(strncmp_2) {
  char str[] = "Hello, world!";
  char str1[] = "not helloworld((";
  s21_size_t len = strlen(str);
  ck_assert_uint_eq(strncmp(str, str1, len) < 0,
                    s21_strncmp(str, str1, len) < 0);
}
END_TEST

START_TEST(strncmp_3) {
  char str[] = "Hello, world!";
  char str1[] = "hello, world!";
  s21_size_t len = strlen(str);
  ck_assert_uint_eq(strncmp(str, str1, len) < 0,
                    s21_strncmp(str, str1, len) < 0);
}
END_TEST

START_TEST(strncmp_4) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world\0";
  s21_size_t len = strlen(str);
  ck_assert_uint_eq(strncmp(str, str1, len) > 0,
                    s21_strncmp(str, str1, len) > 0);
}
END_TEST

START_TEST(strncmp_5) {
  char str[] = "Hello, world!";
  char str1[] = "Hello,\n world";
  s21_size_t len = 10;
  ck_assert_uint_eq(strncmp(str, str1, len) > 0,
                    s21_strncmp(str, str1, len) > 0);
}
END_TEST

START_TEST(strncmp_6) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, Harry!";
  s21_size_t len = 5;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(strncmp_7) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, Harry";
  s21_size_t len = 8;
  ck_assert_uint_eq(strncmp(str, str1, len) > 0,
                    s21_strncmp(str, str1, len) > 0);
}
END_TEST

START_TEST(strncmp_8) {
  char str[] = "69917020";
  char str1[] = "69917020";
  s21_size_t len = 0;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(strncmp_9) {
  char str[] = "69917020";
  char str1[] = "69917020";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(strncmp_10) {
  char str[] = "Hello";
  char str1[] = "Hello";
  s21_size_t len = 0;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(strncmp_11) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world!\0";
  s21_size_t len = strlen(str) + 1;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

Suite *s21_test_strncmp(void) {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc = tcase_create("strncmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strncmp_test1);
  tcase_add_test(tc, s21_strncmp_test2);
  tcase_add_test(tc, s21_strncmp_test3);
  tcase_add_test(tc, s21_strncmp_test4);
  tcase_add_test(tc, s21_strncmp_test5);
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);
  tcase_add_test(tc, strncmp_11);

  suite_add_tcase(s, tc);
  return s;
}