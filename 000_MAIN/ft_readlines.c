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

static void	ft_chainshift(char **dest, char **src)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		dest[i] = gnlxio_ft_strdup(src[i]);
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
		return ;
	ft_chainshift(*chain, temp);
}

char	**ft_readlines(int fd)
{
	char	**lines;
	char	*line;
	int		i;

	lines = gnlxio_ft_calloc(2, sizeof(char *));
	line = get_next_line(fd);
	i = -1;
	while (line)
	{
		lines[++i] = gnlxio_ft_strdup(line);
		ft_realloc(&lines, 1);
		if (!lines)
			return (NULL);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	return (lines);
}
