#include "test_string.h"

char test1[20] = "Teststring\0";
char test2[20] = "Test\n\0";
char test3[10] = "Test\n";
char test4[10] = "\n\0";
char test5[10] = "\0";

START_TEST(s21_sprintf_test) {
  char s21_buffer1[256] = {0};
  char buffer1[256] = {0};
  s21_sprintf(s21_buffer1, "%%%% %c %s %c%s %c %s %s %s", 'a', test1, '\n',
              test2, '-', test3, test4, test5);
  sprintf(buffer1, "%%%% %c %s %c%s %c %s %s %s", 'a', test1, '\n', test2, '-',
          test3, test4, test5);
  ck_assert_str_eq(s21_buffer1, buffer1);

  char s21_buffer2[256] = {0};
  char buffer2[256] = {0};
  s21_sprintf(s21_buffer2, "%-2i %5i % i %2i %4d %d %15d %15d %22u", 101, -210,
              -0, '0', 101, -210, -0, '0', (unsigned int)101);
  sprintf(buffer2, "%-2i %5i % i %2i %4d %d %15d %15d %22u", 101, -210, -0, '0',
          101, -210, -0, '0', (unsigned int)101);
  ck_assert_str_eq(s21_buffer2, buffer2);

  char s21_buffer4[256] = {0};
  char buffer4[256] = {0};
  s21_sprintf(s21_buffer4, "%01.5f %1.4f %-1.5f", 123.212, 3.4414414,
              123.1312321);
  sprintf(buffer4, "%01.5f %1.4f %-1.5f", 123.212, 3.4414414, 123.1312321);
  ck_assert_str_eq(s21_buffer4, buffer4);
}
END_TEST

START_TEST(s21_sprintf_test2) {
  char s21_buffer5[256] = {0};
  char buffer5[256] = {0};
  s21_sprintf(s21_buffer5, "|%e| %.3g %E %e %4.10g", 0.000000000078,
              0.0000000000234, 0.000013, 0.000012341234, 0.0000000242424);
  sprintf(buffer5, "|%e| %.3g %E %e %4.10g", 0.000000000078, 0.0000000000234,
          0.000013, 0.000012341234, 0.0000000242424);
  ck_assert_str_eq(s21_buffer5, buffer5);
}
END_TEST

START_TEST(s21_sprintf_test3) {
  char s21_buffer6[256] = {0};
  char buffer6[256] = {0};
  s21_sprintf(s21_buffer6, "%x %X %u %o %p", 412325, (unsigned int)12785231,
              4841292, 91912838, "qewqweqwe");
  sprintf(buffer6, "%x %X %u %o %p", 412325, 12785231, (unsigned int)4841292,
          91912838, "qewqweqwe");
  ck_assert_str_eq(s21_buffer6, buffer6);
}
END_TEST
START_TEST(s21_sprintf_test4) {
  char s21_buffer7[256] = {0};
  char buffer7[256] = {0};
  s21_sprintf(s21_buffer7, "|%100.23d| <%ld>", 1313999123, 848484848442313);
  sprintf(buffer7, "|%100.23d| <%ld>", 1313999123, 848484848442313);
  ck_assert_str_eq(s21_buffer7, buffer7);
}
END_TEST
START_TEST(s21_sprintf_test5) {
  char s21_buffer8[256] = {0};
  char buffer8[256] = {0};
  sprintf(s21_buffer8, "%2lo", (unsigned long)1234567);
  s21_sprintf(buffer8, "%2lo", (unsigned long)1234567);
  ck_assert_str_eq(s21_buffer8, buffer8);

  sprintf(s21_buffer8, "%2lu", (unsigned long)45);
  s21_sprintf(buffer8, "%2lu", (unsigned long)45);
  ck_assert_str_eq(s21_buffer8, buffer8);

  s21_sprintf(s21_buffer8, "%*d", 10, 10);
  sprintf(buffer8, "%*d", 10, 10);
  ck_assert_str_eq(s21_buffer8, buffer8);

  s21_sprintf(s21_buffer8, "%*.*d", 10, 5, 13);
  sprintf(buffer8, "%*.*d", 10, 5, 13);
  ck_assert_str_eq(s21_buffer8, buffer8);
}
END_TEST

START_TEST(s21_sprintf_test6) {
  char str1[256];
  char str2[256];
  int r1 = sprintf(str1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  int r2 = s21_sprintf(str2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test7) {
  char str1[1000];
  char str2[1000];
  char s[10] = {'h', 'e', 'l', 'l', 'o'};
  int r1 = sprintf(str1, "%ls%10ls%.0ls%7.2ls%-10.3ls %5.3s%-5.0s%s%s%6.33s",
                   L"alana", L"helloworld", L"ALANA", L"VIOLETA", L"ALEX",
                   "SCHOOL21", "LEO", "STRING", s, s);
  int r2 =
      s21_sprintf(str2, "%ls%10ls%.0ls%7.2ls%-10.3ls %5.3s%-5.0s%s%s%6.33s",
                  L"alana", L"helloworld", L"ALANA", L"VIOLETA", L"ALEX",
                  "SCHOOL21", "LEO", "STRING", s, s);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test8) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 115;
  unsigned long l = 123325242342l;
  int r1 =
      sprintf(str1, "%u%15u%-20u%10u%-15.10u!%.u%.10u%-20.12lu%19hu",
              (unsigned int)4321u, (unsigned int)-34567, (unsigned int)2342u,
              (unsigned int)12346u, (unsigned int)234542u, (unsigned int)2345u,
              (unsigned int)2432u, l, h);
  int r2 = s21_sprintf(str2, "%u%15u%-20u%10u%-15.10u!%.u%.10u%-20.12lu%19hu",
                       (unsigned int)4321u, (unsigned int)-34567,
                       (unsigned int)2342u, (unsigned int)12346u,
                       (unsigned int)234542u, (unsigned int)2345u,
                       (unsigned int)2432u, l, h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test9) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "|%5.0f|\n", -320.3);
  sprintf(data1, "|%5.0f|\n", -320.3);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test10) {
  char c1[100] = "b";
  char c2[100] = "b";
  char c3[100] = "HelloWorld";
  char c4[100] = "HelloWorld";
  ck_assert_int_eq(sprintf(c1, "test %d%d%d", 5, 6, 10),
                   s21_sprintf(c2, "test %d%d%d", 5, 6, 10));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c3 + 6, "%d", -6000),
                   s21_sprintf(c4 + 6, "%d", -6000));
  ck_assert_str_eq(c3, c4);

  ck_assert_int_eq(sprintf(c1, "%10d %-10d %4.10d", 1, 666, 2544325),
                   s21_sprintf(c2, "%10d %-10d %4.10d", 1, 666, 2544325));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c1, "%+4.10d", 1), s21_sprintf(c2, "%+4.10d", 1));
  ck_assert_str_eq(c1, c2);
  ck_assert_int_eq(sprintf(c1, "%+20.10d", 1), s21_sprintf(c2, "%+20.10d", 1));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c1, "%-20.10d", 1), s21_sprintf(c2, "%-20.10d", 1));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c1, "%+-20.10d", 1),
                   s21_sprintf(c2, "%+-20.10d", 1));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c1, "%-+10d", 666), s21_sprintf(c2, "%-+10d", 666));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c1, "%% % d", 1), s21_sprintf(c2, "%% % d", 1));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c1, "%10d", -2147483647),
                   s21_sprintf(c2, "%10d", -2147483647));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c1, "%10ld", -21474836488),
                   s21_sprintf(c2, "%10ld", -21474836488));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c1, "%10hd", (short)55643),
                   s21_sprintf(c2, "%10hd", (short)55643));
  ck_assert_str_eq(c1, c2);
}
END_TEST

START_TEST(s21_sprintf_test11) {
  char c1[100] = "b";
  char c2[100] = "b";
  char c3[100] = "HelloWorld";
  char c4[100] = "HelloWorld";
  ck_assert_int_eq(sprintf(c1, "test %f %f %f", 5.1, 0.1, -0.00001),
                   s21_sprintf(c2, "test %f %f %f", 5.1, 0.1, -0.00001));
  ck_assert_str_eq(c1, c2);

  ck_assert_int_eq(sprintf(c3 + 6, "%f", -6000.00006),
                   s21_sprintf(c4 + 6, "%f", -6000.00006));
  ck_assert_str_eq(c3, c4);

  ck_assert_int_eq(sprintf(c3, "%fHelloWorld%f", -6000.00006, -1.0),
                   s21_sprintf(c4, "%fHelloWorld%f", -6000.00006, -1.0));
  ck_assert_str_eq(c3, c4);

  ck_assert_int_eq(sprintf(c3, "%.0f", 99.99), s21_sprintf(c4, "%.0f", 99.99));
  ck_assert_str_eq(c3, c4);
}
END_TEST

START_TEST(s21_sprintf_test12) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "01)SPRINTF : |%5c|\n", '$');
  sprintf(data1, "01)SPRINTF : |%5c|\n", '$');
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test13) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "01)SPRINTF : |%-s|\n", "test");
  sprintf(data1, "01)SPRINTF : |%-s|\n", "test");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test14) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "01)SPRINTF : |%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu",
              "12345", "hu");
  sprintf(data1, "01)SPRINTF : |%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu",
          "12345", "hu");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test15) {
  char str[100];
  char str1[100];
  sprintf(str,
          "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And "
          "now unsigned: |%u|\n",
          "abra", 'e', 56, (unsigned)-43);
  s21_sprintf(str1,
              "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. "
              "And now unsigned: |%u|\n",
              "abra", 'e', 56, (unsigned)-43);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test16) {
  char str[100];
  char str1[100];
  sprintf(str, " %+d %+i %+d %+d", 2147483647, -2147483647, 21, 0);
  s21_sprintf(str1, " %+d %+i %+d %+d", 2147483647, -2147483647, 21, 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test17) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%s";
  char s[] = "A\nB\tO\vB\rA\0C";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(s21_sprintf_test18) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "% u";
  unsigned int u = 5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(s21_sprintf_test19) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%c";
  char c = 'c';
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(s21_sprintf_test20) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+5i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(s21_sprintf_test21) {
  char str1[256];
  char str2[256];

  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, "%#o", val), sprintf(str2, "%#o", val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test22) {
  char str1[256];
  char str2[256];
  char *format = "%.16Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);

  char *format2 = "%.0Le";
  val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format2, val),
                   sprintf(str2, format2, val));
  ck_assert_str_eq(str1, str2);

  char *format3 = "%.15Le";
  val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format3, val),
                   sprintf(str2, format3, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test23) {
  char str1[256];
  char str2[256];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test24) {
  char str1[256];
  char str2[256];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test26) {
  char str1[256];
  char str2[256];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test27) {
  char str1[256];
  char str2[256];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test28) {
  char str1[256];
  char str2[256];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test29) {
  char str1[256];
  char str2[256];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test30) {
  char str1[256];
  char str2[256];
  char format[] = "%#e hello %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test31) {
  char str1[256];
  char str2[256];
  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test32) {
  char str1[256];
  char str2[256];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);

  char *format2 = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format2, format),
                   sprintf(str2, format2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test33) {
  char str1[256];
  char str2[256];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);

  char format2[] = "%.g";
  hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format2, hex),
                   sprintf(str2, format2, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test35) {
  char str1[256];
  char str2[256];
  char format[] = "%f";
  ck_assert_int_eq(s21_sprintf(str1, format, NAN), sprintf(str2, format, NAN));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test36) {
  char str1[256];
  char str2[256];
  char format[] = "%f";
  ck_assert_int_eq(s21_sprintf(str1, format, INFINITY),
                   sprintf(str2, format, INFINITY));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprinf_func_test(void) {
  Suite *s2;
  TCase *tc3;
  s2 = suite_create("s21_string_sprintf");
  tc3 = tcase_create("test_sprintf");
  tcase_add_test(tc3, s21_sprintf_test);
  tcase_add_test(tc3, s21_sprintf_test2);
  tcase_add_test(tc3, s21_sprintf_test3);
  tcase_add_test(tc3, s21_sprintf_test4);
  tcase_add_test(tc3, s21_sprintf_test5);
  tcase_add_test(tc3, s21_sprintf_test6);
  tcase_add_test(tc3, s21_sprintf_test7);
  tcase_add_test(tc3, s21_sprintf_test8);
  tcase_add_test(tc3, s21_sprintf_test9);
  tcase_add_test(tc3, s21_sprintf_test10);
  tcase_add_test(tc3, s21_sprintf_test11);
  tcase_add_test(tc3, s21_sprintf_test12);
  tcase_add_test(tc3, s21_sprintf_test13);
  tcase_add_test(tc3, s21_sprintf_test14);
  tcase_add_test(tc3, s21_sprintf_test15);
  tcase_add_test(tc3, s21_sprintf_test16);
  tcase_add_test(tc3, s21_sprintf_test17);
  tcase_add_test(tc3, s21_sprintf_test18);
  tcase_add_test(tc3, s21_sprintf_test19);
  tcase_add_test(tc3, s21_sprintf_test20);
  tcase_add_test(tc3, s21_sprintf_test21);
  tcase_add_test(tc3, s21_sprintf_test22);
  tcase_add_test(tc3, s21_sprintf_test23);
  tcase_add_test(tc3, s21_sprintf_test24);
  tcase_add_test(tc3, s21_sprintf_test26);
  tcase_add_test(tc3, s21_sprintf_test27);
  tcase_add_test(tc3, s21_sprintf_test28);
  tcase_add_test(tc3, s21_sprintf_test29);
  tcase_add_test(tc3, s21_sprintf_test30);
  tcase_add_test(tc3, s21_sprintf_test31);
  tcase_add_test(tc3, s21_sprintf_test32);
  tcase_add_test(tc3, s21_sprintf_test33);
  tcase_add_test(tc3, s21_sprintf_test35);
  tcase_add_test(tc3, s21_sprintf_test36);
  suite_add_tcase(s2, tc3);
  return s2;
}