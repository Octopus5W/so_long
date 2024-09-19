/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:15:01 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/19 15:26:18 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_dup_tab(char **tab, int size)
{
	char	**new_tab;
	int		i;

	i = -1;
	new_tab = malloc(sizeof(char *) * (size + 1));
	if (!new_tab)
		return (NULL);
	while (++i < size)
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (!new_tab[i])
			return (ft_free(new_tab, i), NULL);
	}
	new_tab[i] = NULL;
	return (new_tab);
}
