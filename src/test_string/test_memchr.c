#include "test_string.h"

char test1999[20] = "Teststring\0";
char test2999[20] = "Test\n\0";
char test3999[10] = "Test\n";
char test4999[10] = "\n\0";
char test5999[10] = "\0";
char test6999[15] = "Hello, world!";
char test7999[10] = "69917020";

START_TEST(s21_memchr_test1999) {
  int ch = 't';
  s21_size_t len = 12;
  ck_assert_str_eq(s21_memchr(test1999, ch, len), memchr(test1999, ch, len));
}
END_TEST
START_TEST(s21_memchr_test2999) {
  int ch = 's';
  s21_size_t len = 10;
  ck_assert_str_eq(s21_memchr(test2999, ch, len), memchr(test2999, ch, len));
}
END_TEST
START_TEST(s21_memchr_test3999) {
  int ch = '\n';
  s21_size_t len = 5;
  ck_assert_str_eq(s21_memchr(test3999, ch, len), memchr(test3999, ch, len));
}
END_TEST
START_TEST(s21_memchr_test4999) {
  int ch = '\n';
  s21_size_t len = 3;
  ck_assert_str_eq(s21_memchr(test4999, ch, len), memchr(test4999, ch, len));
}
END_TEST
START_TEST(s21_memchr_test5999) {
  int ch = ' ';
  s21_size_t len = 3;
  ck_assert_ptr_eq(s21_memchr(test5999, ch, len), memchr(test5999, ch, len));
}
END_TEST
START_TEST(s21_memchr_test6999) {
  int ch = '\0';
  s21_size_t len = 4;
  ck_assert_ptr_eq(s21_memchr(test5999, ch, len), memchr(test5999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test7999) {
  int ch = 'e';
  s21_size_t len = strlen(test6999);
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test8) {
  int ch = 119;
  s21_size_t len = strlen(test6999);
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test9) {
  int ch = 'h';
  s21_size_t len = strlen(test6999);
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19990) {
  int ch = 67;
  s21_size_t len = strlen(test6999);
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19991) {
  int ch = 'o';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19992) {
  int ch = ' ';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19993) {
  int ch = 127;
  s21_size_t len = strlen(test6999);
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19994) {
  int ch = '6';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(test7999, ch, len), s21_memchr(test7999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19995) {
  int ch = 'g';
  s21_size_t len = strlen(test7999);
  ck_assert_ptr_eq(memchr(test7999, ch, len), s21_memchr(test7999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19996) {
  int ch = '\0';
  s21_size_t len = 9;
  ck_assert_ptr_eq(memchr(test7999, ch, len), s21_memchr(test7999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19997) {
  int ch = 'e';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19998) {
  int ch = 'd';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test19999) {
  int ch = '\0';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

START_TEST(s21_memchr_test29990) {
  int ch = '\0';
  s21_size_t len = 15;
  ck_assert_ptr_eq(memchr(test6999, ch, len), s21_memchr(test6999, ch, len));
}
END_TEST

Suite *s21_test_memchr(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc = tcase_create("memchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_memchr_test1999);
  tcase_add_test(tc, s21_memchr_test2999);
  tcase_add_test(tc, s21_memchr_test3999);
  tcase_add_test(tc, s21_memchr_test4999);
  tcase_add_test(tc, s21_memchr_test5999);
  tcase_add_test(tc, s21_memchr_test6999);
  tcase_add_test(tc, s21_memchr_test7999);
  tcase_add_test(tc, s21_memchr_test8);
  tcase_add_test(tc, s21_memchr_test9);
  tcase_add_test(tc, s21_memchr_test19990);
  tcase_add_test(tc, s21_memchr_test19991);
  tcase_add_test(tc, s21_memchr_test19992);
  tcase_add_test(tc, s21_memchr_test19993);
  tcase_add_test(tc, s21_memchr_test19994);
  tcase_add_test(tc, s21_memchr_test19995);
  tcase_add_test(tc, s21_memchr_test19996);
  tcase_add_test(tc, s21_memchr_test19997);
  tcase_add_test(tc, s21_memchr_test19998);
  tcase_add_test(tc, s21_memchr_test19999);
  tcase_add_test(tc, s21_memchr_test29990);

  suite_add_tcase(s, tc);
  return s;
}