/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:33:16 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/06/14 16:46:29 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		ft_strclen(char *s, char c);
char	*ft_sub_before_chr(const char *s, char c);
char	*ft_sub_after_chr(const char *s, char c);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_strcpy(char **src, char **dest);
char	*read_next_line(char **old_line, int fd);
char	*create_line(char **next_line, char **line, char **t_line, int fd);
char	*get_next_line(int fd);

#endif
