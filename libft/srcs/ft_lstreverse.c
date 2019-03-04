#include "../includes/libft.h"

void ft_lstrev(t_list **alst)
{
  t_list *previous;
  t_list *current;
  t_list *next;

  prev = NULL;
  current = *alst;
  while (current != NULL)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  *alst = previous;
}
