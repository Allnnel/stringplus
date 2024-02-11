#include "test_string.h"

char mainline[20] = "Teststring\n\0";
char test178[20] = "Teststring\0";
char test278[20] = "Test\n\0";
char test378[10] = "Test\n";
char test478[10] = "\n\0";
char test578[10] = "\0";
char test678[15] = "Hello, world!";
char test978[15] = "Hello, world!";
char test778[10] = "69917020";
char test988[10] = "69917020";

START_TEST(s21_memcmp_test178) {
  s21_size_t len = 10;
  ck_assert_uint_eq(s21_memcmp(test178, mainline, len) == 0,
                    memcmp(test178, mainline, len) == 0);
}
END_TEST
START_TEST(s21_memcmp_test278) {
  s21_size_t len = 4;
  ck_assert_uint_eq(s21_memcmp(test278, mainline, len) > 0,
                    memcmp(test278, mainline, len) > 0);
}
END_TEST
START_TEST(s21_memcmp_test378) {
  s21_size_t len = 2;
  ck_assert_uint_eq(s21_memcmp(test378, mainline, len) > 0,
                    memcmp(test378, mainline, len) > 0);
}
END_TEST
START_TEST(s21_memcmp_test478) {
  s21_size_t len = 2;
  ck_assert_uint_eq(s21_memcmp(test478, mainline, len) < 0,
                    memcmp(test478, mainline, len) < 0);
}
END_TEST
START_TEST(s21_memcmp_test578) {
  s21_size_t len = 8;
  ck_assert_uint_eq(s21_memcmp(test578, mainline, len) < 0,
                    memcmp(test578, mainline, len) < 0);
}
END_TEST

START_TEST(s21_memcmp_test678) {
  s21_size_t len = strlen(test678);
  ck_assert_int_eq(memcmp(test678, test978, len),
                   s21_memcmp(test678, test978, len));
}
END_TEST

START_TEST(s21_memcmp_test778) {
  char str1[] = "not helloworld((";
  s21_size_t len = strlen(test678);
  ck_assert_uint_eq(memcmp(test678, str1, len) < 0,
                    s21_memcmp(test678, str1, len) < 0);
}
END_TEST

START_TEST(s21_memcmp_test8) {
  char str1[] = "hello, world!";
  s21_size_t len = strlen(test678);
  ck_assert_uint_eq(memcmp(test678, str1, len) < 0,
                    s21_memcmp(test678, str1, len) < 0);
}
END_TEST

START_TEST(s21_memcmp_test9) {
  char str1[] = "Hello, world\0";
  s21_size_t len = strlen(test678);
  ck_assert_uint_eq(memcmp(test678, str1, len) > 0,
                    s21_memcmp(test678, str1, len) > 0);
}
END_TEST

START_TEST(s21_memcmp_test1780) {
  char str1[] = "Hello,\n world";
  s21_size_t len = 10;
  ck_assert_uint_eq(memcmp(test678, str1, len) > 0,
                    s21_memcmp(test678, str1, len) > 0);
}
END_TEST

START_TEST(s21_memcmp_test1781) {
  char str1[] = "Hello, Harry!";
  s21_size_t len = 5;
  ck_assert_int_eq(memcmp(test678, str1, len), s21_memcmp(test678, str1, len));
}
END_TEST

START_TEST(s21_memcmp_test1782) {
  char str1[] = "Hello, Harry";
  s21_size_t len = 8;
  ck_assert_uint_eq(memcmp(test678, str1, len) > 0,
                    s21_memcmp(test678, str1, len) > 0);
}
END_TEST

START_TEST(s21_memcmp_test1783) {
  s21_size_t len = 0;
  ck_assert_int_eq(memcmp(test778, test988, len),
                   s21_memcmp(test778, test988, len));
}
END_TEST

START_TEST(s21_memcmp_test1784) {
  s21_size_t len = strlen(test778);
  ck_assert_int_eq(memcmp(test778, test988, len),
                   s21_memcmp(test778, test988, len));
}
END_TEST

START_TEST(s21_memcmp_test1785) {
  char str1[] = "Hello";
  s21_size_t len = 0;
  ck_assert_int_eq(memcmp(test678, str1, len), s21_memcmp(test678, str1, len));
}
END_TEST

START_TEST(s21_memcmp_test1786) {
  char str1[] = "Hello, world!\0";
  s21_size_t len = strlen(test678) + 1;
  ck_assert_int_eq(memcmp(test678, str1, len), s21_memcmp(test678, str1, len));
}
END_TEST

Suite *s21_test_memcmp(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("memcmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_memcmp_test178);
  tcase_add_test(tc, s21_memcmp_test278);
  tcase_add_test(tc, s21_memcmp_test378);
  tcase_add_test(tc, s21_memcmp_test478);
  tcase_add_test(tc, s21_memcmp_test578);
  tcase_add_test(tc, s21_memcmp_test678);
  tcase_add_test(tc, s21_memcmp_test778);
  tcase_add_test(tc, s21_memcmp_test8);
  tcase_add_test(tc, s21_memcmp_test9);
  tcase_add_test(tc, s21_memcmp_test1780);
  tcase_add_test(tc, s21_memcmp_test1781);
  tcase_add_test(tc, s21_memcmp_test1782);
  tcase_add_test(tc, s21_memcmp_test1783);
  tcase_add_test(tc, s21_memcmp_test1784);
  tcase_add_test(tc, s21_memcmp_test1785);
  tcase_add_test(tc, s21_memcmp_test1786);

  suite_add_tcase(s, tc);
  return s;
}