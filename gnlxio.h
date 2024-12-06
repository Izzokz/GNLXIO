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
# include "t_ints.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef A_TRUNC
#  define A_TRUNC 2147483648
# endif

# ifndef A_BEGIN
#  define A_BEGIN 1
# endif

# ifndef A_END
#  define A_END -1
# endif

typedef char**	t_rlines;

void		ft_fix_lineno(int *lineno, int len);
void		gnlxio_ft_putstr_fd(char *s, int fd);
int			gnlxio_ft_strcmp(char *string1, char *string2);
char		*gnlxio_ft_strnstr(const char *big, const char *little, size_t len);
size_t		gnlxio_ft_strlen(const char *s);
char		*gnlxio_ft_strdup(const char *src);
void		*gnlxio_ft_calloc(size_t nmemb, size_t size);
char		*gnlxio_ft_strjoinfree(char **s1, char **s2);
t_rlines	ft_rlines_dup(t_rlines rlines);
void		ft_realloc_rlines(t_rlines *rlines, int nmemb);
int			ft_rlines_len(t_rlines rlines);
int			ft_rlines_size(t_rlines rlines);
int			ft_file_len(const char *filename);
int			ft_file_size(const char *filename);
int			zombie_rlines(t_rlines rlines);
int			invalid_rlines(t_rlines rlines);
int			zombie_rlines_free(t_rlines *rlines);
int			invalid_rlines_free(t_rlines *rlines);
void		ft_rline_cutendl(char **rline);
void		ft_rlines_cutendl(t_rlines *rlines);
char		*get_next_line(int fd);
t_rlines	ft_readlines(int fd);
t_rlines	ft_readfile(const char *filename);
void		ft_free_rlines(t_rlines *rlines);
int			ft_rewrite_file(const char *filename, t_rlines lines);
int			ft_deline(const char *filename, int lineno);
char		*ft_get_line(const char *filename, int lineno);
int			ft_replace_rlines(t_rlines *rlines, char *from, char *to);
int			ft_replace_file(const char *filename, char *from, char *to);
int			ft_gen_file(char *filename, char *perm);
int			ft_trunc(char *filename);
int			ft_add_line(char *filename, char *line, long long method);
char		*ft_input(void);

#endif
