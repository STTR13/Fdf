#include "libft.h"
#include <stdio.h>
char test(char c){return('a');}
char  *ft_strmap(char const *s, char (*f)(char))
{
  int i;
  int j;
  char *str;

  i = 0;
  j = ft_strlen((char *)s);
  str = ft_strnew(j);
  if (s && f)
  {
  while (s[i] != '\0')
  {
    str[i] = f(s[i]);
    i++;
  }
  return (str);
  }
  return (NULL);
}

int main(void)
{
  char *str = "dit is een test", *str2;

  str2 = ft_strmap(str, &test);
  printf("%s\n", str);
  printf("%s", str2);
  return (0);
}
