#include "test_string.h"

char underthesymbol[] = "0 4 str \n";
char test15[20] = "Teststring\0";
char test25[20] = "Test\n\0";
char test35[10] = "Test\n";
char test45[10] = "\n\0";
char test55[10] = "\0";

START_TEST(s21_strcspn_test1) {
  ck_assert_uint_eq(s21_strcspn(test15, underthesymbol),
                    strcspn(test15, underthesymbol));
}
END_TEST
START_TEST(s21_strcspn_test2) {
  ck_assert_uint_eq(s21_strcspn(test25, underthesymbol),
                    strcspn(test25, underthesymbol));
}
END_TEST

START_TEST(s21_strcspn_test3) {
  ck_assert_uint_eq(s21_strcspn(test35, underthesymbol),
                    strcspn(test35, underthesymbol));
}
END_TEST

START_TEST(s21_strcspn_test4) {
  ck_assert_uint_eq(s21_strcspn(test45, underthesymbol),
                    strcspn(test45, underthesymbol));
}
END_TEST

START_TEST(s21_strcspn_test5) {
  ck_assert_uint_eq(s21_strcspn(test55, underthesymbol),
                    strcspn(test55, underthesymbol));
}
END_TEST

START_TEST(s21_strcspn_test6) {
  char str[100] = "Hello, world!";
  char str1[100] = "world";
  ck_assert_uint_eq(strcspn(str, str1), strcspn(str, str1));
}
END_TEST

START_TEST(s21_strcspn_test7) {
  char str[100] = "Hello, world!";
  char str1[100] = "not helloworld((";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(s21_strcspn_test8) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, world!";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(s21_strcspn_test9) {
  char str[100] = "Hello, world!";
  char str1[100] = "abc";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(s21_strcspn_test13) {
  char str[100] = "1234347";
  char str1[100] = "123";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(s21_strcspn_test14) {
  char str[100] = "1234347";
  char str1[100] = "321";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(s21_strcspn_test15) {
  char str[100] = "";
  char str1[100] = "";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(s21_strcspn_test16) {
  char str[100] = "";
  char str1[100] = "Hello, world!";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

Suite *s21_test_strcspn(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("strcspn_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strcspn_test1);
  tcase_add_test(tc, s21_strcspn_test2);
  tcase_add_test(tc, s21_strcspn_test3);
  tcase_add_test(tc, s21_strcspn_test4);
  tcase_add_test(tc, s21_strcspn_test5);
  tcase_add_test(tc, s21_strcspn_test6);
  tcase_add_test(tc, s21_strcspn_test7);
  tcase_add_test(tc, s21_strcspn_test8);
  tcase_add_test(tc, s21_strcspn_test9);
  tcase_add_test(tc, s21_strcspn_test13);
  tcase_add_test(tc, s21_strcspn_test14);
  tcase_add_test(tc, s21_strcspn_test15);
  tcase_add_test(tc, s21_strcspn_test16);

  suite_add_tcase(s, tc);
  return s;
}