#include "libft.h"
#include <stdio.h>

static void isneg(int *n, int *negative, int *length)
{
  if (*n < 0)
  {
    *n *= -1;
    *negative = 1;
    *length = 2;
  }
  else
  {
    *negative = 0;
    *length = 1;
  }
}


char  *ft_itoa(int n)
{
  int nb;
  int length;
  int negative;
  char *temp;

  if (n == -2147483648)
    return ("-2147483648");
  isneg(&n, &negative, &length);
  nb = n;
  while (nb /= 10)
    length++;
  if ((temp = ft_strnew(length)) == NULL)
    return (NULL);
    temp[length] = '\0';
  while (length--)
  {
    temp[length] = n % 10 + '0';
    n = n / 10;
  }
  if (negative == 1)
    temp[0] = '-';
  return (temp);
}

int main(void)
{
  int i;

  i = -564641;
  printf("%s", ft_itoa(i));
  return (0);
}
