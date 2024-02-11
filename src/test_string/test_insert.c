#include "test_string.h"

START_TEST(s21_insert_test1) {
  char mainline[] = "Test\0";
  char substring[] = "String\0";
  char *test01 = s21_insert(mainline, substring, 2);
  ck_assert_str_eq(test01, "TeStringst");
  free(test01);
}
END_TEST

START_TEST(s21_insert_test2) {
  char mainline2[] = "Test\n\0";
  char substring2[] = "String\n\0";
  char *test02 = s21_insert(mainline2, substring2, 1);
  ck_assert_str_eq(test02, "TString\nest\n\0");
  free(test02);
}
END_TEST

START_TEST(s21_insert_test3) {
  char mainline3[] = "TEST\0";
  char substring3[] = "STRING\0";
  char *test03 = s21_insert(mainline3, substring3, 3);
  ck_assert_str_eq(test03, "TESSTRINGT\0");
  free(test03);
}
END_TEST

START_TEST(s21_insert_test4) {
  char mainline4[] = " s\0";
  char substring4[] = " s\0";
  char *test04 = s21_insert(mainline4, substring4, 1);
  ck_assert_str_eq(test04, "  ss");
  free(test04);
}
END_TEST

START_TEST(s21_insert_test5) {
  char mainline5[] = "\n\0", substring5[] = "\n\0";
  char *test05 = s21_insert(mainline5, substring5, 2);
  ck_assert_ptr_eq(test05, NULL);
  free(test05);
}
END_TEST

START_TEST(s21_insert_test6) {
  char *result = s21_insert("Hello", " world", 5);
  ck_assert_str_eq(result, "Hello world");
  free(result);
}
END_TEST

START_TEST(s21_insert_test7) {
  char *result = s21_insert(" ", "Hello world", 0);
  ck_assert_str_eq(result, "Hello world ");
  free(result);
}
END_TEST

START_TEST(s21_insert_test8) {
  char *result = s21_insert("Hello", " world", 0);
  ck_assert_str_eq(result, " worldHello");
  free(result);
}
END_TEST

START_TEST(s21_insert_test9) {
  char *result = s21_insert("Hello", " world", -1);
  ck_assert_ptr_eq(result, s21_NULL);
  free(result);
}
END_TEST

START_TEST(s21_insert_test10) {
  char *result = s21_insert("Hello", " world", 15);
  ck_assert_ptr_eq(result, s21_NULL);
  free(result);
}
END_TEST

START_TEST(s21_insert_test11) {
  char *result = s21_insert("Hello world", "", 5);
  ck_assert_str_eq(result, "Hello world");
  free(result);
}
END_TEST

Suite *s21_test_insert(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("insert_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_insert_test1);
  tcase_add_test(tc, s21_insert_test2);
  tcase_add_test(tc, s21_insert_test3);
  tcase_add_test(tc, s21_insert_test4);
  tcase_add_test(tc, s21_insert_test5);
  tcase_add_test(tc, s21_insert_test6);
  tcase_add_test(tc, s21_insert_test7);
  tcase_add_test(tc, s21_insert_test8);
  tcase_add_test(tc, s21_insert_test9);
  tcase_add_test(tc, s21_insert_test10);
  tcase_add_test(tc, s21_insert_test11);

  suite_add_tcase(s, tc);
  return s;
}