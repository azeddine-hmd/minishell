#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (!(memory = malloc(size * count)))
		return (NULL);
	ft_bzero(memory, size * count);
	return (memory);
}
