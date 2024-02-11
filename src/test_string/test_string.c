#include "test_string.h"

int main(void) {
  int failed = 0;
  int all = 0;
  int success = 0;
  Suite *list_cases[] = {s21_test_insert(),
                         s21_test_memchr(),
                         s21_test_memcmp(),
                         s21_test__memcpy(),
                         s21_test_memmove(),
                         s21_test_memmset(),
                         scanf_func_test(),
                         sprinf_func_test(),
                         s21_test_strcat(),
                         s21_test_strchr(),
                         s21_test_strcmp(),
                         s21_test_strcpy(),
                         s21_test_strcspn(),
                         s21_test_strerror(),
                         s21_test_strlen(),
                         s21_test_strncat(),
                         s21_test_strncmp(),
                         s21_test_strncpy(),
                         s21_test_strtok(),
                         s21_test_strpbrk(),
                         s21_test_strrchr(),
                         s21_test_strspn(),
                         s21_test_strstr(),
                         s21_test_up_low_trim(),
                         NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    SRunner *sr = srunner_create(list_cases[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    all += srunner_ntests_run(sr);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  success = all - failed;
  printf("ALL: %d \n", all);
  printf("SUCCESS: %d \n", success);
  printf("FAILED: %d \n", failed);

  return failed == 0 ? 0 : 1;
}