#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)xmalloc(sizeof(t_list));
	list->content = content;
	list->next = NULL;
	return (list);
}
