/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:59:35 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/19 11:59:36 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

char	*ft_get_line(const char *filename, int lineno)
{
	char	**lines;
	char	*line;
	int		len;
	int		fd;

	if (lineno == 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Function open() failed");
		return (NULL);
	}
	lines = ft_readlines(fd);
	if (!lines)
		return (NULL);
	len = ft_rlines_len(lines);
	ft_fix_lineno(&lineno, len);
	line = gnlxio_ft_strdup(lines[lineno - 1]);
	ft_free_rlines(&lines);
	return (line);
}
