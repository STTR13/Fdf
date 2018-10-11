//#include "libft.h"
#include <stdio.h>

void test(unsigned int i, char *c)
{
  //printf("%i\n", i)
  printf("%i %s\n", i, c);
}

void  ft_striteri(char *s, void(*f)(unsigned int, char *))
{
  int i;

  i = 0;
  while (s[i] != '\0' && s != NULL)
    {
      f(i, s);
      i++;
    }
}






int main(void)
{
  char *str;
  str = "dit is een test";
  ft_striteri(str, &test);
  return (0);
}
