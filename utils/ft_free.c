#include <stdlib.h>

void ft_free(char **tab, int size)
{
	while (--size >= 0)
		free(tab[size]);
	free(tab);
}