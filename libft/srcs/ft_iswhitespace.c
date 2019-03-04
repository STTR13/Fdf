
#include "../includes/libft.h"

int		ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
			|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}
