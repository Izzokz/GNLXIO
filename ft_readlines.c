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

#include "gnlxio.h"

static char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		index;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (dest);
	dest[len] = '\0';
	index = 0;
	while (index < len)
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}

static void	ft_chainshift(char **dest, char **src)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		dest[i] = ft_strdup(src[i]);
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
	temp = ft_calloc(len + 1, sizeof(char *));
	if (!temp)
		return ;
	ft_chainshift(temp, *chain);
	*chain = ft_calloc(len + nmemb + 1, sizeof(char *));
	if (!(*chain))
		return ;
	ft_chainshift(*chain, temp);
}

char	**ft_readlines(int fd)
{
	char	**lines;
	char	*line;
	int		i;

	lines = ft_calloc(2, sizeof(char *));
	line = get_next_line(fd);
	i = -1;
	while (line)
	{
		lines[++i] = ft_strdup(line);
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
