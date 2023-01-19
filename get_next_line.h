/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimaozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:08:03 by msimaozi          #+#    #+#             */
/*   Updated: 2022/11/29 16:08:05 by msimaozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_readsave(int fd, char *save);
char	*ft_getline(char *save);
char	*ft_save(char *save);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str);

#endif
