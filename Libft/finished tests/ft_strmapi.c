#include "libft.h"
#include <stdio.h>
char test(unsigned int i, char c)
{
  return (c + i);
}
char  *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  int i;
  int j;
  char *str;

  i = 0;
  j = ft_strlen(s);
  str = ft_strnew(j);
  if (s && f)
  {
    while (s[i] != '\0')
    {
      str[i] = f(i, s[i]);
      i++;
    }
    return (str);
  }
  return (NULL);
}

int main(void)
{
  char *str = "abc", *str2;

  str2 = ft_strmapi(str, &test);
  printf("%s\n%s", str, str2);
  return (0);
}
