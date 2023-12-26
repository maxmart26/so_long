/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:54:12 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/07 08:23:05 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_new(char *ptr);
char	*ft_static(char *ptr);
char	*ft_strjoin(char *stockage, char *buffer);
size_t	ft_strlen(char *str);
char	*ft_strjoin_suite(char *stockage, char *buffer, char *str);
char	*ft_cut(char *stockage);

#endif
