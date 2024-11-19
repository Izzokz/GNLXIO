/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:46:36 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/19 11:46:37 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

int	ft_rlines_size(char **rlines)
{
	int	i;
	int	j;
	int	len;

	if (!rlines)
		return (0);
	len = 0;
	i = -1;
	while (rlines[++i])
	{
		j = -1;
		while (rlines[i][++j])
			len++;
	}
	return (len);
}

int	ft_rlines_len(char **rlines)
{
	int	i;

	if (!rlines)
		return (0);
	i = -1;
	while (rlines[++i])
		;
	return (i);
}

int	ft_file_len(const char *filename)
{
	char	**lines;
	int		fd;
	int		len;

	fd = open(filename, O_RDONLY);
	lines = ft_readlines(fd);
	close(fd);
	len = ft_rlines_len(lines);
	ft_free_rlines(&lines);
	return (len);
}

int	ft_file_size(const char *filename)
{
	char	**lines;
	int		fd;
	int		size;

	fd = open(filename, O_RDONLY);
	lines = ft_readlines(fd);
	close(fd);
	size = ft_rlines_size(lines);
	ft_free_rlines(&lines);
	return (size);
}
