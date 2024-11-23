/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:01:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/15 15:01:59 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

/*
It it fails, it continues to free everything
*/
static void	ft_chainshift(char **dest, char **src)
{
	int	i;
	int	fail;

	if (!dest || !src)
		return ;
	i = -1;
	fail = 0;
	while (src[++i])
	{
		dest[i] = NULL;
		if (!fail)
			dest[i] = gnlxio_ft_strdup(src[i]);
		if (!dest[i])
			fail = 1;
		free(src[i]);
		src[i] = NULL;
	}
	free(src);
	src = NULL;
}

static void	ft_realloc(char ***chain, int nmemb)
{
	int		i;
	int		len;
	char	**temp;

	if (!chain || !(*chain) || nmemb < 0)
		return ;
	i = -1;
	while ((*chain)[++i])
		;
	len = i;
	temp = gnlxio_ft_calloc(len + 1, sizeof(char *));
	if (!temp)
		return ;
	ft_chainshift(temp, *chain);
	*chain = gnlxio_ft_calloc(len + nmemb + 1, sizeof(char *));
	if (!(*chain))
	{
		ft_free_rlines(&temp);
		return ;
	}
	ft_chainshift(*chain, temp);
}

char	**ft_readlines(int fd)
{
	char	**lines;
	char	*line;
	int		i;

	lines = gnlxio_ft_calloc(2, sizeof(char *));
	if (!lines)
		return (NULL);
	line = get_next_line(fd);
	i = -1;
	while (line)
	{
		lines[++i] = gnlxio_ft_strdup(line);
		ft_realloc(&lines, 1);
		if (!lines)
		{
			ft_free_rlines(&lines);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (lines);
}
