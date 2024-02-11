#include "test_string.h"

char test12[20] = "Teststring\0";
char test22[20] = "Test\n\0";
char test32[10] = "Test\n";
char test42[10] = "\n\0";
char test52[10] = "\0";

START_TEST(s21_strlen_test1) {
  ck_assert_uint_eq(s21_strlen(test12), strlen(test12));
}
END_TEST
START_TEST(s21_strlen_test2) {
  ck_assert_uint_eq(s21_strlen(test22), strlen(test22));
}
END_TEST
START_TEST(s21_strlen_test3) {
  ck_assert_uint_eq(s21_strlen(test32), strlen(test32));
}
END_TEST
START_TEST(s21_strlen_test4) {
  ck_assert_uint_eq(s21_strlen(test42), strlen(test42));
}
END_TEST
START_TEST(s21_strlen_test5) {
  ck_assert_uint_eq(s21_strlen(test52), strlen(test52));
}
END_TEST

START_TEST(s21_strlen_test6) {
  char *str = "";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test7) {
  char *str = "Hello, world!";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test8) {
  char *str = "12341";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test9) {
  char *str = "   ";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test10) {
  char *str = "\0";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test11) {
  char *str = "2asfaf90au11-fa";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test12) {
  char str[4] = {14, 65, 127, 56};
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(s21_strlen_test13) {
  char str[6] = {65, 66, 0, 0, 0, 65};
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *s21_test_strlen(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("strlen_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strlen_test1);
  tcase_add_test(tc, s21_strlen_test2);
  tcase_add_test(tc, s21_strlen_test3);
  tcase_add_test(tc, s21_strlen_test4);
  tcase_add_test(tc, s21_strlen_test5);
  tcase_add_test(tc, s21_strlen_test6);
  tcase_add_test(tc, s21_strlen_test7);
  tcase_add_test(tc, s21_strlen_test8);
  tcase_add_test(tc, s21_strlen_test9);
  tcase_add_test(tc, s21_strlen_test10);
  tcase_add_test(tc, s21_strlen_test11);
  tcase_add_test(tc, s21_strlen_test12);
  tcase_add_test(tc, s21_strlen_test13);

  suite_add_tcase(s, tc);
  return s;
}