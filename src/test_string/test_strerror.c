#include "test_string.h"

START_TEST(s21_strerror_test) {
  int i = 0;
  while (i < 135) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
    i++;
  }
}
END_TEST

Suite *s21_test_strerror(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("strerror_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_strerror_test);

  suite_add_tcase(s, tc);
  return s;
}