/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:10:09 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/16 13:25:41 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}

int	ft_rewrite_file(const char *filename, char **lines)
{
	int	fd;
	int	i;

	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd < 0)
	{
		perror("GNLXIO:ft_rewrite_file.c:29:open()");
		return (-1);
	}
	i = -1;
	while (lines[++i])
		ft_putstr_fd(lines[i], fd);
	close(fd);
	return (i);
}
