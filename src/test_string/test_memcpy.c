#include "test_string.h"

START_TEST(s21_memcpy_test1) {
  char str[] = "Teststring\0";
  char str1[] = "Teststring\0";
  s21_size_t len = 10;
  ck_assert_str_eq(s21_memcpy(str, str1, len), memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test2) {
  char str[] = "test\n\0";
  char str1[] = "Test\n\0";
  s21_size_t len = 5;
  ck_assert_str_eq(s21_memcpy(str, str1, len), memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test3) {
  char str[] = "str\n\0";
  char str1[] = "Test\n";
  s21_size_t len = 4;
  ck_assert_str_eq(s21_memcpy(str, str1, len), memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test4) {
  char str[] = " \n\0";
  char str1[] = "\n\0";
  s21_size_t len = 2;
  ck_assert_str_eq(s21_memcpy(str, str1, len), memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test5) {
  char str[] = " \0";
  char str1[] = "\0";
  s21_size_t len = 2;
  ck_assert_str_eq(s21_memcpy(str, str1, len), memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test6) {
  char str[] = "Hello";
  char str1[] = "world!";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test7) {
  char str[] = "Hello";
  char str1[] = "world";
  s21_size_t len = 2;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test8) {
  char str[] = "Hello";
  char str1[] = "world!";
  s21_size_t len = 0;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test9) {
  char str[] = "Hello, world!";
  char str1[2] = "";
  s21_size_t len = 2;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test10) {
  char str[] = "12\t34\n56(!@";
  char str1[] = "Hello, world";
  s21_size_t len = 12;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test11) {
  char str[] = "Hello, world!";
  char str1[] = "12\t34\n56(!@";
  s21_size_t len = 12;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test12) {
  char str[] = "Hello, world!";
  char str1[] = "\0";
  s21_size_t len = strlen(str1);
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test13) {
  char str[] = "\0";
  char str1[] = "\0";
  s21_size_t len = 1;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test14) {
  char str[] = "\0";
  char str1[] = "\0";
  s21_size_t len = 0;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test15) {
  char str[] = "Hello";
  char str1[] = "Hello\0";
  s21_size_t len = 5;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test16) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world!\0";
  s21_size_t len = strlen(str1);
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test17) {
  char str[] = "Hello, world!";
  char str1[] = {10, 32, 64, 65, 127};
  s21_size_t len = 5;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

Suite *s21_test__memcpy(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("memcpy_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_memcpy_test1);
  tcase_add_test(tc, s21_memcpy_test2);
  tcase_add_test(tc, s21_memcpy_test3);
  tcase_add_test(tc, s21_memcpy_test4);
  tcase_add_test(tc, s21_memcpy_test5);
  tcase_add_test(tc, s21_memcpy_test6);
  tcase_add_test(tc, s21_memcpy_test7);
  tcase_add_test(tc, s21_memcpy_test8);
  tcase_add_test(tc, s21_memcpy_test9);
  tcase_add_test(tc, s21_memcpy_test10);
  tcase_add_test(tc, s21_memcpy_test11);
  tcase_add_test(tc, s21_memcpy_test12);
  tcase_add_test(tc, s21_memcpy_test13);
  tcase_add_test(tc, s21_memcpy_test14);
  tcase_add_test(tc, s21_memcpy_test15);
  tcase_add_test(tc, s21_memcpy_test16);
  tcase_add_test(tc, s21_memcpy_test17);

  suite_add_tcase(s, tc);
  return s;
}