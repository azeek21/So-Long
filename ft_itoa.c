#include "so_long.h"

int abs(int n)
{
 if (n < 0)
  return (n * -1);
 return (n);
}

int num_len(int n)
{
 int len;

 len = 0;
 if (n <= 0)
  len++;
 while (n != 0)
 {
  len++;
  n = n / 10;
 }
 return (len);
}

char *ft_itoa(int n)
{
 char *s;
 int  len;

 len = num_len(n);
 s = (char *)malloc(sizeof(char) * (len + 1));
 if (!s)
  return ((void *)0);
 s[len] = '\0';
 if (n < 0)
  s[0] = '-';
 else if (n == 0)
  s[0] = '0';
 while (n != 0)
 {
  len--;
  s[len] = abs(n % 10) + '0';
  n = n / 10;
 }
 return (s);
}