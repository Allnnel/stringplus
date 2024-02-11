#include "test_string.h"

char string[] = "TESTS_STRING";
char test18[20] = "Teststring\0";
char test28[20] = "Test\n\0";
char test38[10] = "Test\n";
char test48[10] = "\n\0";
char test58[10] = "\0";

START_TEST(s21_strcmp_test1) {
  ck_assert_uint_eq(s21_strcmp(test18, string) > 0, strcmp(test18, string) > 0);
}
END_TEST
START_TEST(s21_strcmp_test2) {
  ck_assert_uint_eq(s21_strcmp(test28, string) > 0, strcmp(test28, string) > 0);
}
END_TEST
START_TEST(s21_strcmp_test3) {
  ck_assert_uint_eq(s21_strcmp(test38, string) > 0, strcmp(test38, string) > 0);
}
END_TEST
START_TEST(s21_strcmp_test4) {
  ck_assert_uint_eq(s21_strcmp(test48, string) > 0, strcmp(test48, string) > 0);
}
END_TEST
START_TEST(s21_strcmp_test5) {
  ck_assert_uint_eq(s21_strcmp(test58, string) > 0, strcmp(test58, string) > 0);
}
END_TEST

START_TEST(s21_strcmp_test6) {
  char str[100] = "Hello";
  char str1[100] = "Hello";
  ck_assert_int_eq(strcmp(str, str1), strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_test7) {
  char str[100] = "Hello, world!";
  char str1[100] = "not helloworld((";
  ck_assert_uint_eq(strcmp(str, str1) < 0, s21_strcmp(str, str1) < 0);
}
END_TEST

START_TEST(s21_strcmp_test8) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, world!";
  ck_assert_uint_eq(strcmp(str, str1) < 0, s21_strcmp(str, str1) < 0);
}
END_TEST

START_TEST(s21_strcmp_test9) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world\0";
  ck_assert_uint_eq(strcmp(str, str1) > 0, s21_strcmp(str, str1) > 0);
}
END_TEST

START_TEST(s21_strcmp_test10) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello,\n world";
  ck_assert_uint_eq(strcmp(str, str1) > 0, s21_strcmp(str, str1) > 0);
}
END_TEST

START_TEST(s21_strcmp_test11) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, Harry!";
  ck_assert_uint_eq(strcmp(str, str1) > 0, s21_strcmp(str, str1) > 0);
}
END_TEST

START_TEST(s21_strcmp_test12) {
  char str[100] = "ABCD";
  char str1[100] = {65, 66, 67, 68};
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_test13) {
  char str[100] = "ABCD";
  char str1[100] = {65, 66, 67, 68, 0};
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_test14) {
  char str[100] = "ABCD";
  char str1[100] = {65, 67, 66, 68};
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

Suite *s21_test_strcmp(void) {
  Suite *s = suite_create("s21_strmp");
  TCase *tc = tcase_create("strcmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strcmp_test1);
  tcase_add_test(tc, s21_strcmp_test2);
  tcase_add_test(tc, s21_strcmp_test3);
  tcase_add_test(tc, s21_strcmp_test4);
  tcase_add_test(tc, s21_strcmp_test5);
  tcase_add_test(tc, s21_strcmp_test6);
  tcase_add_test(tc, s21_strcmp_test7);
  tcase_add_test(tc, s21_strcmp_test8);
  tcase_add_test(tc, s21_strcmp_test9);
  tcase_add_test(tc, s21_strcmp_test10);
  tcase_add_test(tc, s21_strcmp_test11);
  tcase_add_test(tc, s21_strcmp_test12);
  tcase_add_test(tc, s21_strcmp_test13);
  tcase_add_test(tc, s21_strcmp_test14);

  suite_add_tcase(s, tc);
  return s;
}