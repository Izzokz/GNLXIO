/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:19:07 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/20 17:19:08 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

t_rlines	ft_readfile(const char *filename)
{
	t_rlines	lines;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("GNLXIO:ft_readfile.c:20:open()");
		return (NULL);
	}
	lines = ft_readlines(fd);
	close(fd);
	return (lines);
}
