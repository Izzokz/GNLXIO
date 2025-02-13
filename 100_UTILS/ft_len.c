/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:46:36 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/21 13:42:04 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

int	ft_rlines_size(t_rlines rlines)
{
	int	i;
	int	j;
	int	len;

	if (!rlines)
		return (-1);
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

int	ft_rlines_len(t_rlines rlines)
{
	int	i;

	if (!rlines)
		return (-1);
	i = -1;
	while (rlines[++i])
		;
	return (i);
}

int	ft_slines_rlen(t_slines slines)
{
	int	i;

	if (!slines)
		return (-1);
	i = -1;
	while (slines[++i])
		;
	return (i);
}

int	ft_file_len(const char *filename)
{
	t_rlines	lines;
	int			fd;
	int			len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = ft_readlines(fd);
	close(fd);
	len = ft_rlines_len(lines);
	ft_free_rlines(&lines);
	return (len);
}

int	ft_file_size(const char *filename)
{
	t_rlines	lines;
	int			fd;
	int			size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = ft_readlines(fd);
	close(fd);
	size = ft_rlines_size(lines);
	ft_free_rlines(&lines);
	return (size);
}
