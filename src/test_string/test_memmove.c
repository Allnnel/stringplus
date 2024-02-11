#include "test_string.h"

START_TEST(s21_memmove_test1) {
  char str[] = "Teststring\0";
  char str1[] = "Teststring\0";
  s21_size_t len = 10;
  ck_assert_str_eq(s21_memmove(str, str1, len), memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test2) {
  char str[] = "Teststring\n\0";
  char str1[] = "Test\n\0";
  s21_size_t len = 4;
  ck_assert_str_eq(s21_memmove(str, str1, len), memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test3) {
  char str[] = "str\n\0";
  char str1[] = "Test\n";
  s21_size_t len = 4;
  ck_assert_str_eq(s21_memmove(str, str1, len), memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test4) {
  char str[] = " \n\0";
  char str1[] = "\n\0";
  s21_size_t len = 2;
  ck_assert_str_eq(s21_memmove(str, str1, len), memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test5) {
  char str[] = " \0";
  char str1[] = "\0";
  s21_size_t len = 2;
  ck_assert_str_eq(s21_memmove(str, str1, len), memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test6) {
  char str[10] = "Hello";
  char str1[10] = "world!";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test7) {
  char str[] = "Hello";
  char str1[] = "world";
  s21_size_t len = 2;
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test8) {
  char str[] = "Hello";
  char str1[] = "world!";
  s21_size_t len = 0;
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test9) {
  char str[] = "Hello, world!";
  char str1[2] = "";
  s21_size_t len = 2;
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test10) {
  char str[] = "12\t34\n56(!@";
  char str1[] = "Hello, world";
  s21_size_t len = 12;
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test11) {
  char str[] = "Hello, world!";
  char str1[] = "12\t34\n56(!@";
  s21_size_t len = 12;
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test12) {
  char str[] = "Hello, world!";
  char str1[] = "\0";
  s21_size_t len = strlen(str1);
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test13) {
  char str[] = "\0";
  char str1[] = "\0";
  s21_size_t len = 1;
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test14) {
  char str[] = "\0";
  char str1[] = "\0";
  s21_size_t len = 0;
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test15) {
  char str[] = "Hello";
  char str1[] = "Hello\0";
  s21_size_t len = 5;
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test16) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world!\0";
  s21_size_t len = strlen(str1);
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test17) {
  char str[] = "Hello, world!";
  char str1[] = {10, 32, 64, 65, 127};
  s21_size_t len = 5;
  ck_assert_str_eq(memmove(str, str1, len), s21_memmove(str, str1, len));
}
END_TEST

START_TEST(s21_memmove_test18) {
  char str[] = "Hello, world!";
  ck_assert_str_eq(memmove(&str[5], &str[2], 3),
                   s21_memmove(&str[5], &str[2], 3));
}
END_TEST

Suite *s21_test_memmove(void) {
  Suite *s = suite_create("s21_memmove");
  TCase *tc = tcase_create("memmove_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_memmove_test1);
  tcase_add_test(tc, s21_memmove_test2);
  tcase_add_test(tc, s21_memmove_test3);
  tcase_add_test(tc, s21_memmove_test4);
  tcase_add_test(tc, s21_memmove_test5);
  tcase_add_test(tc, s21_memmove_test6);
  tcase_add_test(tc, s21_memmove_test7);
  tcase_add_test(tc, s21_memmove_test8);
  tcase_add_test(tc, s21_memmove_test9);
  tcase_add_test(tc, s21_memmove_test10);
  tcase_add_test(tc, s21_memmove_test11);
  tcase_add_test(tc, s21_memmove_test12);
  tcase_add_test(tc, s21_memmove_test13);
  tcase_add_test(tc, s21_memmove_test14);
  tcase_add_test(tc, s21_memmove_test15);
  tcase_add_test(tc, s21_memmove_test16);
  tcase_add_test(tc, s21_memmove_test17);
  tcase_add_test(tc, s21_memmove_test18);

  suite_add_tcase(s, tc);
  return s;
}