/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:25:24 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/16 13:25:25 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static char	**ft_delete_line(int lineno, char ***chain, int len)
{
	int		i;
	int		j;
	char	**new_chain;

	if (!(*chain))
		return (NULL);
	new_chain = gnlxio_ft_calloc(len, sizeof(char *));
	i = -1;
	j = -1;
	while ((*chain)[++i])
		if (i != lineno - 1)
			new_chain[++j] = gnlxio_ft_strdup((*chain)[i]);
	ft_free_rlines(chain);
	return (new_chain);
}

int	ft_deline(const char *filename, int lineno)
{
	char	**lines;
	int		i;
	int		len;

	lines = ft_readfile(filename);
	if (!lines)
		return (-1);
	i = -1;
	len = ft_rlines_len(lines);
	ft_fix_lineno(&lineno, len);
	lines = ft_delete_line(lineno, &lines, len);
	ft_rewrite_file(filename, lines);
	ft_free_rlines(&lines);
	return (1);
}
