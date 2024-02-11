#include "test_string.h"

START_TEST(s21_scanf_test1) {
  char buff[50] = "F 69 123.45";
  char c, a;
  int n, b;
  float d, t;
  s21_sscanf(buff, "%c %d %f", &c, &n, &d);
  sscanf(buff, "%c %d %f", &a, &b, &t);
  ck_assert_int_eq(n, b);
  ck_assert_int_eq((int)c, (int)a);
  ck_assert_float_eq(d, t);
}
END_TEST

START_TEST(s21_scanf_test2) {
  char str[80] = "";
  char str2[80] = "";
  int i = 0, a = 0;
  s21_sscanf("hello 1 2 3 4 5", "%s%d", str, &i);
  sscanf("hello 1 2 3 4 5", "%16s%d", str2, &a);
  ck_assert_int_eq(i, a);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_scanf_test3) {
  char tokenstring[] = "15 12 14...";
  char s[81] = "";
  char s_21[81] = "";
  char c, a;
  int i, p;
  float fp, pf;
  sscanf(tokenstring, "%80s %c %d %f", s, &c, &i, &fp);
  s21_sscanf(tokenstring, "%80s %c %d %f", s_21, &a, &p, &pf);
  ck_assert_int_eq(i, p);
  ck_assert_float_eq(fp, pf);
  ck_assert_int_eq((int)c, (int)a);
  ck_assert_str_eq(s, s_21);
}
END_TEST

START_TEST(s21_scanf_test4) {
  char string[] = "25 54.32 Thompson 56789 0123 56ß水";
  int i, j, a, b;
  float x, y, u, o;
  char str1[10] = "", str2[10] = "";
  sscanf(string, "%d%f%9s%2d%f%*d", &i, &x, str1, &j, &y);
  s21_sscanf(string, "%d%f%9s%2d%f%*d", &a, &u, str2, &b, &o);
  ck_assert_int_eq(i, a);
  ck_assert_int_eq(j, b);
  ck_assert_float_eq(x, u);
  ck_assert_float_eq(y, o);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_scanf_test5) {
  char s[] = "3 red balls 2 blue balls";
  char str1[10] = "", str2[10] = "", str3[10] = "", str4[10] = "";
  sscanf(s, "%*s %*s %*s %9s %9s", str1, str2);
  s21_sscanf(s, "%*s %*s %*s %s %s", str3, str4);
  ck_assert_str_eq(str1, str3);
  ck_assert_str_eq(str2, str4);
}
END_TEST

START_TEST(s21_scanf_test6) {
  int a, a1;
  short b, b1;
  long c, c1, d, d1, e, e1;
  a = b = c = d = 1;
  a1 = b1 = c1 = d1 = 1;
  const char str[] = "-12345 -000456000 111 +0005 666 777";
  ck_assert_int_eq(
      sscanf(str, "%3d %hd %ld %*d %ld %2ld", &a, &b, &c, &d, &e),
      s21_sscanf(str, "%3d %hd %ld %*d %ld %2ld", &a1, &b1, &c1, &d1, &e1));
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(e, e1);
}
END_TEST

START_TEST(s21_scanf_test7) {
  unsigned int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "1778 012 0x1111 -10 aaa";
  int r1 = sscanf(str, "%x%x%x%x", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%x%x%x%x", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_scanf_test8) {
  int integer = 5;
  int *p1a = &integer;
  int *p2a;
  int *p3a;
  char temp[50] = {'\0'};
  sprintf(temp, "%p", p1a);
  sscanf(temp, "%p", &p2a);
  s21_sscanf(temp, "%p", &p3a);
  ck_assert_ptr_eq(p2a, p3a);
}
END_TEST

START_TEST(s21_scanf_test9) {
  unsigned int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "1775 012 0 -10 aaa";
  int r1 = sscanf(str, "%o%o%o%o", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%o%o%o%o", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  unsigned int a = 0;
  unsigned int b = 0;
  int result1 = s21_sscanf("12345", "%o", &a);
  int result_origin1 = sscanf("12345", "%o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_scanf_test10) {
  unsigned int a1, b1, a2, b2;
  unsigned short c1, c2;
  unsigned long d1, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "0 0002 -1 -1234 666 aaa";
  int r1 = sscanf(str, "%*u%u%u%hu%lu", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%*u%u%u%hu%lu", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_scanf_test11) {
  int d1 = 0, d2 = 0, i1 = 0, i2 = 0;
  float e1 = 0, e2 = 0, E1 = 0, E2 = 0, f1 = 0, f2 = 0, g1 = 0, g2 = 0, G1 = 0,
        G2 = 0;
  sscanf("4 123 hello 1234 4321 13.37 2.28 1337.228", "%i%d%e%E%f%g%G", &i1,
         &d1, &e1, &E1, &f1, &g1, &G1);
  s21_sscanf("4 123 hello 1234 4321 13.37 2.28 1337.228", "%i%d%e%E%f%g%G", &i2,
             &d2, &e2, &E2, &f2, &g2, &G2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
}
END_TEST

START_TEST(s21_scanf_test12) {
  char a[40] = {'\0'}, d[40] = {'\0'};
  wchar_t b[40] = {'\0'};
  char a2[40] = {'\0'}, d2[40] = {'\0'};
  wchar_t b2[40] = {'\0'};
  char c, c2;
  const char str[] = "Good string test hello world";
  sscanf(str, "%39s %39ls %3c %*s %39s", a, b, &c, d),
      s21_sscanf(str, "%s %ls %3c %*s %s", a2, b2, &c2, d2);
  ck_assert_str_eq(a, a2);
  ck_assert_int_eq((int)c, (int)c2);
  ck_assert_str_eq(d, d2);
}
END_TEST

START_TEST(s21_scanf_test13) {
  unsigned int a = 0;
  unsigned int b = 0;

  unsigned int c = 0;
  unsigned int d = 0;

  int result1 = s21_sscanf("1E240 12D687", "%x %X", &a, &b);
  int result_origin1 = sscanf("1E240 12D687", "%x %X", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  a = 0;
  b = 0;

  result1 = s21_sscanf("1E240", "%x", &a);
  result_origin1 = sscanf("1E240", "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;

  result1 = s21_sscanf("1E240", "%X", &a);
  result_origin1 = sscanf("1E240", "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;

  result1 = s21_sscanf("-12D687", "%X", &a);
  result_origin1 = sscanf("-12D687", "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("-12D687", "%x", &a);
  result_origin1 = sscanf("-12D687", "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("3039", "%x", &a);
  result_origin1 = sscanf("3039", "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("3039", "%X", &a);
  result_origin1 = sscanf("3039", "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;
  const char *for_str = "-929";

  result1 = s21_sscanf(for_str, "%X", &a);
  result_origin1 = sscanf(for_str, "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(s21_scanf_test14) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
START_TEST(s21_scanf_test15) {
  char buff[50] = "o -6945 123.45";
  char c, a;
  int n, b;
  int v, k;
  float d, t;
  s21_sscanf(buff, "%c %d %f %n", &c, &n, &d, &v);
  sscanf(buff, "%c %d %f %n", &a, &b, &t, &k);
  ck_assert_int_eq(n, b);
  ck_assert_int_eq(v, k);
  ck_assert_int_eq((int)c, (int)a);
  ck_assert_float_eq(d, t);
}
END_TEST

START_TEST(s21_scanf_test17) {
  char a16[256] = {0};
  char aa16[256] = {0};
  int a = 12345;
  int b = 1234;
  const char *format_str16 = " *one, %% %+d %% %+d";
  int result1 = s21_sprintf(a16, format_str16, a, b);
  int result_origin1 = sprintf(aa16, format_str16, a, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a16, aa16);
}
END_TEST
START_TEST(s21_scanf_test18) {
  int a1, b1, c1, d1, e1, a2, b2, c2, d2, e2;
  a1 = a2 = b1 = b2 = c1 = e1 = c2 = d1 = d2 = e2 = 0;
  const char str[] = "12 12 011432 0x345 78";
  const char fstr[] = "%d %d %i %i %i";
  s21_sscanf(str, fstr, &a1, &b1, &c1, &d1, &e1);
  sscanf(str, fstr, &a2, &b2, &c2, &d2, &e2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(s21_scanf_test19) {
  const char str[] = "1.234";
  const char fstr[] = "%Lf";
  long double a = 0, a2 = 0;
  s21_sscanf(str, fstr, &a);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a, a2);
}
END_TEST

START_TEST(s21_scanf_test20) {
  const char str[] = "1.234";
  const char fstr[] = "%lf";
  double a = 0, a2 = 0;
  s21_sscanf(str, fstr, &a);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a, a2);
}
END_TEST

START_TEST(s21_scanf_test21) {
  const char str[] = "55 55 555 555 5";
  const char fstr[] = "%*3d %d %2d %6d ";
  int a = 0, a2 = 0;
  int b = 0, b2 = 0;
  int c = 0, c2 = 0;
  s21_sscanf(str, fstr, &a, &b, &c);
  sscanf(str, fstr, &a2, &b2, &c2);
  ck_assert_int_eq(a, a2);
  ck_assert_int_eq(b, b2);
  ck_assert_int_eq(c, c2);
}
END_TEST

START_TEST(s21_scanf_test22) {
  const char str[] = "55555555555";
  const char fstr[] = "%ld";
  long int a = 0, a2 = 0;
  s21_sscanf(str, fstr, &a);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a, a2);
}
END_TEST

START_TEST(s21_scanf_test23) {
  const char str[] = "55.23 55.000 555.134321455415 555 5";
  const char fstr[] = "%*3f %f %2e %6g ";
  float a = 0, a2 = 0;
  float b = 0, b2 = 0;
  float c = 0, c2 = 0;
  s21_sscanf(str, fstr, &a, &b, &c);
  sscanf(str, fstr, &a2, &b2, &c2);
  ck_assert_int_eq(a, a2);
  ck_assert_int_eq(b, b2);
  ck_assert_int_eq(c, c2);
}
END_TEST

START_TEST(s21_scanf_test24) {
  const char str[] = "57234";
  const char fstr[] = "%lo";
  unsigned long int a = 0, a2 = 0;
  s21_sscanf(str, fstr, &a);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a, a2);
}
END_TEST

START_TEST(s21_scanf_test25) {
  const char str[] = "57234";
  const char fstr[] = "%ho";
  unsigned short int a = 0, a2 = 0;
  s21_sscanf(str, fstr, &a);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a, a2);
}
END_TEST

START_TEST(s21_scanf_test26) {
  const char str[] = "0x123";
  const char fstr[] = "%2lx";
  unsigned long int a = 0, a2 = 0;
  s21_sscanf(str, fstr, &a);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a, a2);
}
END_TEST

START_TEST(s21_scanf_test27) {
  const char str[] = "0x123";
  const char fstr[] = "%hx";
  unsigned short int a = 0, a2 = 0;
  s21_sscanf(str, fstr, &a);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a, a2);
}
END_TEST

Suite *scanf_func_test(void) {
  Suite *s3;
  TCase *tc4;
  s3 = suite_create("s21_string_scanf");
  tc4 = tcase_create("test_scanf");
  tcase_add_test(tc4, s21_scanf_test1);
  tcase_add_test(tc4, s21_scanf_test2);
  tcase_add_test(tc4, s21_scanf_test3);
  tcase_add_test(tc4, s21_scanf_test4);
  tcase_add_test(tc4, s21_scanf_test5);
  tcase_add_test(tc4, s21_scanf_test6);
  tcase_add_test(tc4, s21_scanf_test7);
  tcase_add_test(tc4, s21_scanf_test8);
  tcase_add_test(tc4, s21_scanf_test9);
  tcase_add_test(tc4, s21_scanf_test10);
  tcase_add_test(tc4, s21_scanf_test11);
  tcase_add_test(tc4, s21_scanf_test12);
  tcase_add_test(tc4, s21_scanf_test13);
  tcase_add_test(tc4, s21_scanf_test14);
  tcase_add_test(tc4, s21_scanf_test15);
  tcase_add_test(tc4, s21_scanf_test17);
  tcase_add_test(tc4, s21_scanf_test18);
  tcase_add_test(tc4, s21_scanf_test19);
  tcase_add_test(tc4, s21_scanf_test20);
  tcase_add_test(tc4, s21_scanf_test21);
  tcase_add_test(tc4, s21_scanf_test22);
  tcase_add_test(tc4, s21_scanf_test23);
  tcase_add_test(tc4, s21_scanf_test24);
  tcase_add_test(tc4, s21_scanf_test25);
  tcase_add_test(tc4, s21_scanf_test26);
  tcase_add_test(tc4, s21_scanf_test27);
  suite_add_tcase(s3, tc4);
  return s3;
}
