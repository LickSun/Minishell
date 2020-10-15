#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			count;
	unsigned char	*stroke_dst;
	unsigned char	*stroke_src;

	stroke_dst = (unsigned char *)dst;
	stroke_src = (unsigned char *)src;
	count = 0;
	if (src == dst)
		return (stroke_dst);
	if (stroke_dst > stroke_src)
	{
		while (len-- > 0)
			stroke_dst[len] = stroke_src[len];
	}
	else
	{
		while (count < len)
		{
			stroke_dst[count] = stroke_src[count];
			count++;
		}
	}
	return (stroke_dst);
}
