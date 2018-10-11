//#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void test(char *c)
{
  printf("%s\n", c);
}

void  ft_striter(char *s, void (*f)(char *))
{
  while (*s != '\0' && s != NULL)
    f(s++);
}

int main(void)
{
  char *str;
  str = "dit is een test";
  ft_striter(str, &test);
  return (0);
}
