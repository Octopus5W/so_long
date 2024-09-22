/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:32:44 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/06/14 16:32:58 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strclen(char *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] && s[count] != c)
		count++;
	if (s[count] == c)
		return (count);
	else
		return (-1);
}

char	*ft_strjoin(char **s1, char **s2)
{
	char	*join;
	size_t	count;

	count = 0;
	if (s1)
		count += ft_strclen(*s1, '\0');
	if (s2)
		count += ft_strclen(*s2, '\0');
	if (count)
		join = malloc(sizeof(char) * (count + 1));
	else
		return (NULL);
	if (!join)
		return (NULL);
	join[count] = '\0';
	if (s1 && *s1)
		join = ft_strcpy(s1, &join);
	if (s2 && *s2)
		join = ft_strcpy(s2, &join);
	return (join - count);
}

char	*ft_strcpy(char **src, char **dest)
{
	size_t	i;

	i = 0;
	if (!src || !(*src))
		return (NULL);
	while ((*src)[i])
	{
		(*dest)[i] = (*src)[i];
		i++;
	}
	(*dest)[i] = '\0';
	free(*src);
	*src = NULL;
	return (*dest + i);
}

char	*ft_sub_before_chr(const char *s, char c)
{
	char	*r_s;
	int		i;

	r_s = NULL;
	if (s)
	{
		i = 0;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == c)
		{
			r_s = malloc(sizeof(char) * (++i + 1));
			if (!r_s)
				return (NULL);
			r_s[i] = '\0';
			while (--i >= 0)
				r_s[i] = s[i];
		}
	}
	return (r_s);
}

char	*ft_sub_after_chr(const char *s, char c)
{
	char	*r_s;
	int		i;

	r_s = NULL;
	if (s)
	{
		while (*s != c && s && *s)
			s++;
		if (*s == c && *(s + 1) != '\0')
		{
			s++;
			i = 0;
			while (s[i++])
				;
			r_s = malloc(sizeof(char) * (i + 1));
			if (!r_s)
				return (NULL);
			r_s[i] = '\0';
			while (--i >= 0)
				r_s[i] = s[i];
		}
	}
	return (r_s);
}
