/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlxio.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:05:38 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/15 14:23:45 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNLXIO_H
# define GNLXIO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	gnlxio_ft_strlen(const char *s);
char	*gnlxio_ft_strdup(const char *src);
void	*gnlxio_ft_calloc(size_t nmemb, size_t size);
char	*gnlxio_ft_strjoinfree(char **s1, char **s2);
char	*get_next_line(int fd);
char	**ft_readlines(int fd);
void	ft_free_rlines(char ***lines);
int		ft_rewrite_file(char *filename, char **lines);
int		ft_deline(char *filename, int lineno);

#endif
