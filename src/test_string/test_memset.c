#include "test_string.h"

START_TEST(s21_memset_test1) {
  char str[] = "Teststring\0";
  ck_assert_str_eq(s21_memset(str, '-', 4), memset(str, '-', 4));
}
END_TEST

START_TEST(s21_memset_test2) {
  char str[] = "Teststring\n\0";
  ck_assert_str_eq(s21_memset(str, '-', 4), memset(str, '-', 4));
}
END_TEST

START_TEST(s21_memset_test3) {
  char str[] = "str\n\0";
  ck_assert_str_eq(s21_memset(str, '-', 4), memset(str, '-', 4));
}
END_TEST

START_TEST(s21_memset_test4) {
  char str[] = " \n\0";
  ck_assert_str_eq(s21_memset(str, '-', 2), memset(str, '-', 2));
}
END_TEST

START_TEST(s21_memset_test5) {
  char str[] = " \0";
  ck_assert_str_eq(s21_memset(str, '-', 1), memset(str, '-', 1));
}
END_TEST

START_TEST(s21_memset_test6) {
  char str[10] = "Hello";
  char c = 'w';
  s21_size_t len = strlen(str);
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(s21_memset_test7) {
  char str[] = "Hello";
  char c = 66;
  s21_size_t len = 2;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(s21_memset_test8) {
  char str[] = "Hello";
  char c = 10;
  s21_size_t len = 0;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(s21_memset_test9) {
  char str[] = "Hello, world!";
  char c = 9;
  s21_size_t len = 2;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(s21_memset_test10) {
  char str[] = "12\t34\n56(!@";
  char c = 0;
  s21_size_t len = 12;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(s21_memset_test11) {
  char str[] = "Hello, world!";
  char c = 127;
  s21_size_t len = 12;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(s21_memset_test12) {
  char str[] = "a";
  char c = 'f';
  s21_size_t len = 1;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(s21_memset_test13) {
  char str[] = "a";
  char c = 100;
  s21_size_t len = 1;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(s21_memset_test14) {
  char str[] = "\0";
  char c = 127;
  s21_size_t len = 1;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(s21_memset_test15) {
  char str[] = "Hello";
  char c = 0;
  s21_size_t len = 5;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

Suite *s21_test_memmset(void) {
  Suite *s = suite_create("s21_memset");
  TCase *tc = tcase_create("memset_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_memset_test1);
  tcase_add_test(tc, s21_memset_test2);
  tcase_add_test(tc, s21_memset_test3);
  tcase_add_test(tc, s21_memset_test4);
  tcase_add_test(tc, s21_memset_test5);
  tcase_add_test(tc, s21_memset_test6);
  tcase_add_test(tc, s21_memset_test7);
  tcase_add_test(tc, s21_memset_test8);
  tcase_add_test(tc, s21_memset_test9);
  tcase_add_test(tc, s21_memset_test10);
  tcase_add_test(tc, s21_memset_test11);
  tcase_add_test(tc, s21_memset_test12);
  tcase_add_test(tc, s21_memset_test13);
  tcase_add_test(tc, s21_memset_test14);
  tcase_add_test(tc, s21_memset_test15);

  suite_add_tcase(s, tc);
  return s;
}