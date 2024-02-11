#include "test_string.h"

START_TEST(test_to_upper) {
  {
    char *str1 = "Default sentence with numbers: 123";
    char *result = s21_to_upper(str1);
    ck_assert_str_eq(result, "DEFAULT SENTENCE WITH NUMBERS: 123");
    free(result);
  }

  {
    char *str1 = "";
    char *result = s21_to_upper(str1);
    ck_assert_str_eq(result, "");
    free(result);
  }

  {
    char *str1 = "LARGE LETTERS";
    char *result = s21_to_upper(str1);
    ck_assert_str_eq(result, "LARGE LETTERS");
    free(result);
  }

  {
    char *str1 = "Another\n one SenTenCE\t wWith\0 words";
    char *result = s21_to_upper(str1);
    ck_assert_str_eq(result, "ANOTHER\n ONE SENTENCE\t WWITH");
    free(result);
  }
}
END_TEST

START_TEST(test_to_lower) {
  {
    char *str1 = "Default sentence with numbers: 123";
    char *result = s21_to_lower(str1);
    ck_assert_str_eq(result, "default sentence with numbers: 123");
    free(result);
  }

  {
    char *str1 = "";
    char *result = s21_to_lower(str1);
    ck_assert_str_eq(result, "");
    free(result);
  }

  {
    char *str1 = "LARGE LETTERS";
    char *result = s21_to_lower(str1);
    ck_assert_str_eq(result, "large letters");
    free(result);
  }

  {
    char *str1 = "Another\n one SenTenCE\t wWith\0 words";
    char *result = s21_to_lower(str1);
    ck_assert_str_eq(result, "another\n one sentence\t wwith\0 words");
    free(result);
  }
}
END_TEST

START_TEST(test_trim) {
  {
    char *result = s21_trim("", "");
    ck_assert_str_eq(result, "");
    free(result);
  }

  {
    char *result = s21_trim("", "abcdefg");
    ck_assert_str_eq(result, "");
    free(result);
  }

  {
    char *result = s21_trim("one more message", "");
    ck_assert_str_eq(result, "one more message");
    free(result);
  }

  {
    char *result = s21_trim("one more message", "one more message");
    ck_assert_str_eq(result, "");
    free(result);
  }

  {
    char *result = s21_trim("+!!++Abo+ba++00", "+!0-");
    ck_assert_str_eq(result, "Abo+ba");
    free(result);
  }

  {
    char *result = s21_trim("+!!++Abo+ba++00", "+!0-");
    ck_assert_str_eq(result, "Abo+ba");
    free(result);
  }

  {
    char *result = s21_trim("Ab000cd0", "003");
    ck_assert_str_eq(result, "Ab000cd");
    free(result);
  }

  {
    char *result = s21_trim("DoNotTouch", "Not");
    ck_assert_str_eq(result, "DoNotTouch");
    free(result);
  }

  {
    char *result = s21_trim(" Good morning!    ", " ");
    ck_assert_str_eq(result, "Good morning!");
    free(result);
  }
}
END_TEST

Suite *s21_test_up_low_trim(void) {
  Suite *s2;
  TCase *tc3;
  s2 = suite_create("s21_string_lower_upper_trim");
  tc3 = tcase_create("test_low_up_trim");
  tcase_add_test(tc3, test_to_upper);
  tcase_add_test(tc3, test_to_lower);
  tcase_add_test(tc3, test_trim);
  suite_add_tcase(s2, tc3);
  return s2;
}