#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		if (f)
			f(lst->content);
		lst = lst->next;
	}
}
